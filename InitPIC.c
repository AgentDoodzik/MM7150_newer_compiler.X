
#include "p32mz2048efh100.h"

void ConfigTimer(void)
{
    T2CON = 0x0;
    T2CONbits.TCKPS= 0b001;
    PR2= 399; //40 kHz
    TMR2= 0;
    
    T3CON = 0x0;
    T3CONbits.TCKPS= 0b110;
    PR3= 4999; //50Hz
    TMR3= 0;
}
 void AllPortsDigital(void)
{
    ANSELB= 0x00;
    //ANSELC= 0x00;
    //ANSELD= 0x00;
    ANSELE= 0x00;
   //ANSELF= 0x00;
    ANSELG= 0x00;
    //ANSELF= 0x00; 
}
void ConfigPerformance(void)
{
    /*
    CHECONbits.DCSZ= 3;
    CHECONbits.PREFEN= 3;
    CHECONbits.PFMWS= 3;
    */
    //PRECONbits.PREFEN = 3;
    //PRECONbits.PFMWS = 3;
}   
void OnTimer2(void)
{
    T2CONbits.ON= 1;
    IEC0bits.T2IE = 1;
}
void OnTimer3(void)
{
    //T3CONbits.ON= 1;
}
void ConfigINT(void)
{
    INT4Rbits.INT4R = 0b1000;
    INTCONbits.MVEC= 1; //MULTIPLE VECTORS
    IPC2bits.T2IP= 7;
    IPC2bits.T2IS= 3;
}
void OnINT(void)
{
    IFS0bits.T2IF= 0;
    IEC0bits.T2IE= 1;
}
void GlobalINTon(void)
{
    asm volatile("ei");
}
void ConfigPPS(void)
{
    RPB14Rbits.RPB14R= 0b1100; //OC1
    TRISBbits.TRISB8 = 0;
    PORTBbits.RB8 = 0;
    
}
void ConfigOC(void)
{
    OC1CONbits.OCM= 6;//tryb PWM
    OC1CONbits.OCTSEL= 1;// timer3
    OC1RS= 2500;
}
void OnOC(void)
{
    OC1CONbits.ON= 1;
}
void ConfigIO(void)
{
    //TRISBbits.TRISB1= 1; //TO_1 ????
    //TRISDbits.TRISD7= 1; //TO_2 ????
}

void Wake_Config_Enable()
{
    TRISDbits.TRISD11 = 0;
    LATDbits.LATD11 = 1;
    //INT4Rbits.INT4R = 0b1000;
}

void Timer4_Config(void)
{
    /* 
     * This timer is going to trigger DMA transfer to UART 5 TX register
     * The transferred data will be the information from IMU1 and ADCs reading
     * inputs from Prandtl pipes 
     */
    T4CON = 0x0;
    T4CONbits.TCKPS= 0b111; //1:256 prescaler
    PR4= 31249; //2 Hz
    TMR4= 0;
    
    IEC0bits.T5IE = 0; // disable the interrupt for config
    IFS0bits.IC5IF = 0; //clear the flag
    IPC4bits.T4IP = 4; //priority 3
    IPC4bits.T4IS = 2;// subpriority 2
}

void OnTimer4(void)
{
    IEC0bits.T5IE = 1;  //enable the interrupt;
    T4CONbits.ON = 1;
    
}