/******************************************************************************/
/* File   : McalDio.cpp                                                       */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
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
#define MCALDIO_AR_RELEASE_VERSION_MAJOR                                       4
#define MCALDIO_AR_RELEASE_VERSION_MINOR                                       3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(MCALDIO_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible MCALDIO_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(MCALDIO_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible MCALDIO_AR_RELEASE_VERSION_MINOR!"
#endif

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
      CONSTP2CONST(ConstModule_TypeAbstract, MCALDIO_CONST,       MCALDIO_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALDIO_CONFIG_DATA, MCALDIO_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalDio_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstMcalDio_Type*)lptrConstModule;
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

