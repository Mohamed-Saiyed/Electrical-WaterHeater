
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_EEPROM_H
#define	XC_EEPROM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "main.h"
#include "I2C.h"


uint8_t EEPROM_Read(uint16_t add);
void EEPROM_Write(uint16_t add, uint8_t data);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_EEPROM_H */

