/**
  ******************************************************************************
  * @file    CEC/CEC_MultiAddress/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32446e_eval.h"
#include "stm32446e_eval_io.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define CEC_MAX_PAYLOAD                  16

/* Uncomment the line below if you use the CEC peripheral as a Device 1 */
#define DEVICE_1   
/* Uncomment the line below if you use the CEC peripheral as a Device 2 */ 
//#define DEVICE_2 

#define DEVICE_ADDRESS_1               0x01  /* CEC device 1 address   */
#define DEVICE_ADDRESS_2               0x03  /* Tuner: CEC device 2 address        */
#define DEVICE_ADDRESS_3               0x05  /* Audio System: CEC device 3 address */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
