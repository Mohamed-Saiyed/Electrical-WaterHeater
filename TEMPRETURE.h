#ifndef XC_TEMP_H
#define	XC_TEMP_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "TIMER.h"
#include "ADC.h"

void Get_temp(void);
void Tmepreture_Update(void);
void TEMP_Init(void);




#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_TEMP_H */

