#include "UART_user.h"
//#include "p32mz2048efh064.h"
#include "p32mz2048efh100.h"
#include "p32mz2048efh064.h"
#include <string.h>
void UART() //konfiguracja
{
    IEC5bits.U5TXIE = 0;
    U5MODE= 0;
    U5STA = 0;
    U5BRG = 0;
    
    /// Configuration of Tx and Rx I/O
    ANSELEbits.ANSE5 = 0; //digital
    ANSELBbits.ANSB5 = 0; //digital
    TRISEbits.TRISE5 = 0; //output - TX
    TRISBbits.TRISB5 = 1; //input - RX
    RPE5Rbits.RPE5R = 0b0011; //U5TX - CPU1
    U5RXRbits.U5RXR = 0b1000; //RPB5 - U5RX - CPU1
    
    //UxBRG == ((PBCLK/(16 * BAUDRATE ) -1 ), when BRGH = 0
    
    //PBCLK2 = 16 MHz
    
    //Interrupt config
    IFS5bits.U5TXIF = 0; //clear the flag
    U5STAbits.UTXISEL = 0b10; // interrupt is generated when transmit buff is empty
    
    //set the priority here
    
    
    U5MODEbits.BRGH = 0;
    U5BRG= (((16000000)/(16*9600))-1);
    U5MODEbits.PDSEL=1;
    U5MODEbits.STSEL=1;
    
    U5STAbits.UTXEN=1;
    U5STAbits.URXEN=0;
    U5MODEbits.UEN = 0b00;
    IEC5bits.U5TXIE = 1; //interrupt is enabled
    U5MODEbits.ON=1;
}
void UART_send_string(char* txt_to_send)
{
    int i =0;
    for(;txt_to_send[i]!='\0';)
    {
         if(!U5STAbits.UTXBF)
         {
             U5TXREG = (uint32_t)txt_to_send[i];
             i++;
         }
    }
   
}       
  
    
  
