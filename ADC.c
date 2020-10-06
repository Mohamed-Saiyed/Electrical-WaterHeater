#include "ADC.h"



void ADC_INIT(void)
{
    ADC_OFF;
    ADC_SELECT_CLOCK(8);
    ADC_CONFIGURE_PORT;
}

uint16_t ADC_Read(uint8_t Channel)
{
    uint16_t ret = 0;
    ADC_ON;
    ADC_ADJUST(1);
    ADC_SELECT_CHANEEL(Channel);
    ADC_START;
    ADC_WAIT_FOR_CONV;
    ret = ADC_RESUALT(1);
    ADC_OFF;
    return ret;
}