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

CY_ISR_PROTO(isr_spi_rx_handler);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_spi_rx_StartEx(isr_spi_rx_handler);
    SPIS_Start();
    
    for(;;)
    {
        
    }
}

CY_ISR(isr_spi_rx_handler)
{
    while(SPIS_GetRxBufferSize() != SPIS_STS_RX_FIFO_NOT_EMPTY)
    {
        uint8_t data = SPIS_ReadByte();
        switch(data)
        {
            case 0x8:
            {
                LED_Write(0);
            break;   
            }
            case 0xf:
            {
                LED_Write(1);
                break;
            }
        }
    }
}

