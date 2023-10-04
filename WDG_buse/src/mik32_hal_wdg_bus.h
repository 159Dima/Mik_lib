
#define MIK32_HAL_WDG_BUS
#ifdef MIK32_HAL_WDG_BUS



#include "wdt_bus.h"
#include "mcu32_memory_map.h"
#include "power_manager.h"
#include "mik32_hal_def.h"
#include "stddef.h"

#define INT_ALL 0xffffffff
////////////одинаковая с wdg
typedef enum{
    OSC32M,
    HSI32M,
    OSC32K,
    HSI32K
}WDT_Clocks;
//////////////////////////////

typedef enum{
    EEPROM_BUS = (1 << WDT_BUS_EEPROM_S),
    DMA_BUS    = (1 << WDT_BUS_DOM3_S  ), 
    SPIFI_BUS  = (1 << WDT_BUS_SPIFI_S )
}Peripheral_Device_Bus;

typedef struct{
    uint16_t takt;
    uint32_t interups;
    Peripheral_Device_Bus bus;
}WDG_Buse_InitTypeDef;

HAL_StatusTypeDef HAL_WDG_Bus_Init(WDG_Buse_InitTypeDef *WDG_Bus);




#endif