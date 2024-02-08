#ifndef GPIO_X_H
#define GPIO_X_H

#include "CfgMcalDio.hpp"
#include "CfgSwcServiceOs.hpp"

extern void     GPIO_CanInit(void);
extern void     GPIO_DeInit(void);
extern void     GPIO_CanStandby(uint8 ucStb);
extern void     GPIO_CanEnable(uint8 ucEn);
extern void     GPIO_CanInterrupt(uint8 ucVal);
extern void     GPIO_TjaErrInterrupt(uint8 ucVal);
extern uint16   GPIO_input_read(Type_McalDio_eName PortPin);
extern void     GPIO_output_on(Type_McalDio_eName PortPin);
extern void     McalDio_vInitInput     (Type_McalDio_eName leNamePin); //TBD: Remove
extern void     McalDio_vInitOutput    (Type_McalDio_eName leNamePin); //TBD: Remove
extern void     McalDio_vInitOutputOff (Type_McalDio_eName leNamePin); //TBD: Remove
extern void     TP3(uint8 ucSet);
extern void     TP2(uint8 ucSet);
extern void     TP1(uint8 ucSet);
extern void     TP0(uint8 ucSet);
extern uint8    ucGetRF_IRQ_ATA(void);
extern boolean  intMcalDio_bIsFrequency433KHz(void);

#endif
