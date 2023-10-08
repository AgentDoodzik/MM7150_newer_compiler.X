/*
 *  09.08.2016
 *  Author: PN
 *  Modified by: MD
 *  FileInfo: 
 */
#ifndef _MM7150CONFIG_H    /* Guard against multiple inclusion */
#define _MM7150CONFIG_H
//******************************************************************************
//* I N C L U D E  S E C T I O N 
//******************************************************************************
#include "p32mz2048efh064.h"
//******************************************************************************
//* D E F I N E  S E C T I O N 
//******************************************************************************
//RESET PIN - prawdopodobnie RPB2 ~MD
#define ResPinAsOut TRISBbits.TRISB2= 0 
#define ResPinHigh LATBbits.LATB2= 1
#define ResPinLow LATBbits.LATB2= 0
//INTERRUPT PIN - port  RG9 jako External Interrupt 1 (INT 1)
#define IntPinAsIn TRISBbits.TRISB3 = 1;//TRISGbits.TRISG9 = 1
#define IntPin PORTBbits.RB3
//I2C REGISTERS
#define StartI2C I2C4CONbits.SEN
#define StopI2C I2C4CONbits.PEN
#define SendBufI2C I2C4TRN
#define ReceiveBufI2C I2C4RCV
#define TransFlagI2C I2C4STATbits.TBF
#define ACKFlagI2C I2C4STATbits.ACKSTAT
#define RepeatStartI2C I2C4CONbits.RSEN
#define SetReceiveI2C I2C4CONbits.RCEN
#define SendConfirmI2C I2C4CONbits.ACKEN
#define ACKtoSendI2C I2C4CONbits.ACKDT= 0
#define NACKtoSendI2C I2C4CONbits.ACKDT= 1
#endif /* _MM7150CONFIG_H */
/* ****************************************************************************/