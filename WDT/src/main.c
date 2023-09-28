#include "mcu32_memory_map.h"
#include "mik32_hal_gpio.h"
#include "mik32_hal_pad_config.h"

#include "mik32_hal_rcc.h"
#include "mik32_hal_timer16.h"
#include "mik32_hal_scr1_timer.h"

#include "mik32_hal_wdg.h"

#include "uart_lib.h"
#include "xprintf.h"

#define PIN_LED2 PORT1_3 
Timer16_HandleTypeDef htimer16_1;

SCR1_TIMER_HandleTypeDef hscr1_timer;

WDG_InitTypeDef wdg;

static void Scr1_Timer_Init(void);

void SystemClock_Config(void);

void delay(uint32_t DelayTime)
{
  for (volatile int i = 0; i < DelayTime; i++);
}

void WDT_option()
{
  wdg.Clock = OSC32K;
  wdg.Prescaler = PRESCALE_16;
  wdg.Reload = 1000;

  HAL_WDG_Init(&wdg);
}

int main()
{    

    SystemClock_Config();

    UART_Init(UART_0, 3333, UART_CONTROL1_TE_M | UART_CONTROL1_M_8BIT_M, 0, 0);
    
    HAL_PadConfig_PinMode(PIN_LED2, PIN_MODE1);
    HAL_GPIO_PinDirection(PIN_LED2, GPIO_PIN_OUTPUT);

    //Wdt_init(OSC32K, PRESCALE_16, 1000);
    //xprintf("%d\n", Millis_in_clock(OSC32K, PRESCALE_16, 1000));

    
    Scr1_Timer_Init();
    HAL_GPIO_PinWrite(PIN_LED2, GPIO_PIN_HIGH);
    xprintf("start\n");
    WDT_option();    
    HAL_DelayMs(&hscr1_timer, 1000);
    HAL_IWDG_Refresh();
    xprintf("%d\n", WDT_time());

    
    
    while (1)
    {   
    HAL_DelayMs(&hscr1_timer, 900);
    HAL_IWDG_Refresh();
    }
       
}

void SystemClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  PeriphClkInit.PMClockAHB = PMCLOCKAHB_DEFAULT; 
  PeriphClkInit.PMClockAPB_M = PMCLOCKAPB_M_DEFAULT | PM_CLOCK_WU_M | PM_CLOCK_PAD_CONFIG_M;     
  PeriphClkInit.PMClockAPB_P = PM_CLOCK_GPIO_1_M | PMCLOCKAPB_P_DEFAULT | PM_CLOCK_UART_0_M | PM_CLOCK_ANALOG_REG_M | PM_CLOCK_WDT_M;     
  HAL_RCC_ClockConfig(&PeriphClkInit);
}

static void Scr1_Timer_Init(void)
{
    hscr1_timer.Instance = SCR1_TIMER;

    hscr1_timer.ClockSource = SCR1_TIMER_CLKSRC_INTERNAL;    /* Источник тактирования */
    hscr1_timer.Divider = 0;       /* Делитель частоты 10-битное число */

    HAL_SCR1_Timer_Init(&hscr1_timer);
}


