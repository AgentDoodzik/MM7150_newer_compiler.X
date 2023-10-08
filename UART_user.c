#include "UART_user.h"
#include "p32mz2048efh064.h"
#include <string.h>
void UART() //konfiguracja
{
    U2MODE=0;
    U2STA = 0;
    U2BRG = 0;
    
    /// Configuration of Tx and Rx I/O
    TRISBbits.TRISB14 = 0; //output - TX
    TRISBbits.TRISB15 = 1;
    RPB14Rbits.RPB14R = 0b0010; //U2TX
    U2RXRbits.U2RXR = 0b0011; //RPB15 - U2RX
    
    //UxBRG == ((PBCLK/(16 * BAUDRATE ) -1 ), when BRGH = 0
    
    //PBCLK2 = 16 MHz
    
    U2MODEbits.BRGH = 0;
    U2BRG= (((16000000)/(16*9600))-1);
    U2STAbits.UTXEN=1;
    U2STAbits.URXEN=1;
    U2MODEbits.PDSEL=0;
    U2MODEbits.STSEL=0;
    //U2MODEbits.UEN = 0b11;
    U2MODEbits.ON=1;
}
int UART_send(char* txt_to_send)
{
    static int i =0;
    //&& (U2STAbits.UTXBF == 0))
    if(i<=strlen(txt_to_send))
    {
         //while(U2STAbits.UTXBF !=0) {}; //czekamy, az bufor sie wyczysci
         if(U2STAbits.UTXBF == 0)
         {
         
             U2TXREG = txt_to_send[i++];//txt_to_send[i++];
         }
         return 0;

    }
    else
    {i= 0;
    return 1;
    }
    
}       
  
    
  
