#include "project.h"
#define BTN_INTR_BOTH 0xffffu

void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_Start();
    SPIM_Start();
        
    UART_PutString("SPI initiateted, this is Master\r\n");
    
    for(;;)
    {
        CyDelay(20);
        if(!BTN_Read())
        {
            SPIM_ClearTxBuffer();
            SPIM_WriteTxData(0xcc); 
        }
        else
        {
            SPIM_ClearTxBuffer();
            SPIM_WriteTxData(0x55);
        }
    }
}

