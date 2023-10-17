#include "p32mz2048efh100.h"
#include "xc.h"

void ADC_Enable_Disable(char set_adc)
{
    ADCCON1bits.ON = (uint32_t)set_adc;
}

void ADC_General_Config(void)
{
    ADCCON1 = 0;
    ADCCON2 = 0;
    
    
    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 5; // Wakeup exponent = 32 * TADx
    
    ADCCON1bits.FRACT = 0;
    ADCIMCON1bits.SIGN0 = 1;
     //set the voltage reference 
    ADCCON3bits.VREFSEL = 0b000; //AVDD for VREFH, AVSS for VREFL
    
    //setting the clock
    ADCCON3bits.ADCSEL = 0b00; //PBCLK3 as the clock source (normally 16 MHz)
    ADCCON3bits.CONCLKDIV = 0; //Tck = Tq = 16 MHz   
    
    //no interrupts will be used
    ADCGIRQEN1 = 0;
    ADCGIRQEN2 = 0;
    

}

void config_Prandtl_1(void)
{
    ANSELAbits.ANSA0 = 1; //AN0 as analog - required for ADC
    TRISAbits.TRISA0 = 1; //AN0 as data input
    ADC0CFG = DEVADC0; //calibration value
    ADCTRGMODEbits.SH0ALT = 0b00; // AN0 as analog input
    ADCTRG1bits.TRGSRC0 = 0b01000; //OC1 is the trigger for ADC conversion for AN0 (?)
    
    //sampling time settings
    ADC0TIMEbits.ADCDIV = 1; // ADC0 clock frequency is half of control clock = TAD0
    ADC0TIMEbits.SAMC = 5; // ADC0 sampling time = 5 * TAD0
    ADC0TIMEbits.SELRES = 3; // ADC0 resolution is 12 bits
    
    //this analog ipnut will be scanned
    
}

void config_Prandtl_2(void)
{
    ANSELAbits.ANSA1 = 1; //AN1 as analog - required for ADC
    TRISAbits.TRISA1 = 1; //AN1 as data input
    ADC1CFG = DEVADC1; //calibration value
    ADCTRGMODEbits.SH1ALT = 0b00; // AN0 as analog input
    ADCTRG1bits.TRGSRC1 = 0b01000; //OC1 is the trigger for ADC conversion for AN0 (?)
    //sampling time settings
    ADC1TIMEbits.ADCDIV = 1; // ADC0 clock frequency is half of control clock = TAD0
    ADC1TIMEbits.SAMC = 5; // ADC0 sampling time = 5 * TAD0
    ADC1TIMEbits.SELRES = 3; // ADC0 resolution is 12 bits
    
    //this analog input will be scanned
    //ADCCSS1bits.CSS1 = 1;
}

//void config_Prandtl_3(void)
//{
//    //ANSELAbits.ANSA2 = 1; //CANT find ANSA2
//    TRISAbits.TRISA2 = 1; //AN2 as data input
//    ADC2CFG = DEVADC2; //calibration value
//    ADCTRGMODEbits.SH2ALT = 0b00; // AN2 as analog input
//    ADCTRG1bits.TRGSRC2 = 0b01000; //OC1 is the trigger for ADC conversion for AN0 (?)
//}

//void config_Prandtl_4(void)
//{
//    //ANSELAbits.ANSA3 = 1; //AN3 as analog - required for ADC
//    TRISAbits.TRISA3 = 1; //AN3 as data input
//    ADC3CFG = DEVADC3; //calibration value
//    ADCTRGMODEbits.SH3ALT = 0b00; // AN0 as analog input
//    ADCTRG1bits.TRGSRC3 = 0b01000; //OC1 is the trigger for ADC conversion for AN0 (?)
//}

//void config_Prandtl_5(void)
//{
//    //ANSELAbits.ANSA4 = 1; //AN4 as analog - required for ADC
//    TRISAbits.TRISA4 = 1; //AN0 as data input
//    ADC4CFG = DEVADC4; //calibration value
//    ADCTRGMODEbits.SH4ALT = 0b00; // AN4 as analog input
//    ADCTRG2bits.TRGSRC4 = 0b01000; //OC1 is the trigger for ADC conversion for AN4 (?)
//}

//void config_Prandtl_6(void)
//{
//    
//    ANSELAbits.ANSA5 = 1; //AN0 as analog - required for ADC
//    TRISAbits.TRISA5 = 1; //AN0 as data input
//    ADC5CFG = DEVADC5; //calibration value
//    ADCTRGMODEbits.SH = 0b00; // AN0 as analog input
//    ADCTRG1bits.TRGSRC0 = 0b01000; //OC1 is the trigger for ADC conversion for AN0 (?)
//}
 