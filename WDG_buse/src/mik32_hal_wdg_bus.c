#include "mik32_hal_wdg_bus.h"

HAL_StatusTypeDef HAL_WDG_Bus_Init(WDG_Buse_InitTypeDef *WDG_Bus){
    if(WDG_Bus == NULL){
        return HAL_ERROR;
    }
    WDT_BUS->COUNTER = WDG_Bus->takt;
    WDT_BUS->INT_CLEAR = WDG_Bus->interups;
    WDT_BUS->ENABLE = WDG_Bus->bus;
    return HAL_OK;
}