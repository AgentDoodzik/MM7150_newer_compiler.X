
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
    T2CONbits.ON = 0; 
    TMR2 = 0x0000;
    PR2 = 1500; //czestotliwosc sygnalu pwm - 333 Hz
    T2CONbits.T32 = 0;
    T2CONbits.TCKPS = 0b101; //preskaler timera 1:32
    T2CONbits.TCS = 0;
    T2CONbits.ON = on;

}


/* funkcja PWM_x_set - USTAWIENIE MODULOW PWM NA POCZATKU*/

void PWM_1_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia (SATURATION)
    if(duty_var > 1100 )
        duty_var = 1100;
    else 
        if(duty_var < 400)
            duty_var = 400;
    
    
    TRISDbits.TRISD1 = 0; // RPD1 jako wyjscie
    RPD1Rbits.RPD1R = 0b1100; //tryb OC1
    
    
    OC1CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC1CONbits.OCTSEL = 0; //wybor timera 2
    OC1CONbits.OCM = 0b110; // tryb PWM
    OC1RS = duty_var; 
    OC1CONbits.ON = on; //wlaczenie/wylaczenie pwm
    
}

void PWM_2_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia
    if(duty_var > 1100 )
        duty_var = 1100;
    else 
        if(duty_var < 400)
            duty_var = 400;
    
    TRISDbits.TRISD0 = 0; // RPD0 jako wyjscie
    RPD0Rbits.RPD0R = 0b1011; //tryb OC2
    
    
    OC2CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC2CONbits.OCTSEL = 0; //wybor timera 2
    OC2CONbits.OCM = 0b110; // tryb PWM
    OC2RS = duty_var; 
    OC2CONbits.ON = on; //wlaczenie/wylaczenie pwm
}

void PWM_3_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia
    if(duty_var > 1100 )
        duty_var = 1100;
    else 
        if(duty_var < 400)
            duty_var = 400;
    
    TRISDbits.TRISD10 = 0; // RPD0 jako wyjscie
    RPD10Rbits.RPD10R = 0b1011; //tryb OC3
    
    OC3CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC3CONbits.OCTSEL = 0; //wybor timera 2
    OC3CONbits.OCM = 0b110; // tryb PWM
    OC3RS = duty_var;  
    OC3CONbits.ON = on; //wlaczenie/wylaczenie pwm
    
}

void PWM_4_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia
    if(duty_var > 1100 )
        duty_var = 1100;
    else 
        if(duty_var < 400)
            duty_var = 400;
    
    TRISFbits.TRISF5 = 0; // RPD0 jako wyjscie
    RPF5Rbits.RPF5R = 0b1011; //tryb OC4
    
    OC4CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC4CONbits.OCTSEL = 0; //wybor timera 2
    OC4CONbits.OCM = 0b110; // tryb PWM
    OC4RS = duty_var; 
    OC4CONbits.ON = on; //wlaczenie/wylaczenie pwm

}

void PWM_5_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia
    if(duty_var > 1100 )
        duty_var = 1100;
    else 
        if(duty_var < 400)
            duty_var = 400;
    
    TRISDbits.TRISD9 = 0; // RPD0 jako wyjscie
    RPD9Rbits.RPD9R = 0b1011; //tryb OC5
    
    OC5CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC5CONbits.OCTSEL = 0; //wybor timera 2
    OC5CONbits.OCM = 0b110; // tryb PWM
    OC5RS = duty_var; 
    OC5CONbits.ON = on; //wlaczenie/wylaczenie pwm
}

void PWM_6_conf(uint16_t duty_var, uint8_t on)
{
    //ograniczenie wartosci wsp. wypelnienia
    if(duty_var > 1100 )
        duty_var = 1100;
    else 
        if(duty_var < 400)
            duty_var = 400;
    
    TRISFbits.TRISF4 = 0; // RPF4 jako wyjscie
    RPF4Rbits.RPF4R = 0b1100; //tryb OC6
    
    OC6CONbits.ON = 0; //na czas konfiguracjy wylaczamy PWM
    OC6CONbits.OCTSEL = 0; //wybor timera 2
    OC6CONbits.OCM = 0b110; // tryb PWM
    OC6RS = duty_var; 
    OC6CONbits.ON = on; //wlaczenie/wylaczenie pwm

}


// funkcje PWM_x_update - funkcje do sterowania serwam (zmiana wsp. wypelnienia "w locie")
void PWM_1_update(uint16_t new_duty_var)
{
    
    OC1RS = new_duty_var;
}

void PWM_2_update(uint16_t new_duty_var)
{
    OC2RS = new_duty_var;
}

void PWM_3_update(uint16_t new_duty_var)
{
    
    OC3RS = new_duty_var;
}

void PWM_4_update(uint16_t new_duty_var)
{
    
    OC4RS = new_duty_var;
}

void PWM_5_update(uint16_t new_duty_var)
{
    
    OC5RS = new_duty_var;
}

void PWM_6_update(uint16_t new_duty_var)
{
    
    OC6RS = new_duty_var;
}





