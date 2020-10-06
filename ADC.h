/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_ADC_H
#define	XC_ADC_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdint.h>
#include <stdio.h>

#define _XTAL_FREQ 4000000


#define ADC_OFF (ADON = 0)
#define ADC_ON  (ADON = 1)

#define ADC_SELECT_CLOCK(clock) (ADCS2 = ((clock) & 0x4 ) >> 2);\
                                (ADCS1 = ((clock) & 0x2 ) >> 1);\
                                (ADCS2 = ((clock) & 0x1 ) >> 0);\
                                
#define ADC_CONFIGURE_PORT PCFG3 = 1;\
                           PCFG2 = 0;\
                           PCFG1 = 1;\
                           PCFG0 = 0

#define ADC_ADJUST(adjustment)  (ADFM = adjustment)

#define ADC_SELECT_CHANEEL(Channel)  (CHS2 = ((Channel) & 0x4 ) >> 2);\
                                     (CHS1 = ((Channel) & 0x2 ) >> 1);\
                                     (CHS0 = ((Channel) & 0x1 ) >> 0);\

#define ADC_START (GO = 1)
#define ADC_WAIT_FOR_CONV while(GO == 1)
#define ADC_RESUALT(adjustment)  (((uint16_t)ADRESH << 8) | ADRESL)

void ADC_INIT(void);
uint16_t ADC_Read(uint8_t Channel);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

