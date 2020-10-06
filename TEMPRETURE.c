#include "TEMPRETURE.h"


static void Temp_ten_average(void);

static float voltage = 0;
static uint16_t ADC_read = 0;
uint8_t Temperature;

#define TEMP_UPDATE_PERIOD    (10)

static uint8_t temp_average = 0 ;

uint8_t average_flag = 0 ;

uint32_t Ten_average_temp = 0 ;

uint32_t average_temp = 0 ;

void TEMP_Init(void)
{
    ADC_INIT();
}


void Tmepreture_Update(void)
{
     static uint32_t Temp_Update = 0;
   
     Temp_Update++;
     
     if(Temp_Update != TEMP_UPDATE_PERIOD)
     {
         return;
     }
     
     Temp_Update = 0 ;
     
     Get_temp();
     
     Temp_ten_average();
          
}

void Get_temp(void)
{
    ADC_read = ADC_Read(2);
    
    voltage = ADC_read * 0.0048828;
    
    Temperature = voltage / 0.01;

}

static void Temp_ten_average(void)
{
  temp_average += 1;  
  Ten_average_temp += Temperature;
  if(temp_average == 10)
  {
    average_temp = Ten_average_temp / 10 ;
    temp_average = 0 ;
    average_flag = 1 ;
     Ten_average_temp = 0;
  }

}