/******************************************************************************/
/* File   : Dio.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "Dio.hpp"
#include "infDio_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DIO_AR_RELEASE_VERSION_MAJOR                                           4
#define DIO_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(DIO_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible DIO_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(DIO_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible DIO_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, DIO_VAR, DIO_CONST) gptrinfEcuMClient_Dio = &Dio;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Dio, DIO_VAR) Dio;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, DIO_CODE) module_Dio::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, DIO_CONFIG_DATA, DIO_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Dio_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == Dio_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == Dio_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Dio_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DIO_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DIO_CODE) module_Dio::DeInitFunction(
   void
){
#if(STD_ON == Dio_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Dio_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == Dio_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DIO_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DIO_CODE) module_Dio::MainFunction(
   void
){
#if(STD_ON == Dio_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Dio_InitCheck)
   }
   else{
#if(STD_ON == Dio_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  DIO_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, DIO_CODE) module_Dio::ReadChannel(
   void
){
}

FUNC(void, DIO_CODE) module_Dio::WriteChannel(
   void
){
}

FUNC(void, DIO_CODE) module_Dio::ReadPort(
   void
){
}

FUNC(void, DIO_CODE) module_Dio::WritePort(
   void
){
}

FUNC(void, DIO_CODE) module_Dio::ReadChannelGroup(
   void
){
}

FUNC(void, DIO_CODE) module_Dio::WriteChannelGroup(
   void
){
}

FUNC(void, DIO_CODE) module_Dio::FlipChannel(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

