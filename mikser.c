

#include "servo.h"

//regulator Yaw poza blokiem YAW control

#define MAX_YAW_U  1100 //maksymalna wartosc sterowania na osi YAW
#define MIN_YAW_U  400 //min wartosc sterowania na osi YAW

//maks i min wartosc sterowania srodka ciezkosci
#define MAX_WEIGTH_U  1100
#define MIN_WEIGTH_U  400

//transmitancja obiektu - wozka z obciazeniem
#define WEIGTH_U_FILTER  1.0
#define WEIGTH_PI 1.0

//transmitancja regulatora PI osi YAW
#define YAW_PI  5.0

#define YAW_GAIN 1.0 //wzmocnienie 



//mixer
    //maksymalne wartosci wspolczynnika wypelnienia sygnalu PWM sterujacego
    //serwami lotek, wyrazone w zmiennej PRx (liczba cykli)
#define MAX_DUTY_CYCLE  1100
#define MIN_DUTY_CYCLE  400








/* OFFSETY serwomechanizmow sterujacych lotkami (zwiazane z polozeniem)*/
#define SERVO1_OFFSET  0
#define SERVO2_OFFSET  0
#define SERVO3_OFFSET  0
#define SERVO4_OFFSET  0
#define SERVO5_OFFSET  0
#define SERVO6_OFFSET  0
#define SERVO_WEIGTH_OFFSET 0

// wzmocnienia regulatorow dla servo nr 1
#define GAIN1_1   1.0
#define GAIN1_2  -1.0
#define GAIN1_3  -3.0

// wzmocnienia regulatorow dla servo nr 2
#define GAIN2_1  2.0
#define GAIN2_2  2.0
#define GAIN2_3  -2.0

// wzmocnienia regulatorow dla servo nr 3
#define GAIN3_1  3.0
#define GAIN3_2  -1.0
#define GAIN3_3  -1.0

// wzmocnienia regulatorow dla servo nr 4
#define GAIN4_1  3.0
#define GAIN4_2  -1.0
#define GAIN4_3  1.0

// wzmocnienia regulatorow dla servo nr 5
#define GAIN5_1  2.0
#define GAIN5_2  2.0
#define GAIN5_3  2.0

// wzmocnienia regulatorow dla servo nr 6
#define GAIN6_1  1.0
#define GAIN6_2  -1.0
#define GAIN6_3  3.0

//u_servox - sterowanie serwomechanizmami, x =  1...6
uint16_t u_servo1;
uint16_t u_servo2;
uint16_t u_servo3;
uint16_t u_servo4;
uint16_t u_servo5;
uint16_t u_servo6;

uint16_t servo_avg;// srednia ze wszystkich sygnalow ktora zostanie wykorzystana do obliczenia


uint16_t u_weigth; //sterowanie srodkiem ciezkosci
int16_t yaw1, yaw2; //dodatkowe zmienne do obliczenia sterowania yaw 

void Mixer(float pitch, float roll, float yaw, float flaps, float meas_air_spd)
{


    //obliczenie sterowan dla osi YAW
    yaw1 = yaw * YAW_GAIN;
    yaw2 = -yaw * YAW_GAIN;
    
    //ograniczenie zakresu wartosci osi YAW
    if(yaw1 >= MAX_YAW_U)
        yaw1 = MAX_YAW_U;
    else if(yaw1 < 0)
        yaw1 = 0;
    
    if(yaw2 >= MAX_YAW_U)
        yaw2 = MAX_YAW_U;
    else if(yaw2 < 0)
        yaw2 = 0;
    

    
    // u_servox - sterowanie wyprowadzone na serwomechanizm nr x
    u_servo1 = round(GAIN1_1 * pitch + GAIN1_2 * yaw1 + GAIN1_3* roll) + SERVO1_OFFSET; 
    u_servo2 = round(GAIN2_1 * pitch + GAIN2_2 * yaw1 + GAIN2_3* roll) + SERVO2_OFFSET;
    u_servo3 = round(GAIN3_1 * pitch + GAIN3_2 * yaw1 + GAIN3_3* roll) + SERVO3_OFFSET; 
    u_servo4 = round(GAIN4_1 * pitch + GAIN4_2 * yaw2 + GAIN4_3* roll) + SERVO4_OFFSET; 
    u_servo5 = round(GAIN5_1 * pitch + GAIN5_2 * yaw2 + GAIN5_3* roll) + SERVO5_OFFSET; 
    u_servo6 = round(GAIN6_1 * pitch + GAIN6_2 * yaw2 + GAIN6_3* roll) + SERVO6_OFFSET; 
    
    //ograniczenie MIN i MAX wspolczynnika wypelnienia
    if(u_servo1 > MAX_DUTY_CYCLE)
        u_servo1 = MAX_DUTY_CYCLE;
    else if(u_servo1 <= MIN_DUTY_CYCLE)
        u_servo1 = MIN_DUTY_CYCLE;
    
    if(u_servo2 > MAX_DUTY_CYCLE)
        u_servo2 = MAX_DUTY_CYCLE;
    else if(u_servo2 <= MIN_DUTY_CYCLE)
        u_servo2 = MIN_DUTY_CYCLE;
    
    if(u_servo3 > MAX_DUTY_CYCLE)
        u_servo3 = MAX_DUTY_CYCLE;
    else if(u_servo3 <= MIN_DUTY_CYCLE)
        u_servo3 = MIN_DUTY_CYCLE;
    
    
    if(u_servo4 > MAX_DUTY_CYCLE)
        u_servo4 = MAX_DUTY_CYCLE;
    else if(u_servo4 <= MIN_DUTY_CYCLE)
        u_servo4 = MIN_DUTY_CYCLE;
    
    if(u_servo5 > MAX_DUTY_CYCLE)
        u_servo5 = MAX_DUTY_CYCLE;
    else if(u_servo5 <= MIN_DUTY_CYCLE)
        u_servo5 = MIN_DUTY_CYCLE;
    
    if(u_servo6 > MAX_DUTY_CYCLE)
        u_servo6 = MAX_DUTY_CYCLE;
    else if(u_servo6 <= MIN_DUTY_CYCLE)
        u_servo6 = MIN_DUTY_CYCLE;
    
    servo_avg = round((u_servo1 + u_servo2 + u_servo3 + u_servo4 + u_servo5 + u_servo6)/6.0);
 
    
    
     //obliczenie sterowania dla srodka ciezkosci
    u_weigth =  round((flaps - servo_avg) * WEIGTH_PI * WEIGTH_U_FILTER) + SERVO_WEIGTH_OFFSET;
    
    //ograniczenie wartosci sterowania
    
    if(u_weigth > MAX_WEIGTH_U)
        u_weigth = MAX_WEIGTH_U;
    else if(u_weigth < MIN_WEIGTH_U)
        u_weigth = MIN_WEIGTH_U;
    
    PWM_1_update(u_servo1);
    PWM_2_update(u_servo2);
    PWM_3_update(u_servo3);
    PWM_4_update(u_servo4);
    PWM_5_update(u_servo5);
    PWM_6_update(u_servo6);
        
}


