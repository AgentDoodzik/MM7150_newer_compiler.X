#include <xc.h>

#include "UART_user.h"
#include <string.h>
#include <stdio.h>
#include "p32mz2048efh064.h"      
#include "MM7150globalvars.h"
#include "servo.h"
#include <sys/attribs.h>

uint8_t volatile __attribute__ ((coherent, aligned(16))) tx_buff[6];
char temp_tx[20];
char __attribute__ ((coherent, aligned(16))) char_tx_buff[20];
signed short InclinometerY_to_send = 0;
volatile float sine_val = 0.0;

void __ISR_AT_VECTOR(_TIMER_6_VECTOR, IPL7SRS) timer6Handler(void)
{
    /* Clear the cause of the interrupt (if required) */
    IFS0bits.T6IF = 0;
   
    InclinometerY_to_send = InclinometerY; //Prepare Inclinometer pitch axis value to send
    sine_val =PWM_sine_wave_read_1(); //Update sine value
    
    //Update PWM value on servos
    PWM_1_update(sine_val*5045 + 18498); //  Lower & upper servo limits: 5045 18498
    PWM_2_update(-sine_val*6496+ 28545); //  6496 28545
         
    sprintf(char_tx_buff,"%d,%d\n\r", InclinometerY_to_send, (int16_t)(sine_val*1000));
    //UART_send(temp_tx);
             
    DCH0ECONbits.CFORCE = 1; //DMA transfer manual launch
         
    }
