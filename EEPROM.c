#include "EEPROM.h"


void EEPROM_Write(uint16_t add, uint8_t data)
{
    uint8_t ADDRH= (add & 0x0100) >> 8;
    uint8_t ADDRL =(add & 0x00FF);
    I2C_Start();
    if(ADDRH != 0)
    { 
      while(I2C_Write(0xA2));
    }
    else
    {
     while(I2C_Write(0xA0));
    }
    // Wait Until EEPROM Is IDLE
    I2C_Write(ADDRL);
    I2C_Write(data);
    I2C_Stop();
    
}


uint8_t EEPROM_Read(uint16_t add)
{

    uint8_t Data = 0 ;
    uint8_t ADDRH= (add & 0x0100) >> 8;
    uint8_t ADDRL =(add & 0x00FF);
    I2C_Start();
    if(ADDRH != 0)
    { 
      while(I2C_Write(0xA2));
    }
    else
    {
      while(I2C_Write(0xA0));
    }
    // Wait Until EEPROM Is IDLE
    I2C_Write(ADDRL);
    
    I2C_Start();
    if(ADDRH != 0)
    { 
      while(I2C_Write(0xA3));
    }
    else
    {
      while(I2C_Write(0xA1));
    }
    
    
    Data = I2C_Read();
    
    I2C_Stop();
    
    return Data;

}
