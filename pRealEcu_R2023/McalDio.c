/******************************************************************************/
/* File   : McalDio.c                                                         */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "infMcalDioSwcApplEcuM.h"

#include "uC_Dio.h"
#include "CfgMcalDio.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
#ifndef ReSim
#else
volatile uint16 P0;
volatile uint16 P8;
volatile uint16 P9;
volatile uint16 P10;
volatile uint16 PPR0;
volatile uint16 PPR8;
volatile uint16 PPR9;
volatile uint16 PPR10;
volatile uint16 PM0;
volatile uint16 PM8;
volatile uint16 PM9;
volatile uint16 PM10;
volatile uint16 PMC0;
volatile uint16 PMC8;
volatile uint16 PMC9;
volatile uint16 PMC10;
volatile uint16 PIBC0;
volatile uint16 PIBC8;
volatile uint16 PIBC9;
volatile uint16 PIBC10;
volatile uint16 PU0;
#endif

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
void McalDio_vInitInput(Type_McalDio_eName leNamePin){
   const Type_McalDio_stPin* lptrstPin = &CfgMcalDio_castListPins[leNamePin];
         uint16              lu16Mask  = 1u << lptrstPin->PinNumber;

  *lptrstPin->PM_Reg   |=  lu16Mask;
  *lptrstPin->PIBC_Reg |=  lu16Mask;
  *lptrstPin->PMC_Reg  &= ~lu16Mask;
}

void McalDio_vInitOutput(Type_McalDio_eName leNamePin){
   const Type_McalDio_stPin* lptrstPin = &CfgMcalDio_castListPins[leNamePin];
         uint16              lu16Mask  = 1u << lptrstPin->PinNumber;

  *lptrstPin->P_Reg   &= ~lu16Mask;
  *lptrstPin->PM_Reg  &= ~lu16Mask;
  *lptrstPin->PMC_Reg &= ~lu16Mask;
}

static void McalDio_vInitPinErrTja(void){
   PM0   |=  (1 << 2);
   PIBC0 |=  (1 << 2);
   PMC0  &= ~(1 << 2);
   PU0   |=  (1 << 2);
}

FUNC(void, MCALDIO_CODE) infMcalDioSwcApplEcuM_vInitFunction(void){
   McalDio_vInitOutput(GPIO_TP0);
   McalDio_vInitOutput(GPIO_TP1);
   McalDio_vInitOutput(GPIO_TP2);
   McalDio_vInitOutput(GPIO_TP3);
   McalDio_vInitOutput(GPIO_CS_ATA);
   McalDio_vInitOutput(GPIO_PWR_ATA);
   McalDio_vInitOutput(GPIO_PWR_B1ATA);
   McalDio_vInitOutput(GPIO_PWR_B2ATA);

#if(CfgProject == cL_R2023)
   McalDio_vInitInput(GPIO_ERR_TJA);
#endif

#if(CfgProject == cR_R2023)
   McalDio_vInitPinErrTja();
#endif

   McalDio_vInitOutput(GPIO_STB_TJA);
   McalDio_vInitOutput(GPIO_EN_TJA);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
