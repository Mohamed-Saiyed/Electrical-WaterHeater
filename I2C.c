#include "I2C.h"

void I2C_Wait_idle(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_init(const unsigned long baud)
{
  SSPCON = 0b00101000;
  SSPCON2 = 0x00;
  SSPADD = (_XTAL_FREQ/(4*baud))-1;
  SSPSTAT = 0x00;
  TRISC3  = 1;
  TRISC4 =  1 ;
}

void I2C_Start(void)
{
    I2C_Wait_idle();
    SEN = 1;
}

void I2C_Stop(void)
{
    I2C_Wait_idle();
    PEN = 1;
}
void I2C_Ack(void)
{
    I2C_Wait_idle();
    SSPCON2 &=~ (1 << 5);
    SSPCON2 |=  (1 << 4);

}
void I2C_Nack(void)
{
    I2C_Wait_idle();
    SSPCON2 |= (1 << 5);
    SSPCON2 |=  (1 << 4);

}

uint8_t I2C_Write(uint8_t Data)
{
  SSPBUF = Data;
  while(!SSPIF); // Wait Until Completion
  SSPIF = 0;
  return ACKSTAT;
    
}

uint8_t I2C_Read(void)
{
  I2C_Wait_idle();
  RCEN = 1; // Enable & Start Reception
  while(!SSPIF); // Wait Until Completion
  SSPIF = 0; // Clear The Interrupt Flag Bit
  I2C_Wait_idle();
  return SSPBUF; // Return The Received Byte

}
void I2C_Master_RepeatedStart()
{
  I2C_Wait_idle();
  RSEN = 1;
}
