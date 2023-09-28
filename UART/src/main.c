#include <mcu32_memory_map.h>
#include <power_manager.h>
#include "mik32_hal_gpio.h"
#include "mik32_hal_uart.h"
#include "mik32_hal_pad_config.h"
#include "mik32_hal_spi.h"
#include "uart_lib.h"

mic32_hal_uart uart;

void SystemClock_Config(void);

void Uart_init(void)
{
    uart.Instance = UART_0;
    uart.Init_CR1 = UART_CONTROL1_M_8BIT_M| UART_CONTROL1_RE_M| UART_CONTROL1_TE_M;
    uart.Init_CR2 = 0;
    uart.Init_CR3 = 0;

    uart.Bodreit = 3333;
    HAL_UART_Ini(&uart);
    // uart.Init_CR1.UartInterrupt = UART_INTERRUPT_OFF;
    // uart.Init_CR1.TxEnable = TX_ON;
    // uart.Init_CR1.RxEnable = RX_ON;
    // uart.Init_CR1.ParityBitSet = PARITY_BIT;
    // uart.Init_CR1.ParityBitEnable = PARITYBIT_OFF;
    // uart.Init_CR1.DataSize = UART_DATASIZE_8BITS;

    // uart.Init_CR2.DataPolarity = NORMAL;
    // uart.Init_CR2.ExchangeRegister = ParityBit_OFF;
    // uart.Init_CR2.InternalLoop = NORMAL;
    // uart.Init_CR2.LastTakt = LASTTAKT_OFF;
    // uart.Init_CR2.ManagingOrder = START_0_BIT;
    // uart.Init_CR2.PhaseControlClock = FRONT;
    // uart.Init_CR2.PolarityControlClock = OUT_TRANSACTION_0;
    // uart.Init_CR2.RxPolarity = NORMAL;
    // uart.Init_CR2.StopBit = STOP_BIT_1;
    // uart.Init_CR2.SynchronMode = SYNCHRON_OFF;
    // uart.Init_CR2.TxPolarity = NORMAL;
    // uart.Init_CR2.UartInterrupt = UART_INTERRUPT_OFF;

    // uart.Init_CR3.Cts = RST_OFF;
    // uart.Init_CR3.DmaRrq = DMA_RRQ_OFF;
    // uart.Init_CR3.DmaTrq = DMA_TRQ_OFF;
    // uart.Init_CR3.ReactOverflow = 0;
    // uart.Init_CR3.Reset = RST_OFF;
    // uart.Init_CR3.SetBeak = NORMAL;
    // uart.Init_CR3.SetMod = DUPLEX;
    // uart.Init_CR3.UartInterrupt = UART_INTERRUPT_OFF;
}


int main()
{
    SystemClock_Config(); 
}

void SystemClock_Config(void)
{
    PM->CLK_APB_M_SET |= PM_CLOCK_PAD_CONFIG_M | PM_CLOCK_WU_M | PM_CLOCK_PM_M;
    PM->CLK_APB_P_SET |= PM_CLOCK_UART_0_M;
}





