#ifndef XC_WH_H
#define	XC_WH_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "main.h"

typedef enum
{
  Set_Mode,
  Normal_Mode,
  NON
}mode;

#define WH_PORT_CR      GPIO_PORTC_CONTROL
#define WH_PORT_DR      GPIO_PORTC_DATA

#define COOLER_PORT_CR  GPIO_PORTC_CONTROL
#define COOLER_PORT_DR  GPIO_PORTC_DATA 

#define WH_PIN          GPIO_PIN_5
#define COOLER_PIN      GPIO_PIN_2

void WH_Turn_On_Off(void);
void WH_Save_Last_Temp(void);
void WH_Set_temp(void);
void WH_Update(void);
void WH_CL_Init(void);
void Update_OS_Mode(void);
void Check_WH_mode(void);
void Update_Global_counter(void);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_WH_H */

