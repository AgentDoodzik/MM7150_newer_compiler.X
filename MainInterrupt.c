/*
 * File:   INTERRUPT.c
 * Author: Piotrek
 *
 * Created on 4 styczen 2016, 09:21
 */






//******************************************************************************
//* I N C L U D E   S E C T I O N  
//******************************************************************************
#include "p32mz2048efh100.h"
#include <string.h>
#include <stdio.h> //potrzebne do funkcji sprintf
#include "attribs.h"
#include "UART_user.h"
#include "MM7150user.h"
#include "MM7150globalvars.h"
#include "p32mz2048efh064.h"
#include <string.h>

//******************************************************************************
//* M A I N  I N T E R R U P T  H A N D L E R                                 
//******************************************************************************
int spf_sucess = 0;
int tx1_end = 0;
int tx2_end = 0;
//char tx_buff1[20];

void __ISR(_TIMER_2_VECTOR, IPL7SRS) Timer2Handler(void)
{
    IFS0bits.T2IF= 0;
   // IMUReadReqest= 0xF;
    MM7150attendance();  
    if(PeriodGlobal>0)
    {   
        //odczytaj wynik
        sprintf(tx_buff1,"X%d\\Y%d\\Z%d\n\rAvg prandtl reading: %d\n\r\004", InclinometerX, InclinometerY, InclinometerZ, (ADCDATA0 + ADCDATA1/2));
  
        //sprintf(tx_buff2,"0x3P%d\0",ADCDATA0)
        
        //UART_send_string("Test message\0");
        PeriodGlobal= 0;       
    }
}