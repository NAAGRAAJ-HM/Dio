/******************************************************************************/
/* File   : Dio.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infDio_Version.h"
#include "infDio_EcuM.h"
#include "infDio_Dcm.h"
#include "infDio_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_Dio:
      public abstract_module
{
   public:
      FUNC(void, DIO_CODE) InitFunction   (void);
      FUNC(void, DIO_CODE) DeInitFunction (void);
      FUNC(void, DIO_CODE) GetVersionInfo (void);
      FUNC(void, DIO_CODE) MainFunction   (void);
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Dio, DIO_VAR) Dio;
CONSTP2VAR(infEcuMClient, DIO_VAR, DIO_CONST) gptrinfEcuMClient_Dio = &Dio;
CONSTP2VAR(infDcmClient,  DIO_VAR, DIO_CONST) gptrinfDcmClient_Dio  = &Dio;
CONSTP2VAR(infSchMClient, DIO_VAR, DIO_CONST) gptrinfSchMClient_Dio = &Dio;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, DIO_CODE) module_Dio::InitFunction(void){
   Dio.IsInitDone = E_OK;
}

FUNC(void, DIO_CODE) module_Dio::DeInitFunction(void){
   Dio.IsInitDone = E_NOT_OK;
}

FUNC(void, DIO_CODE) module_Dio::GetVersionInfo(void){
}

FUNC(void, DIO_CODE) module_Dio::MainFunction(void){
}

#include "Dio_Unused.h"

FUNC(void, DIO_CODE) class_Dio_Unused::ReadChannel(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::WriteChannel(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::ReadPort(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::WritePort(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::ReadChannelGroup(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::WriteChannelGroup(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::FlipChannel(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

