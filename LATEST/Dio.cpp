/******************************************************************************/
/* File   : Dio.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.hpp"
#include "CfgDio.hpp"
#include "infDio_EcuM.hpp"
#include "infDio_Dcm.hpp"
#include "infDio_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define DIO_AR_RELEASE_MAJOR_VERSION                                           4
#define DIO_AR_RELEASE_MINOR_VERSION                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(DIO_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible DIO_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(DIO_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible DIO_AR_RELEASE_MINOR_VERSION!"
#endif

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

   private:
      CONST(Std_TypeVersionInfo, DIO_CONST) VersionInfo = {
            0x0000
         ,  0xFFFF
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };
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
#if(STD_ON == Dio_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, DIO_CODE) module_Dio::MainFunction(void){
}

#include "Dio_Unused.hpp"

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

