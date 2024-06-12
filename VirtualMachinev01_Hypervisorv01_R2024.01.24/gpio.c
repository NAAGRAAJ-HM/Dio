#include "Std_Types.hpp"

#include "infMcalDioMcalAta.hpp"

#include "device.hpp"
#include "gpio.hpp"

void GPIO_CanEnable(uint8 ucEn){
   if(0 == ucEn){P0 &= ~(1u<<1);}
   else         {P0 |=   1u<<1;}
}

void GPIO_CanStandby(uint8 ucStb){
   if(1 == ucStb){P10 &= ~(1u<<3);}
   else          {P10 |=   1u<<3;}
}

void GPIO_CanInit(void){
   PMC0    &= ~(1u<<1);
   PM0     &= ~(1u<<1);
   P0      &= ~(1u<<1);

   PMC10   &= ~ (1u<<3);
   PM10    &= ~ (1u<<3);
   P10     &= ~(1u<<3);

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

   FCLA0CTL0_INTPL = 0x1;

   TBP0     = 1;
   RFP0     = 0;
   MKP0     = 1;
}

void GPIO_DeInit(void){
   McalDio_vInitOutputOff(GPIO_CS_ATA);
   PFC10   &= ~(1<<6);
   PFCE10  &= ~(1<<6);
   PFCAE10 &= ~(1<<6);
   PMC10   &= ~(1<<6);
   PIPC10  &= ~(1<<6);
   PM10    &= ~(1<<6);
   McalDio_vInitOutput(GPIO_SPI_MOSI);
   PFC10   &= ~(1<<7);
   PFCE10  &= ~(1<<7);
   PFCAE10 &= ~(1<<7);
   PMC10   &= ~(1<<7);
   PIPC10  &= ~(1<<7);
   PM10    &= ~(1<<7);
   McalDio_vInitOutput(GPIO_SPI_CLK);
   PFC10   &= ~(1<<9);
   PFCE10  &= ~(1<<9);
   PFCAE10 &= ~(1<<9);
   PMC10   &= ~(1<<9);
   PIPC10  &= ~(1<<9);
   PM10    &= ~(1<<9);
   McalDio_vInitOutput(GPIO_CHK_FREQ);
   McalDio_vInitOutputOff(GPIO_CHK_FREQ);
   PFC10   &= ~(1<<0);
   PFCE10  &= ~(1<<0);
   PFCAE10 &= ~(1<<0);
   PMC10   &= ~(1<<0);
   PIPC10  &= ~(1<<0);
   PM10    |=  (1<<0);
   PFC10   &= ~(1<<1);
   PFCE10  &= ~(1<<1);
   PFCAE10 &= ~(1<<1);
   PMC10   &= ~(1<<1);
   PIPC10  &= ~(1<<1);
   PM10    |=  (1<<1);
   McalDio_vInitInput(GPIO_TP0);
   McalDio_vInitInput(GPIO_TP1);
   McalDio_vInitInput(GPIO_TP2);
   McalDio_vInitInput(GPIO_TP3);
}

boolean intMcalDio_bIsFrequency433KHz(void){
   return(
      (FALSE != GPIO_input_read(GPIO_CHK_FREQ))
      ?  TRUE
      :  FALSE
   );
}

uint16 GPIO_input_read(Type_McalDio_eName lePinName){
  return (((*CfgMcalDio_castListInfoPins[lePinName].PPR_Reg) >> CfgMcalDio_castListInfoPins[lePinName].PinNumber)& 0x0001);
}

void AMcalDio_vInitOutput(Type_CfgMcalDio_ePinNames lePinName){
  *(ACfgMcalDio_castListPins[lePinName].AP_Reg)   &= ~(1u << ACfgMcalDio_castListPins[lePinName].PinNumber);
  *(ACfgMcalDio_castListPins[lePinName].APM_Reg)  &= ~(1u << ACfgMcalDio_castListPins[lePinName].PinNumber);
}

void GPIO_CanInterrupt(uint8 ucVal){
   PFCAE10 &= ~(1<<0);
   PFCE10  &= ~(1<<0);
   PFC10   |=  (1<<0);

   PIBC10  &= ~(1<<0);
   PMC10   |=  (1<<0);
   PM10    |=  (1<<0);

   FCLA0CTL0_INTPL = 0x2;

   TBP0=1;
   RFP0=0;

   if(c_IRQ_ACTIVE == ucVal){MKP0 = L;}
   else                     {MKP0 = H;}
}

void GPIO_TjaErrInterrupt(uint8 ucVal){
   PFCAE0 |=  (1<<2);
   PFCE0  &= ~(1<<2);
   PFC0   &= ~(1<<2);
   PIBC0  &= ~(1<<2);
   PMC0   |=  (1<<2);
   PM0    |=  (1<<2);
   FCLA0CTL1_INTPL = 0x2;
   TBP1=1;
   RFP1=0;

   if(c_IRQ_ACTIVE == ucVal){MKP1 = L;}
   else                     {MKP1 = H;}
}

void GPIO_output_on(Type_McalDio_eName PortPin){
    *CfgMcalDio_castListInfoPins[PortPin].P_Reg |= (1u << CfgMcalDio_castListInfoPins[PortPin].PinNumber);
}

void GPIO_ChipSelectAta(uint8 ucSet){
   if(1 == ucSet){P10 &= ~(1<<5);}
   else          {P10 |=  (1<<5);}
}

void FastPWR_3Pin4_ATA(uint8 ucSet){
   PPCMD10|=0x000000FF;
   if(1 == ucSet){PDSC10 |=  (7<<12); P10 |=  (7<<12);}
   else          {PDSC10 &= ~(7<<12); P10 &= ~(7<<12);}
}

uint8 ucGetRF_IRQ_ATA(){
   return((uint8)((P10 >>10) & 0x01));
}

uint8 intMcalDioMcalAta_u8GetLevelPortPinIrq(){
   return GPIO_input_read(GPIO_IRQ_ATA);
}

uint8 GPIO_GetAtaIrqPendingFlag(void){
   return (uint8)(RFP11);
}

void TP3(uint8 ucSet){
   if(1 == ucSet){P9 |=  (1<<3);}
   else          {P9 &= ~(1<<3);}
}

void TP2(uint8 ucSet){
   if(1 == ucSet){P9 |=  (1<<2);}
   else          {P9 &= ~(1<<2);}
}

void TP1(uint8 ucSet){
   if(1 == ucSet){P9 |=  (1<<1);}
   else          {P9 &= ~(1<<1);}
}

void TP0(uint8 ucSet){
   if(1 == ucSet){P9 |=  (1<<0);}
   else          {P9 &= ~(1<<0);}
}
