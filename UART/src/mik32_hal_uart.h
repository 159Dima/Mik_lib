#ifndef MIC32_HAL_UATR
#define MIC32_HAL_UATR

#include "mcu32_memory_map.h"
#include "uart.h"
#include "stddef.h"
#include "mik32_hal_def.h"

// #define UART_INTERRUPT_OFF 0

// #define UART_ON 1
// #define UART_OFF 0

// #define RX_ON 1
// #define RX_OFF 0

// #define TX_ON 1
// #define TX_OFF 0

// #define PARITY_BIT 0
// #define ODD_BIT 1

// #define PARITYBIT_ON 1
// #define PARITYBIT_OFF 0

// #define  IDLEIE (1 << 0)
// #define  RXNEIE (1 << 1)
// #define  TCIE   (1 << 2)
// #define  PEIE   (1 << 4)

// #define NORMAL 0
// #define REVERSE 1
// #define WORKAROUND 1
// #define REVERSE 1
// #define BREAK 1;

// #define ParityBit_OFF 0
// #define ParityBit_ON 1

// #define LASTTAKT_OFF 0
// #define LASTTAKT_ON 1

// #define START_0_BIT 0
// #define START_END_BIT 1

// #define FRONT 0
// #define DECLINE 1

// #define OUT_TRANSACTION_0 0
// #define OUT_TRANSACTION_1 1

// #define STOP_BIT_1 0
// #define STOP_BIT_2 1

// #define SYNCHRON_OFF 0
// #define SYNCHRON_ON 1

// #define RST_OFF 0
// #define RSE_TX_NOT_READY 1 

// #define  DMA_RRQ_OFF 0 
// #define  DMA_RRQ_ON 1
// /*   
//    * - <DUPLEX>;
//     * - <HALF_DUPLEX>. 
// */
 
// #define DMA_TRQ_OFF 0
// #define DMA_TRQ_ON 1

// #define RST_OFF 0
// #define RSE_TX_NOT_READY 1

// #define DUPLEX 0
// #define HALF_DUPLEX 1

// typedef enum 
// { 
//     UART_DATASIZE_7BITS = 0,
//     UART_DATASIZE_8BITS = 2,
//     UART_DATASIZE_9BITS = 3
// }DATASIZE;





// typedef struct 
// {
//     /*
//     * Variable: UartEnable
//     * Режим UART (ON/OFF)
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <UART_ON>;
//     * - <UART_OFF>. 
//     *
//     */
//     // uint8_t UartEnable;

//     /*
//     * Variable: RxEnable
//     * Режим Rx (ON/OFF)
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <RX_ON>;
//     * - <RX_OFF>. 
//     *
//     */
//     uint8_t RxEnable;
    
//     /*
//     * Variable: TxEnable
//     * Режим Tx (ON/OFF)
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <TX_ON>;
//     * - <TX_OFF>. 
//     *
//     */
//     uint8_t TxEnable;

//     /*
//     * Variable: UartInterrupt
//     * включает прирывания ( UartInterrupt |= ()|())
//     * 
//     * Этот параметр принемает значения:
//     * 
//     * прерывания отключены
//     * - <UART_INTERRUPT_OFF>. 
//     * включаем прерывания
//     * - <IDLEIE>;
//     * - <RXNEIE>;
//     * - <TCIE>;
//     * - <PEIE>.
//     * 
//     */
//     uint8_t UartInterrupt;

//     /*
//     * Variable: ParityBitSet
//     * Выбор способа формирования бита четности(бит четности/бит нечетности)
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <PARITY_BIT>;
//     * - <ODD_BIT>.
//     * 
//     */   
//     uint8_t ParityBitSet;

//     /*
//     * Variable: ParityBitEnable
//     * Контроль четности
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <ParityBit_ON>;
//     * - <ParityBit_OFF>. 
//     *
//     */
//     uint8_t ParityBitEnable;

//     /*
//     * Variable: DataSize
//     * Длина передаваемой посылки
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <UART_DATASIZE_7BITS>;
//     * - <UART_DATASIZE_8BITS>;
//     * - <UART_DATASIZE_9BITS>.
//     * 
//     */
//     uint8_t DataSize;


// }UART_Init_CR1;

// typedef struct 
// {   
//     /*
//     * Variable: UartInterrupt
//     * включает прирывания ( UartInterrupt |= ()|())
//     * 
//     * Этот параметр принемает значения:
//     * 
//     * прерывания отключены
//     * - <UART_INTERRUPT_OFF>. 
//     * включаем прерывания
//     * - <LBDIE>.
//     * 
//     */
//     uint8_t UartInterrupt;
    
//     /*
//     * Variable: LastTakt
//     * Управление последним тактовым импульсом
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <LASTTAKT_ON>;
//     * - <LASTTAKT_OFF>. 
//     *
//     */
//     uint8_t LastTakt;

//     /*
//     * Variable: PhaseControlClock
//     * Управление фазой выходного тактового сигнала CK
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <FRONT>;
//     * - <DECLINE>. 
//     *
//     */
//     uint8_t PhaseControlClock;

//     /*
//     * Variable: PolarityControlClock
//     * Управление полярностью выходного тактового сигнала CK
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <OUT_TRANSACTION_0>;
//     * - <OUT_TRANSACTION_1>. 
//     *
//     */
//     uint8_t PolarityControlClock;

//     /*
//     * Variable: SynchronousMode
//     * Управление синхронным режимом
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <SYNCHRON_ON>;
//     * - <SYNCHRON_OFF>. 
//     *
//     */
//     uint8_t SynchronMode;

//     /*
//     * Variable: StopBit
//     * Количество стоп битов для приемника и передатчика
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <1_STOP_BIT>;
//     * - <2_STOP_BIT>. 
//     *
//     */
//     uint8_t StopBit;

//     /*
//     * Variable: InternalLoop
//     * Регистр режима обратной внутренней петли
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <NORMAL>;
//     * - <WORKAROUND>. 
//     *
//     */
//     uint8_t InternalLoop;   

//     /*
//     * Variable: InternalLoop
//     * Регистр отвечает за обмен функциями TX выхода и RX входа
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <NORMAL>;
//     * - <EXCHANGE>. 
//     *
//     */
//     uint8_t  ExchangeRegister;

//     /*
//     * Variable: RxPolarity
//     * Управление полярностью RX входа. Регистр влияет не только на данные, но и на стоп биты, старт биты и тд.
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <NORMAL>;
//     * - <REVERSE>. 
//     *
//     */
//     uint8_t  RxPolarity;

//     /*
//     * Variable: TxPolarity
//     * Управление полярностью TX выхода. Регистр влияет не только на данные, но и на стоп биты, старт биты и тд.
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <NORMAL>;
//     * - <REVERSE>. 
//     *
//     */
//     uint8_t  TxPolarity;

//     /*
//     * Variable: DataPolarity
//     * Управление полярностью принимаемых и передаваемых данных
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <NORMAL>;
//     * - <REVERSE>. 
//     *
//     */
//     uint8_t  DataPolarity;

//     /*
//     * Variable: ManagingOrder
//     * Управление очередностью приема и передачи данных
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <START_0_BIT>;
//     * - <START_END_BIT>. 
//     *
//     */
//     uint8_t  ManagingOrder;


// }UART_Init_CR2;

// typedef struct 
// {
//     /*
//     * Variable: UartInterrupt
//     * Управление прерыванием при обнаружении ошибок приема данных (FE, ORE, NF)
//     * 
//     * Этот параметр принемает значения:
//     * 
//     * прерывания отключены
//     * - <UART_INTERRUPT_OFF>. 
//     * включаем прерывания
//     * - <CTSIE>;
//     * - <EIE>.
//     * 
//     */
//     uint8_t UartInterrupt;    

//     /*
//     * Variable: SetBeak
//     * Переход передатчика в break состояние
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <NORMAL>;
//     * - <BREAK>. 
//     *
//     */
//     uint8_t  SetBeak;   

//     /*
//     * Variable: SetMod
//     * Выбор между полудуплекс-ным и дуплексным режима-ми работы. В полудуплекс-ном режиме RX не исполь-зуется, 
//     * все данные передаются и принимаются через TX. 
//     * При наличии данных на передачу происходит отправка данных в остальное время прием:
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <DUPLEX>;
//     * - <HALF_DUPLEX>. 
//     *
//     */
//     uint8_t  SetMod;

//     /*
//     * Variable: DmaRrq
//     * Управление работой сигнала dma_rrq
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <DMA_RRQ_ON>;
//     * - <DMA_RRQ_OFF>. 
//     *
//     */
//     uint8_t  DmaRrq;

//     /*
//     * Variable: DmaRrq
//     * Управление работой сигнала dma_trq
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <DMA_TRQ_ON>;
//     * - <DMA_TRQ_OFF>. 
//     *
//     */
//     uint8_t  DmaTrq;

//     /*
//     * Variable: Reset
//     * Управление выходным сигналом RTS:
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <RST_OFF>;
//     * - <RSE_TX_NOT_READY>. 
//     *
//     */
//     uint8_t  Reset;   

//     /*
//     * Variable: Cts
//     * Выбор реакции на входной сигнал CTS
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - <RST_OFF>;
//     * - <RSE_TX_NOT_READY>. 
//     *
//     */
//     uint8_t  Cts; 

//     /*
//     * Variable: Cts
//     * Выбор реакции на переполнение
//     * 
//     * Этот параметр должен быть одним из значений:
//     * 
//     * - 0 – при переполнении взво-дится флаг ошибки (ORE), новые данные не записываются.
//     * - 1 – флаг переполнения не взводится, данные перезапи-сываются. 
//     *
//     */
//     uint8_t  ReactOverflow;            


// }UART_Init_CR3;

// typedef struct 
// {
//     UART_TypeDef *Instance;

//     UART_Init_CR1 Init_CR1;

//     UART_Init_CR2 Init_CR2;

//     UART_Init_CR3 Init_CR3;

//     uint32_t Bodreit;

// }mic32_hal_uart;

typedef struct 
{
    UART_TypeDef *Instance;

    uint32_t Init_CR1;

    uint32_t Init_CR2;

    uint32_t Init_CR3;

    uint32_t Bodreit;

}mic32_hal_uart;


HAL_StatusTypeDef HAL_UART_Init(mic32_hal_uart *hspi);




































































#endif