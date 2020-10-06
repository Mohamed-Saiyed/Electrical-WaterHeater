
#ifndef XC_LED_H
#define	XC_LED_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "stdint.h"
#include "main.h"

#define LED_WH_PORT_CR      GPIO_PORTB_CONTROL
#define LED_WH_PORT_DR      GPIO_PORTB_DATA

#define LED_CL_PORT_CR      GPIO_PORTB_CONTROL
#define LED_CL_PORT_DR      GPIO_PORTB_DATA


#define LED_WH_PIN          GPIO_PIN_7

#define LED_CL_PIN          GPIO_PIN_7

void Led_Toggle(uint8_t Led);
void Led_Off(uint8_t Led);
void Led_on(uint8_t Led);
void Led_init(void);
void LED_Update(void);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_LED_H */

