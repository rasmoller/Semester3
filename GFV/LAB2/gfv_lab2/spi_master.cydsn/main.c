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

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    
    UART_Start();
    SPIM_Start();
        
    UART_PutString("SPI initiateted, this is Master\r\n");
    
    for(;;)
    {
              
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_ReadRxData();
        UART_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'i':
        {
            SPIM_WriteByte(0xf);
            SPIM_ReadByte();
            break;
        }
        case 'o':
        {
            SPIM_WriteByte(0x9);
            SPIM_ReadByte();
            break;
        }
            default:
        {}
    }
}


/* [] END OF FILE */
