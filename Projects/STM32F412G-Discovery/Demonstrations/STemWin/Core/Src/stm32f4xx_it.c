/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

 /** @addtogroup CORE
  * @{
  */

/** @defgroup 
  * @brief  
  * @{
  */
  
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern PCD_HandleTypeDef                hpcd;
extern QSPI_HandleTypeDef               QSPIHandle;
extern K_ModuleItem_Typedef             USB_Storage_board;
extern I2S_HandleTypeDef                haudio_i2s;

extern DFSDM_Filter_HandleTypeDef      hAudioInDfsdmFilter[];

/* Private function prototypes -----------------------------------------------*/
extern void xPortSysTickHandler(void);

/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  osSystickHandler();
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles DMA1 Stream 0 interrupt request.
  * @param  None
  * @retval None
  */
void AUDIO_IN_I2Sx_DMAx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(haudio_i2s.hdmarx);
}

/**
  * @brief  This function handles External line 3 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI3_IRQHandler(void)
{
   HAL_GPIO_EXTI_IRQHandler(SD_DETECT_PIN);
}

/**
  * @brief  This function handles DMA1 Stream5 interrupt request.
  * @param  None
  * @retval None
  */
void AUDIO_OUT_I2Sx_DMAx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(haudio_i2s.hdmatx);
}

/**
  * @brief  This function handles USB-On-The-Go FS global interrupt request.
  * @param  None
  * @retval None
  */
void OTG_FS_IRQHandler(void)
{
  HAL_PCD_IRQHandler(&hpcd);   
}

/**
  * @brief  This function handles DMA2 Stream 5 interrupt request.
  * @param  None
  * @retval None
  */
void QUADSPI_IRQHandler(void)
{
  HAL_QSPI_IRQHandler(&QSPIHandle);
}

/**
  * @brief  This function handles DFSDM MIC1 DMA interrupt request.
  * @retval None
  */
void AUDIO_DFSDM_DMAx_MIC1_IRQHandler(void)
{
  HAL_DMA_IRQHandler(hAudioInDfsdmFilter[POS_VAL(INPUT_DEVICE_DIGITAL_MIC1)].hdmaReg);
}

/**
  * @brief  This function handles DFSDM MIC2 DMA interrupt request.
  * @retval None
  */
void AUDIO_DFSDM_DMAx_MIC2_IRQHandler(void)
{
  HAL_DMA_IRQHandler(hAudioInDfsdmFilter[POS_VAL(INPUT_DEVICE_DIGITAL_MIC2)].hdmaReg);
}


/**
  * @}
  */

/**
  * @}
  */
    
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
