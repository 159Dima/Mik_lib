#include "mik32_hal_wdg.h"

uint8_t Wdt_enabled()
{
    if (WDT->Sta & WDT_STA_ENABLED_M) return 1;
    else return 0;
}

uint8_t Wdt_loading()
{
    if (WDT->Sta & WDT_STA_LOADING_M) return 1;
    else return 0;
}

uint8_t Wdt_reset_flag()
{
    if (WDT->Sta & WDT_STA_RST_FLAG_M) return 1;
    else return 0;
}

uint16_t WDT_time()
{
    return WDT->Con & 0xFFF;
}

void _Wdt_stop()
{
    WDT->Key = WDT_KEY_UNLOCK;
    WDT->Key = WDT_KEY_STOP;    
}

void _Wdt_start()
{
    WDT->Key = WDT_KEY_UNLOCK;
    WDT->Key = WDT_KEY_START;
}

uint16_t _Millis_in_clock(WDG_InitTypeDef *WDG)
{
    uint32_t clck;

    clck = (WDG->Clock < 2) ? CLOCK32M : CLOCK32K;
    uint8_t pres = 1;

    for(uint8_t i = 0 ; i < WDG->Prescaler; i++)
    {
        if (i < 2)
        {
            pres = pres*2;
        }
        else{
            pres = pres*4;
        }
    }

    float tick = 4095 - ((clck/(pres))*WDG->Reload)/1000;
    if (tick > 4095 || tick == 0) return 0;
    return tick;
}

HAL_StatusTypeDef HAL_WDG_Init(WDG_InitTypeDef *WDG)
{
    
    if(WDG == NULL){
        return HAL_ERROR;
    }

    // переводим время в такты
    uint16_t tact = _Millis_in_clock(WDG);
    if(tact == 0) return HAL_ERROR;

    // подключаем тактирование wdg
    PM->WDT_CLK_MUX = WDG->Clock;

    _Wdt_stop();

    WDT->Key = WDT_KEY_UNLOCK;
    WDT->Con = (WDG->Prescaler<<WDT_CON_PRESCALE_S) | WDT_CON_PRELOAD(tact);

    //ждем пока значания запишуться
    while(Wdt_loading());
    
    _Wdt_start();

    //проверяем включился ли таймер
    if(!Wdt_enabled())return HAL_ERROR;

    
    return HAL_OK;
}

HAL_StatusTypeDef HAL_IWDG_Refresh()
{
    _Wdt_start();
    uint8_t timeout = 0; 
    while(++ timeout < MAX_TIME_LOAD){
        if(!Wdt_loading())
        {
            return HAL_OK;
        }
    }
    return HAL_ERROR;
}



