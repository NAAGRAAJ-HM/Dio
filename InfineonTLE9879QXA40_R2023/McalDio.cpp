/******************************************************************************/
/* File   : McalDio.cpp                                                       */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "McalDio.hpp"
#include "infMcalDio_Imp.hpp"

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
VAR(module_McalDio, MCALDIO_VAR) McalDio;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALDIO_CODE) module_McalDio::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, MCALDIO_CONST,       MCALDIO_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALDIO_CONFIG_DATA, MCALDIO_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalDio_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == McalDio_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == McalDio_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == McalDio_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALDIO_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALDIO_CODE) module_McalDio::DeInitFunction(
   void
){
#if(STD_ON == McalDio_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalDio_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == McalDio_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALDIO_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALDIO_CODE) module_McalDio::MainFunction(
   void
){
#if(STD_ON == McalDio_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalDio_InitCheck)
   }
   else{
#if(STD_ON == McalDio_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALDIO_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALDIO_CODE) module_McalDio::ReadChannel(
   void
){
}

FUNC(void, MCALDIO_CODE) module_McalDio::WriteChannel(
   void
){
}

FUNC(void, MCALDIO_CODE) module_McalDio::ReadMcalPort(
   void
){
}

FUNC(void, MCALDIO_CODE) module_McalDio::WriteMcalPort(
   void
){
}

FUNC(void, MCALDIO_CODE) module_McalDio::ReadChannelGroup(
   void
){
}

FUNC(void, MCALDIO_CODE) module_McalDio::WriteChannelGroup(
   void
){
}

FUNC(void, MCALDIO_CODE) module_McalDio::FlipChannel(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

