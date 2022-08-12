#pragma once
/******************************************************************************/
/* File   : McalDio_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_McalDio.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define MCALDIO_CORE_FUNCTIONALITIES                                               \
              FUNC(void, MCALDIO_CODE) ReadChannel       (void);                   \
              FUNC(void, MCALDIO_CODE) WriteChannel      (void);                   \
              FUNC(void, MCALDIO_CODE) ReadMcalPort          (void);                   \
              FUNC(void, MCALDIO_CODE) WriteMcalPort         (void);                   \
              FUNC(void, MCALDIO_CODE) ReadChannelGroup  (void);                   \
              FUNC(void, MCALDIO_CODE) WriteChannelGroup (void);                   \
              FUNC(void, MCALDIO_CODE) FlipChannel       (void);                   \

#define MCALDIO_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, MCALDIO_CODE) ReadChannel       (void) = 0;               \
      virtual FUNC(void, MCALDIO_CODE) WriteChannel      (void) = 0;               \
      virtual FUNC(void, MCALDIO_CODE) ReadMcalPort          (void) = 0;               \
      virtual FUNC(void, MCALDIO_CODE) WriteMcalPort         (void) = 0;               \
      virtual FUNC(void, MCALDIO_CODE) ReadChannelGroup  (void) = 0;               \
      virtual FUNC(void, MCALDIO_CODE) WriteChannelGroup (void) = 0;               \
      virtual FUNC(void, MCALDIO_CODE) FlipChannel       (void) = 0;               \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_McalDio_Functionality{
   public:
      MCALDIO_CORE_FUNCTIONALITIES_VIRTUAL
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

