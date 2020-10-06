#ifndef XC_I2C_H
#define	XC_I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdint.h>
#include <stdio.h>

#define _XTAL_FREQ 4000000

void I2C_Wait_idle(void);
void I2C_Master_init(const unsigned long baud);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Ack(void);
void I2C_Nack(void);
uint8_t I2C_Write(uint8_t Data);
uint8_t I2C_Read(void);
void I2C_Master_RepeatedStart();

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_I2C_H */

