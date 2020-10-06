
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_SSD_H
#define	XC_SSD_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "main.h"
#include "TIMER.h"


#define _XTAL_FREQ 4000000

typedef enum
{
    SSD_OFF = 0,
    SSD_ON = 1
            
}SSD_State;

#define SSD_DATA_PORT_DR     GPIO_PORTD_DATA
#define SSD_DATA_PORT_CR     GPIO_PORTD_CONTROL

#define SSD_CONTROL_PORT_DR  GPIO_PORTA_DATA
#define SSD_CONTROL_PORT_CR  GPIO_PORTA_CONTROL

#define SSD_DISP3_PIN       GPIO_PIN_4  
#define SSD_DISP2_PIN       GPIO_PIN_3

#define SSD_NULL            0x00

void SDD_Init(void);
void SSD_SetSSD(uint8_t ssd);
void SSD_Toggle(void);
void SSD_Blink(void);
void SSD_SetState(SSD_State state);
void DISP_Update(void);
void SSD_OUT(uint8_t Data , uint8_t ssd);


void SW_Init(void);
void SW_Update(void);

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_SSD_H */

