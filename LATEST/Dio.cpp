/******************************************************************************/
/* File   : Dio.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infDio_EcuM.hpp"
#include "infDio_Dcm.hpp"
#include "infDio_SchM.hpp"

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
class class_Dio_Functionality{
   public:
      FUNC(void, DIO_CODE) ReadChannel       (void);
      FUNC(void, DIO_CODE) WriteChannel      (void);
      FUNC(void, DIO_CODE) ReadPort          (void);
      FUNC(void, DIO_CODE) WritePort         (void);
      FUNC(void, DIO_CODE) ReadChannelGroup  (void);
      FUNC(void, DIO_CODE) WriteChannelGroup (void);
      FUNC(void, DIO_CODE) FlipChannel       (void);
};

class module_Dio:
      public abstract_module
   ,  public class_Dio_Functionality
{
   public:
      module_Dio(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, DIO_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, DIO_CONFIG_DATA, DIO_APPL_CONST) lptrCfgModule
      );
      FUNC(void, DIO_CODE) DeInitFunction (void);
      FUNC(void, DIO_CODE) MainFunction   (void);
};

extern VAR(module_Dio, DIO_VAR) Dio;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, DIO_VAR, DIO_CONST) gptrinfEcuMClient_Dio = &Dio;
CONSTP2VAR(infDcmClient,  DIO_VAR, DIO_CONST) gptrinfDcmClient_Dio  = &Dio;
CONSTP2VAR(infSchMClient, DIO_VAR, DIO_CONST) gptrinfSchMClient_Dio = &Dio;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgDio.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Dio, DIO_VAR) Dio(
   {
         DIO_AR_RELEASE_VERSION_MAJOR
      ,  DIO_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, DIO_CODE) module_Dio::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, DIO_CONFIG_DATA, DIO_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Dio_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == Dio_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Dio_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgDio;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == Dio_InitCheck)
   }
#endif
}

FUNC(void, DIO_CODE) module_Dio::DeInitFunction(void){
#if(STD_ON == Dio_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Dio_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Dio_InitCheck)
   }
#endif
}

FUNC(void, DIO_CODE) module_Dio::MainFunction(void){
#if(STD_ON == Dio_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Dio_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
#if(STD_ON == Dio_InitCheck)
   }
#endif
}

FUNC(void, DIO_CODE) class_Dio_Functionality::ReadChannel(void){
}

FUNC(void, DIO_CODE) class_Dio_Functionality::WriteChannel(void){
}

FUNC(void, DIO_CODE) class_Dio_Functionality::ReadPort(void){
}

FUNC(void, DIO_CODE) class_Dio_Functionality::WritePort(void){
}

FUNC(void, DIO_CODE) class_Dio_Functionality::ReadChannelGroup(void){
}

FUNC(void, DIO_CODE) class_Dio_Functionality::WriteChannelGroup(void){
}

FUNC(void, DIO_CODE) class_Dio_Functionality::FlipChannel(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

