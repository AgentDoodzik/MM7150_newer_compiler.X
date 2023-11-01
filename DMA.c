#include "p32mz2048efh100.h"
#include "MM7150globalvars.h"
#include <sys/kmem.h>


void config_DMA(void)
{
    uint32_t dest_address_kseg1, source_address_kseg1;
    
    if(IS_KVA0(tx_buff1))
        source_address_kseg1 = (uint32_t)KVA0_TO_KVA1(tx_buff1);
    else
        source_address_kseg1 = (uint32_t)tx_buff1;
    
    if(IS_KVA0(&U5TXREG))
        dest_address_kseg1 = (uint32_t)KVA0_TO_KVA1(&U5TXREG);
    else
        dest_address_kseg1 = (uint32_t)&U5TXREG;
    
    DCH0CON = 0x0;
    IEC1CLR=0x00010000; // disable DMA channel 0 interrupts
    IFS1CLR=0x00010000; // clear existing DMA channel 0 interrupt flag
    
    // channel off, priority 3, no chaining
    DCH0CONbits.CHPRI = 0b11; //highest priority 
    DCH0ECONbits.CHSIRQ = 19; //timer 4 interrupt starts the transfer
    DCH0ECONbits.SIRQEN = 1; //start the transfer when the interrupt above occurs
    
    DCH0SSA= KVA_TO_PA(source_address_kseg1); // transfer source physical address
    DCH0DSA= KVA_TO_PA(dest_address_kseg1);// transfer destination physical address
    
    DCH0SSIZ= 20; // source size 200 bytes
    DCH0DSIZ= 1; // destination size 200 bytes
    DCH0CSIZ= 1;
    DCH0CONbits.CHAEN = 1; //autoenable
    
    DCH0INTbits.CHERIF = 0;
    DCH0INTbits.CHERIE = 1; //address error interrupt enable
    
}

void DMA_enable(void)
{
    DMACONbits.ON = 1; //enable the module
    DCH0CONbits.CHEN = 1; //enable ch0
    DCH0ECONbits.CFORCE = 1;
}
