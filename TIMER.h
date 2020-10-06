
#ifndef XC_TIMER_H
#define	XC_TIMER_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "SSD.h"



#define _XTAL_FREQ 4000000

#define TIMER_TICK_MS         (1)

#define TIMER_OVF_FLAG        (TMR1IF)

#define TIMER_CLEAR_FLAG      (TMR1IF = 0)

#define TIMER_ENABLE          (TMR1ON = 1)

#define TIMER_DISABLE         (TMR1ON = 0)

#define TIMER_INT_ENABLE      (TMR1IE = 1)

#define TIMER_SET_PSC_1       T1CKPS1 = 0;\
                              T1CKPS0 = 0

#define TIMER_UPDATE(TIME)    ((TMR1) = (TIME))

#define TIMER_INTERNAL_CLK_EN  (TMR1CS = 0);


void Timer_init(void);
void Timer_Start(uint8_t tick_ms);
void Timer_Stop(void);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_TIMER_H */

