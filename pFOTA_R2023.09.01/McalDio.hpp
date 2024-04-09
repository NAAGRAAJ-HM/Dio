#ifndef GPIO_X_H
#define GPIO_X_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "Std_Types.hpp"

#define c_IRQ_ACTIVE       1
#define c_IRQ_NOT_ACTIVE   0

enum GPIO_Name{
   GPIO_LED1=0
   ,  GPIO_LCD_E
   ,  GPIO_LCD_RW
   ,  GPIO_LCD_RS
   ,  GPIO_RES_OUT
   ,  GPIO_DIN
   ,  GPIO_SELDP0
   ,  GPIO_SELDP1
   ,  GPIO_SELDP2
   ,  GPIO_INTP
   ,  GPIO_EN_TJA
   ,  GPIO_ERR_TJA
   ,  GPIO_STB_TJA
   ,  GPIO_CS_ATA
   ,  GPIO_SPI_MOSI
   ,  GPIO_SPI_CLK
   ,  GPIO_SPI_MISO
   ,  GPIO_CHK_FREQ
   ,  GPIO_PWR_ATA
   ,  GPIO_PWR_B1ATA
   ,  GPIO_PWR_B2ATA
   ,  GPIO_IRQ_ATA
   ,  GPIO_TP0
   ,  GPIO_TP1
   ,  GPIO_TP2
   ,  GPIO_TP3
};

#define cFREQUENCY_433 1
#define cFREQUENCY_315 2

extern void     McalDio_InitFunction(void);
extern void     McalDio_CanInitFunction(void);
extern void     McalDio_DeInitFunction(void);
extern void     McalDio_CanStandby(uint8 ucStb);
extern void     McalDio_CanEnable(uint8 ucEn);
extern void     McalDio_CanInterrupt(uint8 ucVal);
extern void     McalDio_TjaErrInterrupt(uint8 ucVal);
extern uint8    McalDio_GetFrequencySetting(void);
extern uint16   McalDio_input_read(enum GPIO_Name PortPin);
extern void     McalDio_output_off(enum GPIO_Name PortPin);
extern void     McalDio_output_on(enum GPIO_Name PortPin);
extern void     McalDio_ChipSelectAta(uint8 ucSet);
extern void TP3(uint8 ucSet);
extern void TP2(uint8 ucSet);
extern void TP1(uint8 ucSet);
extern void TP0(uint8 ucSet);
extern uint8 ucGetRF_IRQ_ATA(void);
extern void FastPWR_3Pin4_ATA(uint8 ucSet);

#ifdef __cplusplus
}
#endif
#endif
