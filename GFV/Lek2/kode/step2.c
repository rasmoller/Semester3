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

//Lav arrays med enum, til at repræsentere de forskellige steps

#include "project.h"
#include <stdlib.h>

CY_ISR_PROTO(ISR_UART_rx_handler);

// Motor control
void move(int, int);
void rotation();
void counterRotation();

void handleByteReceived(uint8_t byteReceived);

const int fullStep[8][4] = { 
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}
};

const int waveDrive[8][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};

const int halfStep[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}
};

int step = 0;
int dir = 1;
int chooseMode = 1;
int delay = 50;
int stopMotor = 1;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    
    UART_1_PutString("Stepper motor application started\r\r\n");
    
    
    for(;;)
    {
        if(!stopMotor)
        {
            move(dir, chooseMode);
            CyDelay(delay);
        }
    }
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'w' :
        {
            dir = 1;
            UART_1_PutString("w: Forwards\r\n");
        }
        break;
        case 's' : 
        {
            dir = 0;
            UART_1_PutString("s: backwards\r\n");
        }
        break;
        case '+' :
        {
            delay -= 5;
            if (delay <=5) delay = 5;
            UART_1_PutString("+: Increase speed\r\n");
            char text[20];
            itoa(delay, text, 10);
            UART_1_PutString(text);
        }
        break;
        case '-' : 
        {
            delay += 5;
            UART_1_PutString("-: Decrease speed\r\n");
            char text[20];
            itoa(delay, text, 10);
            UART_1_PutString(text);
        }
        break;
        case '0' : 
        {
            stopMotor = 1;
            UART_1_PutString("0: Stop motor\r\n");
        }
        break;
        case '1' : 
        {
            stopMotor = 0;
            UART_1_PutString("1: Start motor\r\n");
        }
        break;
        case 'm' :
        {
            chooseMode = 1; //Wave
            UART_1_PutString("m: Wave Drive\r\n");
        }
        break;
        case 'k' : 
        {
            chooseMode = 2; //Full
            UART_1_PutString("m: Full setp\r\n");
        }
        break;
        case 'l' : 
        {
            chooseMode = 3; //Half
            UART_1_PutString("m: Half step\r\n");
        }
        break;
        case 'r' :
        {
             rotation();  
        }
        break;
        case 't' :
        {
            counterRotation();
        }
        break;
        default :
        {
            // Default
        }
        break;
    }
}

void move(int dir, int chooseMode)
{
    dir ? ++step : --step;
    
    if(step > 7) step = 0;
    if(step < 0) step = 7;
    
    //UART_1_PutChar(step + 48);
    
    switch(chooseMode){
        case 1 : 
        {
            stepCtrl1_Write(waveDrive[step][0]); //A
            stepCtrl2_Write(waveDrive[step][1]); //B
            stepCtrl3_Write(waveDrive[step][2]); //A'
            stepCtrl4_Write(waveDrive[step][3]); //B'
        }
        case 2 :
        {
            stepCtrl1_Write(fullStep[step][0]);
            stepCtrl2_Write(fullStep[step][1]);
            stepCtrl3_Write(fullStep[step][2]);
            stepCtrl4_Write(fullStep[step][3]);   
        }
        case 3 :
        {
            stepCtrl1_Write(halfStep[step][0]);
            stepCtrl2_Write(halfStep[step][1]);
            stepCtrl3_Write(halfStep[step][2]);
            stepCtrl4_Write(halfStep[step][3]);   
        }
    }
}

void rotation()
{
    int step = 0;
    for(int x = 0; x < 48; x++){
        ++step; 
        if(step > 7) step = 0;
        
        stepCtrl1_Write(waveDrive[step][0]); //A
        stepCtrl2_Write(waveDrive[step][1]); //B
        stepCtrl3_Write(waveDrive[step][2]); //A'
        stepCtrl4_Write(waveDrive[step][3]); //B'
        CyDelay(20);
    }
}

void counterRotation()
{
    int step = 0;
    for(int x = 0; x < 48; x++){
        --step; 
        if(step < 0) step = 7;
        
        stepCtrl1_Write(waveDrive[step][0]); //A
        stepCtrl2_Write(waveDrive[step][1]); //B
        stepCtrl3_Write(waveDrive[step][2]); //A'
        stepCtrl4_Write(waveDrive[step][3]); //B'
        CyDelay(20);
    }
}