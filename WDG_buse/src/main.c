#include "mcu32_memory_map.h"
#include "mik32_hal_gpio.h"
#include "mik32_hal_pad_config.h"
#include "mik32_hal_rcc.h"

#include "mik32_hal_wdg_bus.h"


#include "uart_lib.h"
#include "xprintf.h"

WDG_Buse_InitTypeDef WDG_Bus;

void SystemClock_Config(void);

void WDG_init(){
WDG_Bus.takt = 7;
WDG_Bus.interups = INT_ALL;
WDG_Bus.bus = EEPROM_BUS|DMA_BUS|SPIFI_BUS;
HAL_WDG_Bus_Init(&WDG_Bus);
}

int main()
{
    SystemClock_Config();
    WDG_init();

    while(1)
    {

    }

    return 0;
}



void SystemClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  PeriphClkInit.PMClockAHB = PMCLOCKAHB_DEFAULT; 
  PeriphClkInit.PMClockAPB_M = PMCLOCKAPB_M_DEFAULT | PM_CLOCK_WU_M | PM_CLOCK_PAD_CONFIG_M;     
  PeriphClkInit.PMClockAPB_P = PM_CLOCK_GPIO_1_M | PMCLOCKAPB_P_DEFAULT | PM_CLOCK_UART_0_M | PM_CLOCK_ANALOG_REG_M | PM_CLOCK_WDT_M;     
  HAL_RCC_ClockConfig(&PeriphClkInit);
}