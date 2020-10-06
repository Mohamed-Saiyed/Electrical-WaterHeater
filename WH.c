#include "WH.h"
#include "TIMER.h"
#include "SW.h"
#include "EEPROM.h"


#define WH_UPDATE_PERIOD      (2)
#define TEMP_SAMPEL           (5)
#define MAX_TEMP              (75)
#define MIN_TEMP              (35)
#define MAX_WAIT_TIME         (500)
#define INITIAL_TEMP          (60)
#define TEMP_EEPROM_LOCATION  (0x0030)

static void WH_turn_on(void);
static void WH_turn_off(void);
static void COOL_turn_on(void);
static void COOL_turn_off(void);
static void WH_Disable(void);
static void get_temp_after_reset(void);

static uint32_t g_tick_count = 0;
static uint32_t Init_flag = 0 ;
static uint32_t Sleep_flag = 0 ;


extern uint32_t average_temp;
extern SSD_State SSD_BLINK_STATE;
extern uint8_t average_flag;

uint8_t back_up_temp = 0 ;
uint8_t Current_Temp = 60 ;
uint8_t set_temp = 60 ;
uint8_t WH_FLAG = 0;
uint8_t CL_Flag = 0;

mode MODE = NON;

void WH_CL_Init(void)
{
    GPIO_INIT_PIN(WH_PORT_CR , WH_PIN , PIN_OUT);
    GPIO_INIT_PIN(COOLER_PORT_CR , COOLER_PIN , PIN_OUT);
}

void WH_Update(void)
{
    static uint32_t WH_Counter = 0 ;
    WH_Counter += TIMER_TICK_MS;
    
    if(WH_Counter != WH_UPDATE_PERIOD)
    {
        return;    
    }
    WH_Counter = 0;
    Check_WH_mode();
    if(MODE == Set_Mode)
    {        
        WH_Save_Last_Temp();
        WH_Set_temp();
    }
    else if(MODE == Normal_Mode)
    {           
        WH_Turn_On_Off();   
    }
    else
    {
     
    }
}

void WH_Set_temp(void)
{
   
    if(SW_GetState(SW_PLUS) == SW_PRE_PRESSED && Init_flag == 2)
    {
        if(set_temp < MAX_TEMP)
        {
          set_temp += TEMP_SAMPEL;
        }        
    }
    else if(SW_GetState(SW_MINUS) == SW_PRE_PRESSED && Init_flag == 2)
    {
        if(set_temp > MIN_TEMP)
        {
             set_temp -= TEMP_SAMPEL;
        }    
    }
    else
    {

    }

}

void WH_Save_Last_Temp(void)
{
    EEPROM_Write(TEMP_EEPROM_LOCATION , set_temp);
    Current_Temp = set_temp;
}

static void get_temp_after_reset(void)
{
  back_up_temp =  EEPROM_Read(TEMP_EEPROM_LOCATION);
  Current_Temp = back_up_temp ;
}

void WH_Turn_On_Off(void)
{
    if(average_flag == 1)
    {
        if(average_temp <= (Current_Temp - 5))
        {
          WH_turn_on();
          COOL_turn_off();
        }
        else if(average_temp >= (Current_Temp + 5))
        {
          WH_turn_off();
          COOL_turn_on();   
        }
        
        average_flag = 0 ;   
    }   
           
}


void Update_Global_counter(void)
{  
    if(MODE == Set_Mode)
    {
      g_tick_count += TIMER_TICK_MS;
    }   
    if((SW_GetState(SW_PLUS) == SW_PRE_PRESSED)   ||
       (SW_GetState(SW_MINUS) == SW_PRE_PRESSED)  ||
       ((SW_GetState(SW_SET) == SW_PRE_PRESSED)))
    {
        g_tick_count = 0 ;
    }
    else
    {
    
    }
       
}

void Check_WH_mode(void)
{
    if(((SW_GetState(SW_PLUS) == SW_PRE_PRESSED) ||
      (SW_GetState(SW_MINUS) == SW_PRE_PRESSED)) && (Init_flag !=2) && (Sleep_flag != 0))
    {
        WH_turn_off();
        COOL_turn_off();
        MODE = Set_Mode;
        Init_flag++ ;      
    }
    else if(SW_GetState(SW_SET) == SW_PRE_PRESSED)
    {
      if(Sleep_flag == 0)
      { 
         MODE = Normal_Mode;
         Sleep_flag = 1 ;
      }
      else if(Sleep_flag == 1)
      {   
          get_temp_after_reset();
          WH_Disable();
          MODE = NON;
          Sleep_flag = 0 ;
      }
    }
    else
    {
       
    }
}

static void WH_Disable(void)
{
     WH_turn_off();
     COOL_turn_off();
     g_tick_count = 0;
     Init_flag = 0;
     set_temp = INITIAL_TEMP;
     SSD_BLINK_STATE = SSD_OFF ;

}

void Update_OS_Mode(void)
{
    if(g_tick_count != MAX_WAIT_TIME)
    {
        return;
    }
    MODE = Normal_Mode;
    g_tick_count = 0;
    Init_flag = 0;
    SSD_BLINK_STATE = SSD_OFF ;
}

static void WH_turn_on(void)
{
    GPIO_WRITE_PIN(WH_PORT_DR , WH_PIN , PIN_HIGH);
    WH_FLAG = 1 ;
}

static void WH_turn_off(void)
{
  GPIO_WRITE_PIN(WH_PORT_DR , WH_PIN , PIN_LOW);
  WH_FLAG = 0 ;
}

static void COOL_turn_on(void)
{
  GPIO_WRITE_PIN(COOLER_PORT_DR , COOLER_PIN , PIN_HIGH);
  CL_Flag = 1 ;
}

static void COOL_turn_off(void)
{
 GPIO_WRITE_PIN(COOLER_PORT_DR , COOLER_PIN , PIN_LOW);
 CL_Flag = 0 ;
}
