#ifdef __cplusplus
extern "C"
{
#endif

#include "McalDio.hpp"

enum AGPIO_Name {   AGPIO_AP0
   ,  									AGPIO_AP1
   ,  									AGPIO_AP2
   ,  									AGPIO_AP3
   ,  									AGPIO_AP4
   ,  									AGPIO_AP5
   ,  									AGPIO_AP6
   ,  									AGPIO_AP7
   ,  									AGPIO_AP8
   ,  									AGPIO_AP9
                                };

struct GPIO_pin {
    enum GPIO_Name Name;
    uint16 PinNumber;
    volatile uint16 * PMC_Reg;
    volatile uint16 * PM_Reg;
    volatile const uint16 * PPR_Reg;
    volatile uint16 * PIBC_Reg;
    volatile uint16 * P_Reg;
};

struct AGPIO_pin {
    enum AGPIO_Name Name;
    uint16 PinNumber;
    volatile uint16 * APM_Reg;
    volatile const uint16 * APPR_Reg;
    volatile uint16 * APIBC_Reg;
    volatile uint16 * AP_Reg;
};

void GPIO_AtaInterrupt(uint8 ucVal);
void PWR_ATA_P10_14_on(void);
void PWR_ATA_P10_14_off(void);
void PWR_ATA(uint8 ucSet);
void SPI_CLK(uint8 ucSet);
void SPI_MOSI(uint8 ucSet);
void AGPIO_init_output(enum AGPIO_Name PortPin);
void ClearKplAPort(void);
void APort0(uint8 ucSet);
void APort1(uint8 ucSet);
void APort2(uint8 ucSet);
void APort3(uint8 ucSet);
void APort4(uint8 ucSet);
void APort5(uint8 ucSet);
void APort6(uint8 ucSet);
void APort7(uint8 ucSet);

uint8 ucGetRF_TP3(void);
uint8 ucGetRF_TP2(void);
uint8 ucGetRF_TP1(void);
uint8 ucGetRF_TP0(void);

void Set8Bit2APort(uint8);
void LCD_E(uint8);
void LCD_RS(uint8);
void LCD_RW(uint8 ucSet);

static void GPIO_init_output(enum GPIO_Name PortPin);
static void GPIO_init_input(enum GPIO_Name PortPin);
static void GPIO_init_RF_Freq_Pin(void);
static void GPIO_init_TJA_ERR_Pin(void);

#include "dr7f701013.dvf.hpp"
#include "version.hpp"

static const struct GPIO_pin GPIO_List [] = {
   {GPIO_LED1      ,3u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_LCD_E     ,6u,&PMC8 ,&PM8 ,&PPR8, &PIBC8, &P8}
   ,  {GPIO_LCD_RW    ,5u,&PMC8 ,&PM8 ,&PPR8, &PIBC8, &P8}
   ,  {GPIO_LCD_RS    ,4u,&PMC8 ,&PM8 ,&PPR8, &PIBC8, &P8}
   ,  {GPIO_RES_OUT   ,0u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0}
   ,  {GPIO_DIN       ,1u,&PMC8 ,&PM8 ,&PPR8, &PIBC8, &P8}
   ,  {GPIO_SELDP0    ,4u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0}
   ,  {GPIO_SELDP1    ,5u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0}
   ,  {GPIO_SELDP2    ,6u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0}
   ,  {GPIO_INTP      ,9u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0}
   ,  {GPIO_EN_TJA    ,1u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0 }
   ,  {GPIO_ERR_TJA   ,2u,&PMC0 ,&PM0 ,&PPR0, &PIBC0, &P0 }
   ,  {GPIO_STB_TJA   ,3u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_CS_ATA    ,5u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_SPI_MOSI  ,6u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_SPI_CLK   ,7u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_SPI_MISO  ,8u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_CHK_FREQ  ,9u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_PWR_ATA   ,14u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_PWR_B1ATA ,13u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_PWR_B2ATA ,12u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_IRQ_ATA   ,11u,&PMC10,&PM10,&PPR10,&PIBC10,&P10}
   ,  {GPIO_TP0       ,0u ,&PMC9, &PM9 ,&PPR9, &PIBC9, &P9}
   ,  {GPIO_TP1       ,1u ,&PMC9, &PM9 ,&PPR9, &PIBC9, &P9}
   ,  {GPIO_TP2       ,2u ,&PMC9, &PM9 ,&PPR9, &PIBC9, &P9}
   ,  {GPIO_TP3       ,3u ,&PMC9, &PM9 ,&PPR9, &PIBC9, &P9}
};

void McalDio_CanEnable(uint8 ucEn){
  if(ucEn == 0){
    P0 &= ~(1u<<1);
  }
  else{
    P0 |= 1u<<1;
  }
}

void McalDio_CanStandby(uint8 ucStb){
  if(ucStb == 1){
    P10 &= ~(1u<<3);
  }
  else{
    P10 |= 1u<<3;
  }
}

void McalDio_InitFunction(void){
#ifdef DEBUG_PORTS_ACTIVE

  GPIO_init_output(GPIO_TP0);
  GPIO_init_output(GPIO_TP1);
  GPIO_init_output(GPIO_TP2);
  GPIO_init_output(GPIO_TP3);
  TP3(1);
  TP0(0);
#else
  GPIO_init_input(GPIO_TP0);
  GPIO_init_input(GPIO_TP1);
  GPIO_init_input(GPIO_TP2);
  GPIO_init_input(GPIO_TP3);
#endif

  GPIO_init_RF_Freq_Pin();
  GPIO_init_TJA_ERR_Pin();
  GPIO_init_output(GPIO_STB_TJA);
  GPIO_init_output(GPIO_EN_TJA);
  McalDio_output_off(GPIO_STB_TJA);
  McalDio_output_off(GPIO_EN_TJA);
}

void McalDio_CanInitFunction(void){
  PMC0 &= ~(1u<<1);
  PM0 &= ~(1u<<1);
  P0 &= ~(1u<<1);

  PMC10 &= ~ (1u<<3);
  PM10 &= ~ (1u<<3);
  P10 &= ~(1u<<3);

  PFCAE10 &= 0xFFFEU;
  PFCE10  &= 0xFFFEU;
  PFC10   |= 0x0001U;
  PM10    |= 0x0001U;
  PMC10   |= 0x0001U;

  PFCAE10 &= 0xFFFDU;
  PFCE10  &= 0xFFFDU;
  PFC10   |= 0x0002U;
  P10     |= 0x0002U;
  PM10    &= 0xFFFDU;
  PMC10   |= 0x0002U;
}

uint8 McalDio_GetFrequencySetting(void){
  uint8 ucRet;

  if(McalDio_input_read(GPIO_CHK_FREQ) == TRUE){
    ucRet = cFREQUENCY_433;
  }
  else{
    ucRet = cFREQUENCY_315;
  }
  return ucRet;
}

static void GPIO_init_output(enum GPIO_Name PortPin){
  *(GPIO_List[PortPin].P_Reg)   &= ~(1u << GPIO_List[PortPin].PinNumber);
  *(GPIO_List[PortPin].PM_Reg)  &= ~(1u << GPIO_List[PortPin].PinNumber);
  *(GPIO_List[PortPin].PMC_Reg) &= ~(1u << GPIO_List[PortPin].PinNumber);
}

static void GPIO_init_input(enum GPIO_Name PortPin){
  *GPIO_List[PortPin].PM_Reg   |= (1u << GPIO_List[PortPin].PinNumber);
  *GPIO_List[PortPin].PIBC_Reg |= (1u << GPIO_List[PortPin].PinNumber);
  *GPIO_List[PortPin].PMC_Reg  &= ~(1u << GPIO_List[PortPin].PinNumber);
}

static void GPIO_init_RF_Freq_Pin(void){
  PM10  |=(1<<9);
  PIBC10|=(1<<9);
  PMC10 &=~(1<<9);
  PU10 |=(1<<9);
}

static void GPIO_init_TJA_ERR_Pin(void){
		PM0 |= (1 << 2);
		PIBC0 |= (1 << 2);
		PMC0 &= ~(1 << 2);
		PU0 |= (1 << 2);
}

uint16 McalDio_input_read(enum GPIO_Name PortPin){
  return (((*GPIO_List[PortPin].PPR_Reg) >> GPIO_List[PortPin].PinNumber)& 0x0001);
}

void McalDio_output_off(enum GPIO_Name PortPin){
    *GPIO_List[PortPin].P_Reg &= ~(1u << GPIO_List[PortPin].PinNumber);
}

void McalDio_output_on(enum GPIO_Name PortPin){
    *GPIO_List[PortPin].P_Reg |= (1u << GPIO_List[PortPin].PinNumber);
}

void TP3(uint8 ucSet){
  if(ucSet == 1){
    P9|=(1<<3);
  }
  else{
    P9&=~(1<<3);
  }
}

void TP2(uint8 ucSet){
  if(ucSet == 1){
    P9|=(1<<2);
  }
  else{
    P9&=~(1<<2);
  }
}

void TP1(uint8 ucSet){
  if(ucSet == 1){
    P9|=(1<<1);
  }
  else{
    P9&=~(1<<1);
  }
}

void TP0(uint8 ucSet){
  if(ucSet == 1){
    P9|=(1<<0);
  }
  else{
    P9&=~(1<<0);
  }
}

#ifdef __cplusplus
}
#endif
