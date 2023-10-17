/* 
 * File:   main.c
 * Author: PN, MD
 *
 * Created on 29 grudzien 2015, 8:23
 */
//******************************************************************************
//* I N C L U D E  S E C T I O N
//******************************************************************************
#include "p32mz2048efh100.h"
#include "MM7150globalvars.h"
#include "InitPIC.h"
#include "UART_user.h"
#include "MM7150config.h"
#include "Prandtl.h"
#include <stdio.h>
//******************************************************************************
//* C O N F I G  C L O C K  S E C T I O N
//******************************************************************************
// DEVCFG3
//#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
//#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
//#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = OFF           // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = OFF            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = OFF             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
//#pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)
//SYSCLK 32 MHz
// PBCLK3 16 MHz
// PBCLK2 (UART)16 MHz
#pragma config FPLLIDIV = DIV_1         // System PLL Input Divider (1x Divider)
#pragma config FPLLRNG = RANGE_8_16_MHZ // System PLL Input Range (8-16 MHz Input)
#pragma config FPLLICLK = PLL_POSC      // System PLL Input Clock Selection (POSC is input to the System PLL)
#pragma config FPLLMULT = MUL_64        // System PLL Multiplier (PLL Multiply by 64)
#pragma config FPLLODIV = DIV_16        // System PLL Output Clock Divider (16x Divider)
//#pragma config UPLLFSEL = FREQ_24MHZ

#pragma config FWDTEN = OFF
#pragma config FDMTEN = OFF
#pragma config POSCMOD = HS
#pragma config FNOSC = SPLL
//#pragma config FPBDIV = DIV_2
#pragma config FSOSCEN = OFF
#pragma config DEBUG = ON
#pragma config ICESEL = ICS_PGx1
#pragma config CP = OFF
//#pragma config BWP = OFF
#pragma config JTAGEN = OFF
//#pragma config PWP = OFF
//#pragma config UPLLEN = OFF
//#pragma config FVBUSONIO = OFF
#pragma config FCKSM = CSECME
#pragma config DBGPER = PG_ALL



// DEVCP0

// SEQ3
#pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)



//******************************************************************************
//* M A I N  F U N C T I O N 
//******************************************************************************
unsigned int main(void)
{       
    ConfigPerformance();
    IMUReadReqest= 0xF; //set 0xf to read
    ConfigTimer();
    AllPortsDigital();
    ODCBbits.ODCB3= 1;
    ADC_General_Config();
    config_Prandtl_1();
    config_Prandtl_2();
    ConfigINT();
    OnINT();
    GlobalINTon();
    ConfigPPS();
    ConfigOC();
    OnOC();
    ConfigIO();
    Wake_Config_Enable();
    ADC_Enable_Disable(1);
    OnTimer2();
    OnTimer3();
    UART();
   
    
    while(1)
    {
//      if(PORTBbits.RB3 == 1)
//      {
//          IntPin == 1;
//      }
          
    }
    return 0;
}