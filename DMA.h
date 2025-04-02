/* 
 * File:   DMA.h
 * Author: macie
 *
 * Created on 14 stycznia 2024, 14:56
 */

#ifndef DMA_H
#define	DMA_H

#include "servo.h"


#ifdef	__cplusplus
extern "C" {
#endif

void config_DMA(void);
void DMA_enable(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DMA_H */

