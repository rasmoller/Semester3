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
#include <stdio.h>
#include "project.h"
#include "PIDControl.h"
#include "I2C_temp.h"

static char outputBuffer[256];
static float setPoint = 30; // degrees celcius
static int flag;

#define SAMPLES_PER_SECOND 3
static uint16_t sampleWaitTimeInMilliseconds = 1000 / SAMPLES_PER_SECOND;

CY_ISR(isr_uart_rx_handler){
        uint8 bytesToRead = UART_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8 byteReceived = UART_ReadRxData();
        //UART_WriteTxData(byteReceived); // echo back
        
        switch(byteReceived){
            case '0':
            flag = 0;
            break;
            case '1':
            flag = 1;
            break;
            case '2':
            setPoint = 30;
            PIDControl_changeSetPoint(setPoint);
            break;
            case '3':
            setPoint = 50;
            PIDControl_changeSetPoint(setPoint);
            break;
            default:
            break;
        }
        
        bytesToRead--;
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    i2cInit();
    PWM_1_Init();
    PWM_1_Start();

    isr_uart_rx_StartEx(isr_uart_rx_handler);
    
    float Kp = 6.0f; 
    float Ki = 1.0f/10.0f; 
    float Kd = 0.0f;
    float integralMax = 3000;
    float integralMin = -3000;
    float temp = 0;
    float controlSignal = 0;

    float dt = ((float)sampleWaitTimeInMilliseconds) / 1000; // dt is measured in seconds
    PIDControl_init(Kp, Ki, Kd, integralMax, integralMin, dt);
    PIDControl_changeSetPoint(setPoint);

//    UART_1_PutString("Temperature control application started\r\n");

    for(;;)
    {
        /* Place your application code here. */
        i2cRead(0x48, &temp, 1);
        //i2cPrintTemp(temp);
        
        
        float error = setPoint - temp;
        float proportionalPart = 0;
        float integralPart = 0;
        float derivativePart = 0;
        
        controlSignal = PIDControl_doStep(temp, &proportionalPart, &integralPart, &derivativePart);
        
        if(controlSignal > 100) controlSignal = 100;
        if(controlSignal < 0) controlSignal = 0;
        
        if(flag)
        {
            PWM_1_WriteCompare((uint8)controlSignal);
        }
        // Reset all
        else 
        {
            PWM_1_WriteCompare(0);
            PIDControl_reset();
        }
                    
        snprintf(outputBuffer, sizeof(outputBuffer), "%.2f, %.2f, %.2f, %f, %.2f, %.2f, %.2f, %.2f, %.5f, %.2f \r\n \r\n", 
                                                      setPoint, temp, error, controlSignal, Kp, Ki, Kd, 
                                                      proportionalPart, integralPart, derivativePart);
        UART_PutString(outputBuffer);    

        CyDelay(sampleWaitTimeInMilliseconds);
    }
}

/* [] END OF FILE */
