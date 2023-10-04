#include "mcu32_memory_map.h"
#include "mik32_hal_gpio.h"
#include "mik32_hal_pad_config.h"

#include "mik32_hal_rcc.h"
#include "mik32_hal_timer16.h"
#include "mik32_hal_scr1_timer.h"

#include "mik32_hal_wdt.h"

#include "uart_lib.h"
#include "xprintf.h"

Timer16_HandleTypeDef htimer16_1;
SCR1_TIMER_HandleTypeDef hscr1_timer;
WDT_InitTypeDef wdt;

static void Scr1_Timer_Init(void);

void SystemClock_Config(void);


void WDT_Init(){
  wdt.Clock = OSC32K;
  wdt.Prescaler = PRESCALE_16;
  wdt.Reload = 1000;
  HAL_WDT_Init(&wdt);
}
void WDT_NEW_Time(){
  wdt.Reload = 500;
  HAL_WDT_Init(&wdt); 
  HAL_WDT_Start();
}

int main()
{    

  SystemClock_Config();
  Scr1_Timer_Init();
  WDT_Init();

  UART_Init(UART_0, 3333, UART_CONTROL1_TE_M | UART_CONTROL1_M_8BIT_M, 0, 0);
  
  xprintf("\nstart 1\n"); 
  HAL_WDT_Start(); 
  HAL_DelayMs(&hscr1_timer, 1000);
  HAL_WDT_Refresh();
  xprintf("stop 1");


  xprintf("\nstart 2\n"); 
  WDT_NEW_Time();
  HAL_DelayMs(&hscr1_timer, 500);
  HAL_WDT_Refresh();
  xprintf("stop 2\n");

  HAL_WDT_Stop();

  while (1)
  {   
  HAL_DelayMs(&hscr1_timer, 1050);
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


