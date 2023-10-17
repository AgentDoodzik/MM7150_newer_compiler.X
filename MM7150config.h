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
#include "p32mz2048efh100.h"
//******************************************************************************
//* D E F I N E  S E C T I O N 
//******************************************************************************
//RESET PIN - prawdopodobnie RA4 (PORTA) ~MD
#define ResPinAsOut TRISAbits.TRISA4 = 0; 
#define ResPinHigh LATAbits.LATA4 = 1;
#define ResPinLow LATAbits.LATA4= 0;
//INTERRUPT PIN - port  RD0 jako External Interrupt 0 (INT 0)
#define IntPinAsIn TRISDbits.TRISD0 = 1;//TRISGbits.TRISG9 = 1
#define IntPin PORTDbits.RD0;
//I2C REGISTERS
#define StartI2C I2C5CONbits.SEN
#define StopI2C I2C5CONbits.PEN
#define SendBufI2C I2C5TRN
#define ReceiveBufI2C I2C5RCV
#define TransFlagI2C I2C5STATbits.TBF
#define ACKFlagI2C I2C5STATbits.ACKSTAT
#define RepeatStartI2C I2C5CONbits.RSEN
#define SetReceiveI2C I2C5CONbits.RCEN
#define SendConfirmI2C I2C5CONbits.ACKEN
#define ACKtoSendI2C I2C5CONbits.ACKDT= 0
#define NACKtoSendI2C I2C5CONbits.ACKDT= 1
#endif /* _MM7150CONFIG_H */
/* ****************************************************************************/