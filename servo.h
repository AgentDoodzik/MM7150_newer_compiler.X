/* 
 * File:   servo.h
 * Author: macie
 *
 * Created on 10 listopada 2022, 12:38
 */

#ifndef SERVO_H
#define	SERVO_H



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
// PIC32MZ2048EFH064 Configuration Bit Settings

// 'C' source line config statements


#include <math.h>
#include "p32mz2048efh064.h"
#include <stdint.h>

void freq_set(uint8_t on);

//serwomechanizmy lotek
void PWM_1_conf(uint16_t duty_var, uint8_t on);
void PWM_2_conf(uint16_t duty_var, uint8_t on);
void PWM_3_conf(uint16_t duty_var, uint8_t on);
void PWM_4_conf(uint16_t duty_var, uint8_t on);
void PWM_5_conf(uint16_t duty_var, uint8_t on);
void PWM_6_conf(uint16_t duty_var, uint8_t on);

void PWM_W_conf(uint16_t duty_var, uint8_t on); // serwomechanizm srodka ciezkosci



void PWM_1_update(uint16_t new_duty_var);
void PWM_2_update(uint16_t new_duty_var);
void PWM_3_update(uint16_t new_duty_var);
void PWM_4_update(uint16_t new_duty_var);
void PWM_5_update(uint16_t new_duty_var);
void PWM_6_update(uint16_t new_duty_var);

void PWM_W_update(uint16_t new_duty_var);



#endif	/* SERVO_H */







//void __ISR_AT_VECTOR(_TIMER_3_VECTOR, IPL5SRS) update_PWM_Duty(void); //przerwania

// funkcje SET ustawiaja parametry PWM i wlaczaja/wylaczaja go 
//uzywamy ich NA POCZATKU
//#include <stdint.h>




