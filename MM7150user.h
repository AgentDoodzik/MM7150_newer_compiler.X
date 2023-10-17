/*
 *  15.07.2016
 *  Author: PN, MD
 *  FileInfo: 
 */
#ifndef _MM7150USER_H    /* Guard against multiple inclusion */
#define _MM7150USER_H

//******************************************************************************
//* G L O B A L  V A R I A B L E S 
//******************************************************************************
/*
extern unsigned char  ReadValue;
extern unsigned char IMUReadReqest; // SET IMUReadReqest= 0xF FOR DATA REQUEST
extern unsigned int PeriodGlobal;   // IF PeriodGlobal>0 DATA ARE READY; CONTAINS TIME  
                             // BETWEEN REVEIVE DATA; CLEAR AFTER READ
extern signed short AccelerometerX; // ACCELEROMETER X AXIS
extern signed short AccelerometerY; // ACCELEROMETER Y AXIS
extern signed short AccelerometerZ; // ACCELEROMETER Z AXIS
extern signed short InclinometerX; // INCLINOMETER X AXIS
extern signed short InclinometerY; // INCLINOMETER Y AXIS
extern signed short InclinometerZ; // INCLINOMETER Z AXIS
extern unsigned short Compass; // COMPASS 0-360 DEGREES 
 */
 
//******************************************************************************
//* F U N C T I O N  P R O T O T Y P E
//******************************************************************************
void MM7150attendance(void);
#endif /* _MM7150USER_H */
/******************************************************************************/