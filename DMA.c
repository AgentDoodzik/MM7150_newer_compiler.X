#include "p32mz2048efh064.h"
#include "MM7150globalvars.h"
#include <sys/kmem.h>


void config_DMA(void)
{
    uint32_t dest_address_kseg1, source_address_kseg1; //variables for adresses of source and destination
    
    //the if/else conditional statements are related to the translation of kseg0 adress to kseg1 adress
    //kseg0 and kseg1 refers to the kernel adress location
    if(IS_KVA0(tx_buff))
        source_address_kseg1 = (uint32_t)KVA0_TO_KVA1(char_tx_buff);
    else
        source_address_kseg1 = (uint32_t)char_tx_buff;
    
    if(IS_KVA0(&U2TXREG))
        dest_address_kseg1 = (uint32_t)KVA0_TO_KVA1(&U2TXREG);
    else
        dest_address_kseg1 = (uint32_t)&U2TXREG;
    
    DCH0CON = 0x0; //disable DMA for config
    
    IEC1CLR=0x00010000; // disable DMA channel 0 interrupts
    IFS1CLR=0x00010000; // clear existing DMA channel 0 interrupt flag
    
    // channel off, priority 3, no chaining
    DCH0CONbits.CHPRI = 0b11; //channel 0 has highest priority
    
    IEC4bits.DMA0IE =0;
    IFS4bits.DMA0IF = 0;
    IPC33bits.DMA0IP = 5;
    //DCH0ECONbits.CHSIRQ = 134; //#134 - DMA channel dest done #181 UART5 TX transfer done interrupt starts the transfer, #28 - Timer 6 triggers dma trn.
    //DCH0ECONbits.SIRQEN = 1; //start the transfer when the interrupt above occurs
    DCH0DAT = '\r'; //termination mark - <CR> - stops the transfer
    DCH0ECONbits.PATEN = 1; //enable pattern termination functionality
    
    //KVA_TO_PA - convert virtual adress of a variable to physical
    //it's required for correct uart operation
    DCH0SSA= KVA_TO_PA(source_address_kseg1); //set source physical address
    DCH0DSA= KVA_TO_PA(dest_address_kseg1); //set destination physical address
    
    DCH0SSIZ= 21; // source size 15+1 bytes
    DCH0CSIZ = 2;
    DCH0DSIZ= 1; // destination size 1 bytes
    DCH0CONbits.CHAEN = 1; //re-enable the DMA after a transfer if there is still something to transmit
    
    //DCH0INTbits.CHBCIE = 1;// Destination done interrupt enable
    
}

void DMA_enable(void)
{
    DMACONbits.ON = 1; //enable the module
    //IEC4bits.DMA0IE = 1;
    DCH0CONbits.CHEN = 1; //enable ch0
    //DCH0ECONbits.CFORCE = 1; //force first transfer
}
