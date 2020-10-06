#include "LED.h"
#include "TIMER.h"

#define LED_UPDATE_PERIOD    (100)

extern uint8_t WH_FLAG;
extern uint8_t CL_Flag;


void Led_init(void)
{
    GPIO_INIT_PIN(LED_CL_PORT_CR , LED_CL_PIN , PIN_OUT);
    GPIO_INIT_PIN(LED_WH_PORT_CR , LED_WH_PIN , PIN_OUT);

}

void LED_Update(void)
{
    static uint32_t Led_counter = 0 ;
    Led_counter += TIMER_TICK_MS;
  
    if(Led_counter != LED_UPDATE_PERIOD)
    {
        return;
    }
    Led_counter = 0 ;
    
    if(WH_FLAG)
    {
      Led_Toggle(LED_WH_PIN);
    }
    else if(CL_Flag)
    {
      Led_Off(LED_WH_PIN);
      Led_on(LED_CL_PIN);
    }
    else
    {
    
    }

}

void Led_on(uint8_t Led)
{
    GPIO_WRITE_PIN(LED_CL_PORT_DR , Led , PIN_HIGH);
}

void Led_Off(uint8_t Led)
{
    GPIO_WRITE_PIN(LED_CL_PORT_DR , Led , PIN_LOW);
}

void Led_Toggle(uint8_t Led)
{
  GPIO_TOGGLE_PIN(LED_CL_PORT_DR , Led);
}
