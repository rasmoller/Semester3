/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

// Inspiration to general solution
// https://community.cypress.com/docs/DOC-11153

#include "project.h"
#include <stdio.h>


#define BUFFER_LEN 2
#define PRINT_LEN 50

void i2cPrintTemp(float temp);
uint8 i2cRead(uint8 addr, float *result, int delayTime);

char printBuf[PRINT_LEN];


void i2cInit()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    // Initiate UART & I2C
    UART_Start();
    I2C_Start();
    I2C_EnableInt();    
}

//Continually measure the temperature and prints in console
void i2cPrintTemp(float temp)
{
        sprintf(printBuf, "Temperaturen paa slave 1 er: %.1f \r\n", temp);
        UART_PutString(printBuf);
}

// addr = Adress of i2C device
// *result = pass result by reference
// delayTime = delay after reading in milliseconds
uint8 i2cRead(uint8 addr, float *result, int delayTime){
    uint8 buffer[BUFFER_LEN];
    I2C_Init();
    I2C_MasterReadBuf(addr, buffer, BUFFER_LEN, I2C_MODE_COMPLETE_XFER);
    
    // Wait for transfer to complete
    while(I2C_MasterStatus() == I2C_MSTAT_XFER_INP);
    if(I2C_MasterStatus() != I2C_MSTAT_RD_CMPLT)
    {
      // Re-init I2C after fault
      I2C_Init();
      // Tranfer err
      return 0;
    }
    
    // Interpret LM75 2s compliment into propper float
    buffer[1] >>= 7;
    _Bool comp = buffer[0] & 0b10000000;
    buffer[0] <<= 1;
    uint8 total = buffer[0] | buffer[1]; 
    if(comp)
    {
      --total;
      total ^= 0xff;
    }
    
    *result = (float)total * 0.5;
    CyDelay(delayTime);
    
    //no err
    return 1;
}