#pragma once
/******************************************************************************/
/* File   : Types_McalDio.h                                                   */
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
}Type_McalDio_stPin;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

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
