/* 
 * File:   main.c
 * Author: PN
 *
 * Created on 29 grudzien 2015, 8:23
 */
//******************************************************************************
//* I N C L U D E  S E C T I O N
//******************************************************************************
#include "p32mz2048efh064.h"
#include "MM7150globalvars.h"
#include "InitPIC.h"
#include "UART_user.h"
#include "MM7150config.h"
#include "servo.h"
#include "DMA.h"
#include <stdio.h>

// PIC32MZ2048EFH064 Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = OFF            // Permission Group Lock One Way Configuration (Allow multiple reconfigurations)
#pragma config PMDL1WAY = OFF           // Peripheral Module Disable Configuration (Allow multiple reconfigurations)
#pragma config IOL1WAY = OFF            // Peripheral Pin Select Configuration (Allow multiple reconfigurations)
#pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_1         // System PLL Input Divider (1x Divider)
#pragma config FPLLRNG = RANGE_8_16_MHZ // System PLL Input Range (8-16 MHz Input)
#pragma config FPLLICLK = PLL_POSC      // System PLL Input Clock Selection (POSC is input to the System PLL)
#pragma config FPLLMULT = MUL_64        // System PLL Multiplier (PLL Multiply by 64)
#pragma config FPLLODIV = DIV_16        // System PLL Output Clock Divider (16x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = SPLL             // Oscillator Selection Bits (System PLL)
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = HS             // Primary Oscillator Configuration (HS osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON              // Deadman Timer Enable (Deadman Timer is enabled)

// DEVCFG0
#pragma config DEBUG = ON               // Background Debugger Enable (Debugger is enabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_2X       // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ3
#pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

/* ###### PRIVATE VARIABLES #######  */
//Czestotliwosc zegara sysclk - 32 MHz
//PBCLK2 i PBCLK3 - 16 MHz (SYSCLK/2)
/*  ############ */
uint8_t __attribute__ ((coherent, aligned(16))) tx_buff[10];
uint16_t int_cnt = 0;
volatile float sine_val = 0.0;

unsigned int main(void)
//******************************************************************************
//* M A I N  F U N C T I O N 
//******************************************************************************

{       
    
    ConfigPerformance();
    IMUReadReqest= 0xF; //set 0xf to read
    ConfigTimer();
    AllPortsDigital();
    ODCBbits.ODCB3= 1;
//    CNPUBbits.CNPUB3= 1;
    ConfigINT();
    freq_set(1);
    PWM_1_conf(24024, 1);
    PWM_2_conf(21020, 1);
    PWM_sine_wave_conf(1);
    OnINT();
    GlobalINTon();
    ConfigPPS();
    ConfigOC();
    OnOC();
    ConfigIO();
    Wake_Config_Enable();
    config_DMA();
    OnTimer3();
    OnTimer2();
    UART();
    DMA_enable();
    
    
    while(1)
    {
        //sine_val =PWM_sine_wave_read_1();
//        PWM_1_update(sine_val*5045 + 18498); //5045 18498
//        PWM_2_update(-sine_val*6496+ 28545); //6496 28545
          
    }
    return 0;
}