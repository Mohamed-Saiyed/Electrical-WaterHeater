#ifndef XC_SW_H
#define	XC_SW_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "main.h"

#define SW_PLUS_PIN       GPIO_PIN_2

#define SW_MINUS_PIN      GPIO_PIN_1

#define SWs_PORT_DR       GPIO_PORTB_DATA
#define SWs_PORT_CR       GPIO_PORTB_CONTROL

typedef enum
{
    SW_SET ,
    SW_MINUS,
    SW_PLUS         
            
}SW;

typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED

}SW_State;


void SW_Update(void);
void SW_Init(void);
SW_State SW_GetState(SW sw);
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

#endif	/* XC_SW_H */

