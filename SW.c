#include "SW.h"
#include "TIMER.h"

#define SW_UPDATE_PERIOD           (2)

#define SW_PRESSED_LEVEL           (0)
#define SW_RELEASED_LEVEL          (1)

#define NUM_OF_SW                  (3)
#define NUM_OF_SAMPLES             (2)

typedef struct
{
    uint8_t SW_Samples[NUM_OF_SAMPLES];
    SW_State SW_state;

}SW_Info;


SW_Info SWs_Info[NUM_OF_SW];

void SW_Init(void)
{
    uint8_t index = 0 ;
    GPIO_INIT_PIN(SWs_PORT_CR , SW_PLUS_PIN , PIN_IN);
    GPIO_INIT_PIN(SWs_PORT_CR , SW_MINUS_PIN , PIN_IN);
    
    for(index = SW_SET ; index < NUM_OF_SW ; index++ )
    {
        SWs_Info[index].SW_Samples[0] = SW_RELEASED_LEVEL;
        SWs_Info[index].SW_Samples[1] = SW_RELEASED_LEVEL;
        
        SWs_Info[index].SW_state = SW_RELEASED;
    
    }

}

SW_State SW_GetState(SW sw)
{
    return SWs_Info[sw].SW_state;
}

void SW_Update(void)
{
   static uint8_t SW_UPDATE = 0;
   uint8_t index = 0;
   SW_UPDATE +=TIMER_TICK_MS;
    
    if(SW_UPDATE != SW_UPDATE_PERIOD )
    {
        return;
    }
    SW_UPDATE = 0;
    
    for(index = SW_SET ; index < NUM_OF_SW ; index++)
    {
    
      SWs_Info[index].SW_Samples[0] = SWs_Info[index].SW_Samples[1];
      
      if(index == SW_PLUS)
      {
        SWs_Info[index].SW_Samples[1] = GPIO_READ_PIN(SWs_PORT_DR , SW_PLUS);
      }
      else if(index == SW_MINUS)
      {
       SWs_Info[index].SW_Samples[1] = GPIO_READ_PIN(SWs_PORT_DR , SW_MINUS);
      }
      else if (index == SW_SET)
      {
        SWs_Info[index].SW_Samples[1] = GPIO_READ_PIN(SWs_PORT_DR , SW_SET);
      }
      else
      {
      
      }
      switch(SWs_Info[index].SW_state)
      {
          case SW_RELEASED:
              if((SWs_Info[index].SW_Samples[0] == SW_PRESSED_LEVEL) &&
                 (SWs_Info[index].SW_Samples[1] == SW_PRESSED_LEVEL))
              {
                 SWs_Info[index].SW_state = SW_PRE_PRESSED;  
              }
              else
              {
              
              }
              break;
          case SW_PRE_PRESSED:
              if((SWs_Info[index].SW_Samples[1] == SW_PRESSED_LEVEL))
              {
                SWs_Info[index].SW_state = SW_PRESSED;  
              }
              else
              {
              
              }
              break;
          case SW_PRESSED:
              if((SWs_Info[index].SW_Samples[0] == SW_RELEASED_LEVEL) &&
                 (SWs_Info[index].SW_Samples[1] == SW_RELEASED_LEVEL))
              {
                 SWs_Info[index].SW_state = SW_PRE_RELEASED;  
              }
              else
              {
              
              }
              break;
          case SW_PRE_RELEASED:
              if((SWs_Info[index].SW_Samples[1] == SW_RELEASED_LEVEL))
              {
                SWs_Info[index].SW_state = SW_RELEASED;  
              }
              else
              {
              
              }
              break;
          default:
              break;
              
      
      }
          
    
    }
    
}
