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

CY_ISR_PROTO(isr_spi_rx_handler);

int main(void)
{
    CyGlobalIntEnable;
    isr_spi_rx_StartEx(isr_spi_rx_handler);
    SPIS_Start();
    UART_Start(); //debuging
    
    // LED startup sequence
    LED_Write(1);
    CyDelay(500);
    LED_Write(0);
    
    for(;;)
    {  
    }
}

CY_ISR(isr_spi_rx_handler)
{
    uint8_t data = SPIS_ReadByte();
    
    // Write to terminal for DEBUGGING
    char buf[20];
    sprintf(buf, "Data received: %x\r\n", data);
    UART_PutString(buf);
    
    // Clear buffer, makes it easier
    SPIS_ClearRxBuffer();
    
    switch(data)
    {
        case 0xcc:
        {
            LED_Write(1);
        break;   
        }
        case 0x55:
        {
            LED_Write(0);
            break;
        }
        default:
        {}
    }
}