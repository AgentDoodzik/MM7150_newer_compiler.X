#include <xc.h>

#include <string.h>
#include <stdio.h>
#include "p32mz2048efh064.h"      
#include "MM7150globalvars.h"
#include "servo.h"
#include <sys/attribs.h>

uint8_t volatile __attribute__ ((coherent, aligned(16))) tx_buff[6];
char __attribute__ ((coherent, aligned(16))) char_tx_buff[20];
signed short InclinometerY_to_send = 0;
float sine_val_tmp;

void __ISR_AT_VECTOR(_TIMER_6_VECTOR, IPL7SRS) timer6Handler(void)
{
    /* Clear the cause of the interrupt (if required) */
    IFS0bits.T6IF = 0;
    

         InclinometerY_to_send = InclinometerY;
         sine_val =PWM_sine_wave_read_1();
         PWM_1_update(sine_val*5045 + 18498); //5045 18498
         PWM_2_update(-sine_val*6496+ 28545); //6496 28545
         
//         int16_t quantized_sine_val = (int16_t)(sine_val * 1000.0); // Scale sine_val as needed
//         int32_t packed_data = ((int32_t)InclinometerY_to_send << 16) | (uint16_t)quantized_sine_val;
//         
//        tx_buff[0] = 'a'; //frame begin symbol
//        tx_buff[1] = 'c';//(packed_data >> 24) & 0xFF; //MSB of the inclinomever value
//        tx_buff[2] = 'd';//(packed_data >> 16) & 0xFF; //LSB of inclinometer
//        tx_buff[3] = 'e';//(packed_data >> 8) & 0xFF; //MSB of sine wave value
//        tx_buff[4] = 'f';//packed_data & 0xFF; //LSB of Sine wave value
//        tx_buff[5] = 'b';  //frame end symbol
         
         sprintf(char_tx_buff,"%d, %.2f\n\r\0", InclinometerY_to_send, sine_val);
        
         asm volatile("nop");
         //DCH0ECONbits.CFORCE = 1; //manually DMA transfer launch
         
//         for(int i = 0; i<strlen(char_tx_buff)+1;)
//         {
//             U2TXREG = char_tx_buff[i++];
//         }
        
       
        
    }
