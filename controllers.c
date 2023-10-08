/////blok pitch control
 //MAX_UPID1...,MIN_UPID1 -  dane do bloku dead zone, ograniczajacego sterowanie na pierwszym regulatorem PID
#include "servo.h"
#define MAX_UPID1 100.0
#define MIN_UPID1 -100.0

// MAX_UPID2, MIN_UPID2 - blok za drugim regulatorem PID
#define MAX_UPID2 100.0
#define MIN_UPID2 -100.0

#define PITCH_TRANSFER_FCN 1.0 //PLACEHOLDER transmitancja obiektu ( za blokiem Reference Speed)
#define PITCH_PID1 1.0 //reprezentacja nastaw pierwszego reg. PID
#define PITCH_PID2 1.0// jw. drugiego regulatora PID
#define REF_SPEED 500.0 //Reference speed
/////////////////



/////blok flaps control
#define K_FLAPS 1.0; //regulator proporcjonalny w Flaps Control
#define FLAPS_TRANSFER_FCN 1.0 // transmitancja obiektu
#define MIN_FLAPS_SPD 20.0
#define MAX_FLAPS_SPD 100.0 // maksymalna predkosc 
#define MAX_FLAPS_U 15.0 // maksymalne sterowanie (wyjscie z regulatora)
////////////////////////

//blok roll control - stale
/////////////


//blok yaw control - stale
/////////////

///
#include <stdint.h>





//VARS
//PITCH CONTROL
float upid1;
float pitch;
float returned_pitch;


//FLAPS CONTROL
float speed;
float flaps;

//ROLL CONTROL

//YAW CONTROL

//SINE WAVE
uint16_t d;

////////////////////////////
float Pitch_control(float meas_air_spd, float meas_IMU_pitch)
{
    //na podstawie pliku schemat2.PNG (regulator do Pitch Control)
    //obliczenie sterowania regulatora PID 1, ograniczenie wartosci (dead zone)
   upid1 = ((REF_SPEED * PITCH_TRANSFER_FCN) - meas_air_spd) * PITCH_PID1;
    if(upid1 > MAX_UPID1 )
        upid1 = MAX_UPID1;
    else if(upid1 <= MIN_UPID1)
        upid1 = MIN_UPID1;
    
    //obliczenie wyjscia z ukladu, ograniczenie wartosci
    pitch = (upid1 - meas_IMU_pitch) * PITCH_PID2;
    returned_pitch = pitch; // wartosc Returned Pitch ze schematu
    if(upid1 > MAX_UPID2 )
        pitch = MAX_UPID2;
    else if(upid1 <= MIN_UPID2)
        pitch = MIN_UPID2;
    
    return pitch;
    
    
      
}

float Flaps_control(float meas_air_spd)
{
    
    
    speed = MIN_FLAPS_SPD - (meas_air_spd) * FLAPS_TRANSFER_FCN; //obliczenie predkosci strug (?)
    //ograniczenie maksymalnej wartosci predkosci
    if(speed > MAX_FLAPS_SPD)
        speed = MAX_FLAPS_SPD;
    else if(speed <= 0)
        speed = 0;
    
    flaps = speed * K_FLAPS; //obliczenie sterowania
    
    //ograniczenie max/min wartosci sterowania
    if(flaps > MAX_FLAPS_U)
        flaps = MAX_FLAPS_U;
    else if(flaps <= 0)
        flaps = 0;
    
    return flaps;
    
}

float Yaw_control(float yaw_out)
{
        
}

float Roll_control()
{
    
}


uint16_t PWM_sine_wave(uint8_t on){ //generowanie sterowania sinus
    
    
    T4CONbits.ON = 0;
    T5CONbits.ON = 0;
    T4CONbits.T32 = 1; //tryb 32-bitowy timera
    TMR4 = 0x0000;
    TMR5 = 0x0;
    PR4 = 624999;//624999;// czestotliwosc sygnalu sinus - 0.1 Hz
    T4CONbits.TCKPS = 0b111; //preskaler 1:256
    T4CONbits.ON = on;
    
   d = (uint16_t)round(350 * sin(2 * M_PI * (1./624999) * (TMR4 + TMR5)) + 750);  
   return d;
}