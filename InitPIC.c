
#include "p32mz2048efh064.h"

void ConfigTimer(void)
{    
    T2CONbits.TCKPS= 0b000;
    PR2= 799; //20 kHz
    TMR2= 0;
    
    T6CONbits.TCKPS=0b000;
    //PR6 = 0xF423; //1Hz frequency - testing only
    PR6 = 0x3E7F; //1 kHz - UART transfer initiation

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
    T3CONbits.ON= 1;
}

void OnTimer6(void)
{
    T6CONbits.ON = 1;
    IEC0bits.T6IE = 1;
}
void ConfigINT(void)
{
    INT4Rbits.INT4R = 0b1000;
    INTCONbits.MVEC= 1; //MULTIPLE VECTORS
    IPC33bits.DMA0IP = 6;
    
    //setting interrupt priorities
    //interrupts have the same priorities but different subprio's
    //If they are triggerd simultaneously, the one with higher suprio will
    //be handled first
    IPC2bits.T2IP= 7;
    IPC2bits.T2IS= 3;
    IPC7bits.T6IP = 7;
    IPC7bits.T6IS = 2;
    
}
void OnINT(void)
{
    IEC4bits.DMA0IE = 1;
    IFS0bits.T2IF= 0;
    IFS0bits.T6IF = 0;
    IEC0bits.T2IE= 1;
    IEC0bits.T6IE = 1;
}
void GlobalINTon(void)
{
    asm volatile("ei");
}
void ConfigPPS(void)
{
//    RPB14Rbits.RPB14R= 0b1100; //OC1
//    TRISBbits.TRISB8 = 0;
//    PORTBbits.RB8 = 0;
    
}
void ConfigOC(void)
{
//    OC1CONbits.OCM= 6;//tryb PWM
//    OC1CONbits.OCTSEL= 1;// timer3
    //OC1RS= 2500;
}
void OnOC(void)
{
//    OC1CONbits.ON= 1;
}
void ConfigIO(void)
{
    //TRISBbits.TRISB1= 1; //TO_1 ????
    //TRISDbits.TRISD7= 1; //TO_2 ????
}

void Wake_Config_Enable()
{
    TRISBbits.TRISB5 = 0;
    LATBbits.LATB5 = 1;
    //INT4Rbits.INT4R = 0b1000;
}