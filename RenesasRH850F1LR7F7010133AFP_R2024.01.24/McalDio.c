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
#include "Std_Types.hpp"

#include "infMcalDioMcalAta.hpp"

#include "CfgMcalDio.hpp"
#include "infMcalDioSwcApplEcuM.hpp"

#include "uC_Dio.hpp"
#include "Types_SwcServiceOs.hpp"

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
#if(CfgProject_dSwitchReSim != STD_ON)
#else
volatile       uint16 P0;
volatile       uint16 P8;
volatile       uint16 P9;
volatile       uint16 P10;
volatile const uint16 PPR0;
volatile const uint16 PPR8;
volatile const uint16 PPR9;
volatile const uint16 PPR10;
volatile       uint16 PM0;
volatile       uint16 PM8;
volatile       uint16 PM9;
volatile       uint16 PM10;
volatile       uint16 PMC0;
volatile       uint16 PMC8;
volatile       uint16 PMC9;
volatile       uint16 PMC10;
volatile       uint16 PFC10;
volatile       uint16 PFCE10;
volatile       uint16 PFCAE10;
volatile       uint16 PIBC0;
volatile       uint16 PIBC8;
volatile       uint16 PIBC9;
volatile       uint16 PIBC10;
volatile       uint16 PIPC10;
volatile       uint16 PU0;
volatile       uint16 PU10;
volatile       uint8  FCLA0CTL3_INTPH;
#endif

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
//static void McalDio_vInitInput(Type_McalDio_eName leNamePin){
         void McalDio_vInitInput(Type_McalDio_eName leNamePin){ //TBD: Remove
   const Type_McalDio_stPin* lptrstPin = &CfgMcalDio_castListInfoPins[leNamePin];
         uint16              lu16Mask  = 1u << lptrstPin->PinNumber;

  *lptrstPin->PM_Reg   |=  lu16Mask;
  *lptrstPin->PIBC_Reg |=  lu16Mask;
  *lptrstPin->PMC_Reg  &= ~lu16Mask;
}

//static void McalDio_vInitOutput(Type_McalDio_eName leNamePin){
         void McalDio_vInitOutput(Type_McalDio_eName leNamePin){ //TBD: Remove
   const Type_McalDio_stPin* lptrstPin = &CfgMcalDio_castListInfoPins[leNamePin];
         uint16              lu16Mask  = 1u << lptrstPin->PinNumber;

  *lptrstPin->P_Reg   &= ~lu16Mask;
  *lptrstPin->PM_Reg  &= ~lu16Mask;
  *lptrstPin->PMC_Reg &= ~lu16Mask;
}

void McalDio_vInitOutputOff(Type_McalDio_eName leNamePin){
  *CfgMcalDio_castListInfoPins[leNamePin].P_Reg &= ~(1u << CfgMcalDio_castListInfoPins[leNamePin].PinNumber);
}

static void McalDio_vInitPinErrTja(void){
   PM0   |=  (1 << 2); //TBD: Move to CfgMcalDio
   PIBC0 |=  (1 << 2);
   PMC0  &= ~(1 << 2);
   PU0   |=  (1 << 2);
}

static void McalDio_vInitPinFreqRF(void){
   PM10   |=  (1 << 9);
   PIBC10 |=  (1 << 9);
   PMC10  &= ~(1 << 9);
   PU10   |=  (1 << 9);
}

static void McalDio_vInitInterruptAta(uint8 lu8Val){
   PFC10           |=  (1 << 11);
   PFCE10          &= ~(1 << 11);
   PFCAE10         &= ~(1 << 11);
   PM10            |=  (1 << 11);
   PMC10           |=  (1 << 11);
   FCLA0CTL3_INTPH  =  2;
   TBP11            =  1;
   RFP11            =  0;
   if(lu8Val == c_IRQ_ACTIVE){
      MKP11 = L;
   }
   else{
      MKP11 = H;
   }
}

static void McalDio_vInitPinsRLin(void){
   PFC10   |=  (1 << 6);
   PFCE10  &= ~(1 << 6);
   PFCAE10 &= ~(1 << 6);
   PMC10   |=  (1 << 6);
   PIPC10  |=  (1 << 6);
   PM10    &= ~(1 << 6);
   PFC10   |=  (1 << 7);
   PFCE10  &= ~(1 << 7);
   PFCAE10 &= ~(1 << 7);
   PMC10   |=  (1 << 7);
   PIPC10  |=  (1 << 7);
   PM10    &= ~(1 << 7);
   PFC10   |=  (1 << 8);
   PFCE10  &= ~(1 << 8);
   PFCAE10 &= ~(1 << 8);
   PMC10   |=  (1 << 8);
   PM10    |=  (1 << 8);
}

FUNC(void, MCALDIO_CODE) infMcalDioSwcApplEcuM_vInitFunction(void){
   McalDio_vInitOutput(GPIO_TP0);
   McalDio_vInitOutput(GPIO_TP1);
   McalDio_vInitOutput(GPIO_TP2);
   McalDio_vInitOutput(GPIO_TP3);
   McalDio_vInitPinFreqRF();
   McalDio_vInitOutput(GPIO_CS_ATA);
   McalDio_vInitOutput(GPIO_PWR_ATA);
   McalDio_vInitOutput(GPIO_PWR_B1ATA);
   McalDio_vInitOutput(GPIO_PWR_B2ATA);
   McalDio_vInitInterruptAta(c_IRQ_NOT_ACTIVE);
   McalDio_vInitPinsRLin();

#if(CfgProject == cL_R2023)
   McalDio_vInitInput(GPIO_ERR_TJA);
#endif

#if(CfgProject == cR_R2023)
   McalDio_vInitPinErrTja();
#endif

   McalDio_vInitOutput(GPIO_STB_TJA);
   McalDio_vInitOutput(GPIO_EN_TJA);
   McalDio_vInitOutputOff(GPIO_STB_TJA);
   McalDio_vInitOutputOff(GPIO_EN_TJA);
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
