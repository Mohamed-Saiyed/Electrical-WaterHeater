/*
 * File:   main.c
 * Author: Mohamed-Sayed
 *
 * Created on July 11, 2020, 7:49 PM
 */


#define _XTAL_FREQ 4000000

#include <xc.h>
#include "config.h"
#include "I2C.h"
#include "ADC.h"
#include "WH.h"
#include "TIMER.h"
#include "LED.h"

void OS_init(void);


volatile uint8_t flag = 0;

void main(void)
{
  
       
    OS_init();  
    
    while(1)
    {
       
    }
    
    return;
}



void OS_init(void)
{
    Timer_init();
    ADC_INIT();
    I2C_Master_init(100000);
    SDD_Init();
    SW_Init();
    WH_CL_Init();
    Led_init();
    Timer_Start(10);
    PORTC &=~(1 << 5);
    TRISD &=~0xFF;
    TRISA &=~ 0xFB;   

}



