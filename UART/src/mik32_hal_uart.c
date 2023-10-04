#include "mik32_hal_uart.h"

void HAL_UART_Disable(mic32_hal_uart *huart)
{
    huart->Instance->CONTROL1 &=~UART_CONTROL1_UE_M;
}

void HAL_UART_Enable(mic32_hal_uart *huart)
{
    huart->Instance->CONTROL1 |= UART_CONTROL1_UE_M;
}

HAL_UART_ClearError(mic32_hal_uart *huart)
{
    huart->Instance->FLAGS |= 0x1FF;
}

HAL_StatusTypeDef HAL_UART_Init(mic32_hal_uart *huart)
{
    HAL_StatusTypeDef error_code = HAL_OK;

    if (huart == NULL || huart->Bodreit < 16)
    {
        return HAL_ERROR;
    }

    /* Выключение модуля UART */
    HAL_UART_Disable(huart);

    huart->Instance->CONTROL1 = huart->Init_CR1;
    huart->Instance->CONTROL2 = huart->Init_CR2;
    huart->Instance->CONTROL3 = huart->Init_CR3;
    
    #ifdef MIK32_UART_DEBUG
    xprintf("uart_Init\n");
    #endif
    
    huart->Instance->RXDATA = 0;
    huart->Instance->TXDATA = 0;

    HAL_UART_ClearError(huart);
    AL_UART_Enable(huart);

    uint8_t ready;
    uint32_t flags;

    do
    {
        flags = huart->Instance->FLAGS;
        ready = 1;
        if(huart->Instance->CONTROL1 & UART_CONTROL1_RE_M)
        {
            ready = ready && ((flags & UART_FLAGS_REACK_M) != 0);
        }
        if(huart->Instance->CONTROL1 & UART_CONTROL1_TE_M)
        {
            ready = ready && ((flags & UART_FLAGS_TEACK_M) != 0);
        }
    }
    while (!ready);
    
    return error_code;
}

HAL_StatusTypeDef HAL_UART_WRITE(mic32_hal_uart *huart, char byte)
{
    while (huart->Instance->FLAGS)
    {
        /* code */
    }
    
}