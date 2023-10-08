/* 
 * File:   UART_user.h
 * Author: macie
 *
 * Created on 21 grudnia 2022, 17:28
 */

#ifndef UART_USER_H
#define	UART_USER_H

#define pbclk 16000000
#define brate 9600


void UART();
int UART_send(char* txt_to_send);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UART_USER_H */

