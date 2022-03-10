/*****************************************************/
/* File   : Dio.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "infDio_EcuM.h"
#include "infDio_SchM.h"
#include "Dio_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Dio:
      public abstract_module
{
   public:
      FUNC(void, DIO_CODE) InitFunction   (void);
      FUNC(void, DIO_CODE) DeInitFunction (void);
      FUNC(void, DIO_CODE) GetVersionInfo (void);
      FUNC(void, DIO_CODE) MainFunction   (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Dio     Dio;
infEcuMClient* gptrinfEcuMClient_Dio = &Dio;
infDcmClient*  gptrinfDcmClient_Dio  = &Dio;
infSchMClient* gptrinfSchMClient_Dio = &Dio;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DIO_CODE) module_Dio::InitFunction(void){
}

FUNC(void, DIO_CODE) module_Dio::DeInitFunction(void){
}

FUNC(void, DIO_CODE) module_Dio::GetVersionInfo(void){
}

FUNC(void, DIO_CODE) module_Dio::MainFunction(void){
}

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

FUNC(void, DIO_CODE) class_Dio_Unused::GetVersionInfo(void){
}

FUNC(void, DIO_CODE) class_Dio_Unused::FlipChannel(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

