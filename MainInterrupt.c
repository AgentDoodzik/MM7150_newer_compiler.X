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
uint8_t __attribute__ ((coherent, aligned(16))) tx_buff[6] = {0};
signed short InclinometerY_to_send = 0;
float sine_val_tmp;

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
         
        tx_buff[0] = 0xA; //frame begin symbol
        tx_buff[1] = (packed_data >> 24) & 0xFF; //MSB of the inclinomever value
        tx_buff[2] = (packed_data >> 16) & 0xFF; //LSB of inclinometer
        tx_buff[3] = (packed_data >> 8) & 0xFF; //MSB of sine wave value
        tx_buff[4] = packed_data & 0xFF; //LSB of Sine wave value
        tx_buff[5] = 0xB;  //frame end symbol
        
                 
//       sprintf(tx_buff, "%hi;%.2lf\n\r", InclinometerY_to_send, sine_val);
       DCH0ECONbits.CFORCE = 1; //manually DMA transfer launch
         
        int_cnt = 0;
        
    }
    asm volatile("ei");
 \
}
    
}

