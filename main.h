
#ifndef XC_main_H
#define	XC_main_H

#include <xc.h> // include processor files - each processor file is guarded.

#define GPIO_PIN_0              (0)
#define GPIO_PIN_1              (1)
#define GPIO_PIN_2              (2)
#define GPIO_PIN_3              (3)
#define GPIO_PIN_4              (4)
#define GPIO_PIN_5              (5)
#define GPIO_PIN_6              (6)
#define GPIO_PIN_7              (7)

#define PORT_OUT                ((0x00))
#define PORT_IN                 ((0xFF))

#define PIN_OUT                (0)
#define PIN_IN                 (1)

#define PIN_HIGH               (1)
#define PIN_LOW                (0)
          

#define GPIO_PORTD_CONTROL      (TRISD)
#define GPIO_PORTD_DATA         (PORTD)

#define GPIO_PORTA_CONTROL      (TRISA)
#define GPIO_PORTA_DATA         (PORTA)

#define GPIO_PORTC_CONTROL      (TRISC)
#define GPIO_PORTC_DATA         (PORTC)

#define GPIO_PORTB_CONTROL      (TRISB)
#define GPIO_PORTB_DATA         (PORTB)


#define GPIO_INIT_PORT(CONTROL , DIRECTION)         ((CONTROL) = (DIRECTION) ? (PORT_IN) : (PORT_OUT))
#define GPIO_WRITE_PORT(PORT, DATA)                 ((PORT) = (DATA))
#define GPIO_READ_PORT(PORT)                        (PORT)

#define GPIO_INIT_PIN(CONTROL, PIN, DIRECTION)      ((CONTROL) = (CONTROL & (~(1 << PIN)))|(DIRECTION << PIN))
#define GPIO_WRITE_PIN(PORT , PIN , DATA)           ((PORT) = (((PORT) & (~1<<PIN))) | (DATA << PIN))
#define GPIO_READ_PIN(PORT, PIN)                    (((PORT) & (1 << PIN)) >> (PIN))
#define GPIO_TOGGLE_PIN(PORT, PIN)                  (((PORT) ^= (1 << PIN)))
 
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_main_H */

