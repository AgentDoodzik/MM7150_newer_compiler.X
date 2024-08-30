
#include "servo.h"

//#define PWM_PRx 1500

/*
 Mamy ta sama czestotliwosc sterowania serwomechanizmami
 Tak wiec OCACLK moze miec wartosc zero-
 wtedy WSZYSTKIE output compare korzystaja
 z Timer2/Timer3 (Timerx/Timery) 
 
 800 us -> OC1RS = 400
 2200 us -> OC1RS = 1100 
 */

// sygnal sinusoidalny
// czestotliwosc 0.1 Hz - caly ruch w jedna i druga strone trwa 10 s

//

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//DO ZROBIENIA
//ENKAPSULACJA (m.in wyrzucic funkcje pitch_control do innego pliku) - mozliwe, ze zrobione 
//zdeklarowac zmienne w plikach zrodlowych jako globalne, tj poza funkcjami
//Poprosic huberta o kod obslugujacy UART
//polaczyc sie Uartami pomiedzy dwoma plytkami z uzyciem kabelkow
//zdobyc kod do sprzezenia zwrotnego z IMU
//poprawic yaw (ma byc zakres od + czegos tam do 0 NA OBU STRONACH)
//przerzucic offset serwomechanizmow 1-6 przed blok dead zone
//offset za flaps control? 

/* wlacz/ wylacz timer */
void freq_set(uint8_t on)
{
    CFGCONbits.OCACLK = 0;
    T3CON = 0x0; //clear the control register for config
    TMR3 = 0x0000;
    PR3 = 48047; //Servo base frequency 333 Hz
    T3CONbits.TCKPS = 0b000; //timer prescaler 1:1
    T3CONbits.TCS = 0; //gated time accumulation disabled
    T3CONbits.ON = on; // enable/disable the timer

}

void PWM_sine_wave_conf(uint8_t on){ //Sine wave generation
    
    /*
     * This function changes the duty cycle according to a sine wave value
     * 
     */
    
    //timer control registers disabled for config
    T4CON = 0x0;
    T5CON = 0x0;
    
    T4CONbits.T32 = 1; //32 bit timer mode (Timer 4 + Timer 5 work together)
    
    //timer start value
    TMR4 = 0x0000;
    TMR5 = 0x0;
    
    PR4 = 0x3D08;//624999;// sine frequency 0.1Hz
    //0x7A11 2Hz  0xF423 1 Hz  0x1E847 0.5 Hz 0x3D08F - 0.25 0x5B5EA - 0.167 Hz,  0x7A11F - 0.125 Hz,  124999; //2s 0.5Hz
    //0x3D08 - 4 Hz
    T4CONbits.TCKPS = 0b111; //1:256 prescaler to prevent overflow
    
    T4CONbits.ON = on;
    
   //return (uint16_t)round(350 * sin(2 * M_PI * (1./624999) * (TMR4 + TMR5)) + 750);  
  
}

float PWM_sine_wave_read_1(void) //read the sine wave value - servos on glider's left(right?) side
{
    //return (uint16_t)round(6496 * sin(2 * M_PI * (1./(PR4+PR5)) * (TMR4+TMR5+(124999/2))) + 28545);   //start 24024
    return sin(2.0 * M_PI * (1./(PR4+PR5)) * (TMR4+TMR5));
    //28000 looks good
}

uint16_t PWM_sine_wave_read_2(void)//read the sine wave value - servos on glider's right(left?) side
{
    //return (uint16_t)round(5045 * sin(2 * M_PI * (1./(PR4+PR5)) * (TMR4+TMR5)) + 18498);  
}


/* funkcja PWM_x_conf - USTAWIENIE MODULOW PWM NA POCZATKU*/

void PWM_1_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia (SATURATION)
//    if(duty_var > 1100 ) //NEEDS ADJUSTMENT
//        duty_var = 1100;
//    else 
//        if(duty_var < 400)
//            duty_var = 400;
    
    
    TRISBbits.TRISB9 = 0; // RPD1 jako wyjscie
    RPB9Rbits.RPB9R = 0b1011; //tryb OC3
    
    
    OC3CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC3CONbits.OCTSEL = 1; //wybor timera 3
    OC3CONbits.OCM = 0b110; // tryb PWM
    OC3RS = duty_var; 
    OC3CONbits.ON = on; //wlaczenie/wylaczenie pwm
    
}

void PWM_2_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia
//    if(duty_var > 1100 ) NEEDS ADJUSTMENT
//        duty_var = 1100;
//    else 
//        if(duty_var < 400)
//            duty_var = 400;
    
    TRISBbits.TRISB10 = 0; // RPB10 jako wyjscie
    RPB10Rbits.RPB10R = 0b1100; //tryb OC6
    
    
    OC6CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC6CONbits.OCTSEL = 1; //wybor timera 3
    OC6CONbits.OCM = 0b110; // tryb PWM
    OC6RS = duty_var; 
    OC6CONbits.ON = on; //wlaczenie/wylaczenie pwm
}

void PWM_3_conf(uint16_t duty_var, uint8_t on)
{

}

void PWM_4_conf(uint16_t duty_var, uint8_t on)
{

}

void PWM_5_conf(uint16_t duty_var, uint8_t on)
{
   
}

void PWM_6_conf(uint16_t duty_var, uint8_t on)
{

}


// funkcje PWM_x_update - funkcje do sterowania serwam (zmiana wsp. wypelnienia "w locie")
void PWM_1_update(uint16_t new_duty_var)
{
        //ograniczenie wartosci wsp. wypelnienia
//    if(duty_var > 1100 ) NEEDS ADJUSTMENT
//        duty_var = 1100;
//    else 
//        if(duty_var < 400)
//            duty_var = 400;
    OC3RS = new_duty_var; 
}

void PWM_2_update(uint16_t new_duty_var)
{
            //ograniczenie wartosci wsp. wypelnienia
//    if(duty_var > 1100 ) NEEDS ADJUSTMENT
//        duty_var = 1100;
//    else 
//        if(duty_var < 400)
//            duty_var = 400;
    OC6RS = new_duty_var; 
}

void PWM_3_update(uint16_t new_duty_var)
{
    
}

void PWM_4_update(uint16_t new_duty_var)
{
    
}

void PWM_5_update(uint16_t new_duty_var)
{
    
}

void PWM_6_update(uint16_t new_duty_var)
{
  
}





