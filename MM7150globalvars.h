/* 
 * File:   MM7150globalvars.h
 * Author: macie
 *
 * Created on 16 grudnia 2022, 13:51
 */

#ifndef MM7150GLOBALVARS_H
#define	MM7150GLOBALVARS_H
#include <stdint.h>

extern unsigned char  ReadValue;
extern unsigned char IMUReadReqest; // SET IMUReadReqest= 0xF FOR DATA REQUEST
extern unsigned int PeriodGlobal;   // IF PeriodGlobal>0 DATA ARE READY; CONTAINS TIME  
                             // BETWEEN REVEIVE DATA; CLEAR AFTER READ
extern signed short AccelerometerX; // ACCELEROMETER X AXIS
extern signed short AccelerometerY; // ACCELEROMETER Y AXIS
extern signed short AccelerometerZ; // ACCELEROMETER Z AXIS
//alternative inclinometer type
//extern int16_t InclinometerX;
extern signed short InclinometerX; // INCLINOMETER X AXIS
extern signed short InclinometerY; // INCLINOMETER Y AXIS
extern signed short InclinometerZ; // INCLINOMETER Z AXIS
extern unsigned short Compass; // COMPASS 0-360 DEGREES
//alt compass type
//extern int16_t Compass; 

extern uint16_t int_cnt; //uart 1kHz counter variable
//extern uint8_t tx_buff[6];
extern uint8_t volatile __attribute__ ((coherent, aligned(16))) tx_buff[6]; //uart buffer
extern char __attribute__ ((coherent, aligned(16))) char_tx_buff[20];
extern volatile float sine_val;

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MM7150GLOBALVARS_H */

