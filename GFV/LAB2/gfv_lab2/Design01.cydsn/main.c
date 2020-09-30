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
#include "project.h"
#include <stdio.h>

#define BUFFER_LENGTH 2
#define PRINT_LEN 50

float i2cRead(uint8* buffer, uint8 addr);

uint8 buf[2];

char printBuf[PRINT_LEN];

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    UART_Start();
    I2C_Start();
    I2C_EnableInt();
    
    for(;;)
    {
        float temp1 = i2cRead(buf, 0x48);
        sprintf(printBuf, "Temperaturen paa slave1 er: %.1f \r\n", temp1);
        //UART_PutString(printBuf);
        CyDelay(50);
        
        float temp2 = i2cRead(buf, 0x49);
        sprintf(printBuf, "Temperaturen paa slave2 er: %.1f \r\n", temp2);
        UART_PutString(printBuf);
        
        CyDelay(50);
    }
}

float i2cRead(uint8 * buffer, uint8 addr){
    I2C_MasterReadBuf(addr, buffer, 2, I2C_MODE_COMPLETE_XFER);
    
    buffer[1] >>= 7;
    _Bool comp = buffer[0] & 0b10000000;
    buffer[0] <<= 1;
    uint8 total = buffer[0] | buffer[1]; 
    if(comp)
    {
        total ^= 0xff;
        ++total;
    }
    
    float retVal = (float)total * 0.5;
    
    return retVal;
}

/* [] END OF FILE */
