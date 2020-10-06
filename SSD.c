#include "SSD.h"
#include "EEPROM.h"
#include "SW.h"
#include "TIMER.h"
#include "WH.h"

#define SSD_UPDATE_PERIOD     (2)

#define SSD_BLINK_PERIOD      (100)

static void DISP_Elements(uint8_t var);
static void SSD_Dispaly_NULL(void);

extern mode MODE;
extern uint8_t Temperature;
extern uint8_t set_temp ;

static uint32_t Current_SSD = SSD_DISP2_PIN;
static SSD_State SSD_STATE = SSD_OFF;

SSD_State SSD_BLINK_STATE = SSD_OFF;
uint8_t SSD_map[10] = {0x3F , 0x06 , 0x5B ,0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F}; 

void SDD_Init(void)
{
    GPIO_INIT_PIN(SSD_CONTROL_PORT_CR , SSD_DISP2_PIN , PIN_OUT);
    GPIO_INIT_PIN(SSD_CONTROL_PORT_CR , SSD_DISP2_PIN , PIN_OUT); 
    GPIO_INIT_PORT(SSD_DATA_PORT_CR , PORT_OUT);  
}

void DISP_Update(void)
{
    static uint32_t DISP_Counter = 0;
    static uint32_t DISP_Blink = 0 ;
    DISP_Counter += TIMER_TICK_MS;
    if(DISP_Counter != SSD_UPDATE_PERIOD)
    {
        return;
    }
    
    DISP_Counter = 0;

    if(MODE == Normal_Mode)
    {
        DISP_Elements(Temperature);    
    }
    else if(MODE == Set_Mode)
    {
        DISP_Blink += TIMER_TICK_MS; 
        DISP_Elements(set_temp);
        if(DISP_Blink != SSD_BLINK_PERIOD)
        {
            return;
        }

        SSD_Blink();

        DISP_Blink = 0;

    }
    else
    {
       SSD_Dispaly_NULL();
    }
   
}

static void SSD_Dispaly_NULL(void)
{
  GPIO_WRITE_PORT(SSD_DATA_PORT_DR , SSD_NULL);
}

void SSD_Toggle(void)
{
    if(SSD_BLINK_STATE == SSD_ON)
    {
         SSD_SetState(SSD_OFF);
    }
    else
    {
        SSD_SetState(SSD_ON);
    }
}

void SSD_SetSSD(uint8_t ssd)
{
    switch(ssd)
    {
        case SSD_DISP2_PIN:
        GPIO_WRITE_PIN(SSD_CONTROL_PORT_DR , SSD_DISP3_PIN , SSD_OFF);
        GPIO_WRITE_PIN(SSD_CONTROL_PORT_DR , SSD_DISP2_PIN , SSD_ON);
        break;
        case SSD_DISP3_PIN:
        GPIO_WRITE_PIN(SSD_CONTROL_PORT_DR , SSD_DISP2_PIN , SSD_OFF);
        GPIO_WRITE_PIN(SSD_CONTROL_PORT_DR , SSD_DISP3_PIN , SSD_ON);
        break;
        defualt:
        break;
    
    }
}

void SSD_SetState(SSD_State state)
{
    SSD_BLINK_STATE = state;
}

void SSD_Blink(void)
{
    GPIO_WRITE_PORT(SSD_DATA_PORT_DR , SSD_NULL);
    SSD_Toggle();
}

void SSD_OUT(uint8_t Data , uint8_t ssd)
{
   if(SSD_BLINK_STATE == SSD_OFF)
   {
    SSD_SetSSD(ssd);   
    GPIO_WRITE_PORT(SSD_DATA_PORT_DR , SSD_map[Data]);
   }
       
 }


static void DISP_Elements(uint8_t var)
{
   if(Current_SSD == SSD_DISP2_PIN)
    {
      SSD_OUT(var /10 , Current_SSD);
      Current_SSD = SSD_DISP3_PIN;  
    }
    else
    { 
        
      SSD_OUT(var % 10 , Current_SSD);  
      Current_SSD = SSD_DISP2_PIN;
       
    }

}








