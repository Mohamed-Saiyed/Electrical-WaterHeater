#include "TIMER.h"
#include "SW.h"
#include "TEMPRETURE.h"
#include "WH.h"
#include "LED.h"

static void Timer_update_reg(uint8_t tick_ms);
static uint16_t Timer_Update_Vlue ; 




mode MODE = Set_Mode;

void Timer_init(void)
{   
    TIMER_SET_PSC_1;
    TIMER_DISABLE;
}


void Timer_Start(uint8_t tick_ms)
{
    PEIE = 1;   // Peripherals Interrupts Enable Bit
    GIE = 1;    // Global Interrupts Enable Bit
    Timer_update_reg(tick_ms);    
    TIMER_INTERNAL_CLK_EN;
    TIMER_CLEAR_FLAG;
    TIMER_INT_ENABLE;
    TIMER_ENABLE;
}

void Timer_Stop(void)
{
    TIMER_DISABLE;
}
static void Timer_update_reg(uint8_t tick_ms)
{
    if((tick_ms >= 1) && (tick_ms <= 65))
    {
        Timer_Update_Vlue = (65536 - (((tick_ms * 0.001) * _XTAL_FREQ) / 4 ));
        
        TIMER_UPDATE(Timer_Update_Vlue);        
    }
    else
    {
        TIMER_UPDATE(55536); //10 MS as default
    }
  
}


void TMR_Update(void) __interrupt 0
{   

      Update_Global_counter();
      Update_OS_Mode();
      DISP_Update();
      SW_Update();  
      Tmepreture_Update();
      LED_Update();
      WH_Update();
      TIMER_UPDATE(Timer_Update_Vlue);
 
      TIMER_CLEAR_FLAG;
     
}
