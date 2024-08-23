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
#include "servo.h"


//******************************************************************************
//* M A I N  I N T E R R U P T  H A N D L E R                                 
//******************************************************************************
int spf_sucess = 0;
int tx1_end = 0;
int tx2_end = 0;
uint8_t data[6];
signed short InclinometerY_to_send = 0;
float sine_val_tmp;

extern uint8_t tx_buff[10];

void __ISR(_TIMER_2_VECTOR, IPL7SRS) Timer2Handler(void)
{
    IFS0bits.T2IF= 0;   
    asm volatile("di");
    int_cnt++;
   // IMUReadReqest= 0xF;
    MM7150attendance();
     if(PeriodGlobal>0)   
        {   
          
            PeriodGlobal= 0;
        }
    
    
    if(int_cnt == 20)   
    {
         InclinometerY_to_send = InclinometerY;
         sine_val =PWM_sine_wave_read_1();
         PWM_1_update(sine_val*5045 + 18498); //5045 18498
         PWM_2_update(-sine_val*6496+ 28545); //6496 28545
         
         int16_t quantized_sine_val = (int16_t)(sine_val * 1000.0); // Scale sine_val as needed
         int32_t packed_data = ((int32_t)InclinometerY_to_send << 16) | (uint16_t)quantized_sine_val;
         
        data[0] = 0xAA; //frame begin symbol
        data[1] = (packed_data >> 24) & 0xFF;
        data[2] = (packed_data >> 16) & 0xFF;
        data[3] = (packed_data >> 8) & 0xFF;
        data[4] = packed_data & 0xFF;
        data[5] = 0xFF;  //frame end symbol
        
        
//         for(int i = 0;i < 6;)
//    {
//         if(U2STAbits.UTXBF == 0)//oczekiwanie na wyczyszczenie bufora
//         {
//            U2TXREG = data[i++];//txt_to_send[i++];
//         }
    
         
//       sprintf(tx_buff, "%hi;%.2lf\n\r", InclinometerY_to_send, sine_val);
//       DCH0ECONbits.CFORCE = 1; //manually DMA transfer launch
         
        int_cnt = 0;
        
    }
    asm volatile("ei");
 \
}
    
}

