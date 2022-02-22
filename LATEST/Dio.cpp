/*****************************************************/
/* File   : Dio.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "Dio_EcuM.h"
#include "Dio_SchM.h"
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
   ,  public interface_Dio_EcuM
   ,  public interface_Dio_SchM
{
   public:
      FUNC(void, DIO_CODE) InitFunction   (void);
      FUNC(void, DIO_CODE) DeInitFunction (void);
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
module_Dio Dio;

interface_Dio_EcuM *EcuM_Client_ptr_Dio = &Dio;
interface_Dio_SchM *SchM_Client_ptr_Dio = &Dio;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, DIO_CODE) module_Dio::InitFunction(void){
}

FUNC(void, DIO_CODE) module_Dio::DeInitFunction(void){
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

