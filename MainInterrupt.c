/*
 * File:   INTERRUPT.c
 * Author: Piotrek
 *
 * Created on 4 styczen 2016, 09:21
 */






//******************************************************************************
//* I N C L U D E   S E C T I O N  
//******************************************************************************
#include "p32mz2048efh064.h"
#include <string.h>
#include <stdio.h> //potrzebne do funkcji sprintf
#include "attribs.h"
#include "UART_user.h"
#include "MM7150user.h"
#include "MM7150globalvars.h"


//******************************************************************************
//* M A I N  I N T E R R U P T  H A N D L E R                                 
//******************************************************************************
int spf_sucess = 0;
int tx1_end = 0;
int tx2_end = 0;

char tx_buff[100];
void __ISR(_TIMER_2_VECTOR, IPL7SRS) Timer2Handler(void)
{
    
    IFS0bits.T2IF= 0;
    
   
   // IMUReadReqest= 0xF;
    MM7150attendance();  
    
    if(PeriodGlobal>0)
    {   
        //odczytaj wynik
          spf_sucess = sprintf(tx_buff,"\n\rInclinometer = X%hi Y%hi Z%hi\n\rCompass: %hi\n\rAccel: X%hi Y%hi Z%hi", InclinometerX, InclinometerY, InclinometerZ, Compass, AccelerometerX, AccelerometerY, AccelerometerZ);//,InclinometerZ);//\e[1;1H\e[2J - kasowanie tekstu
        if(spf_sucess <0)
            UART_send("Sprintf error!\n\r");
        else
            UART_send(tx_buff);
        PeriodGlobal= 0;
        
//       
}
    
}