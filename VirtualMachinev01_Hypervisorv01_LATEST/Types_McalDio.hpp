#pragma once
/******************************************************************************/
/* File   : Types_McalDio.hpp                                                 */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      CfgMcalDio_ePinName_AP0
   ,  CfgMcalDio_ePinName_AP1
   ,  CfgMcalDio_ePinName_AP2
   ,  CfgMcalDio_ePinName_AP3
   ,  CfgMcalDio_ePinName_AP4
   ,  CfgMcalDio_ePinName_AP5
   ,  CfgMcalDio_ePinName_AP6
   ,  CfgMcalDio_ePinName_AP7
   ,  CfgMcalDio_ePinName_AP8
   ,  CfgMcalDio_ePinName_AP9
}Type_CfgMcalDio_ePinNames;

typedef enum{
      GPIO_LED1
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
}Type_McalDio_eName;

typedef struct{
                  Type_McalDio_eName Name;
                  uint16             PinNumber;
   volatile       uint16*            PMC_Reg;
   volatile       uint16*            PM_Reg;
   volatile const uint16*            PPR_Reg;
   volatile       uint16*            PIBC_Reg;
   volatile       uint16*            P_Reg;
}Type_McalDio_stPin; //TBD: correct naming convention

typedef struct{
                  Type_CfgMcalDio_ePinNames ePinName;
                  uint16                    PinNumber;
   volatile       uint16*                   APM_Reg;
   volatile const uint16*                   APPR_Reg;
   volatile       uint16*                   APIBC_Reg;
   volatile       uint16*                   AP_Reg;
}Type_CfgMcalDio_stInfoPin; //TBD: correct naming convention

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
extern CONST(Type_McalDio_stPin, MCALDIO_CONFIG_DATA) CfgMcalDio_castListInfoPins[]; //TBD: correct naming convention
extern const Type_CfgMcalDio_stInfoPin                ACfgMcalDio_castListPins[];    //TBD: correct naming convention

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
