/**
  **************************************************************************
  * @file     at32f402_405_int.c
  * @brief    main interrupt service routines.
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* includes ------------------------------------------------------------------*/
#include "at32f402_405_int.h"

/** @addtogroup AT32F405_periph_examples
  * @{
  */

/** @addtogroup 405_I2SF_fullduplex_dma_philip
  * @{
  */

#define TXBUF_SIZE                       32
#define RXBUF_SIZE                       TXBUF_SIZE

extern uint16_t i2sf5_buffer_tx[TXBUF_SIZE];
extern uint16_t spi_i2s_buffer_rx[RXBUF_SIZE];
extern __IO uint32_t tx_index, rx_index;

/**
  * @brief  this function handles nmi exception.
  * @param  none
  * @retval none
  */
void NMI_Handler(void)
{
}

/**
  * @brief  this function handles hard fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* go to infinite loop when hard fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles memory manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* go to infinite loop when memory manage exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles bus fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* go to infinite loop when bus fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles usage fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* go to infinite loop when usage fault exception occurs */
  while(1)
  {
  }
}

/**
  * @brief  this function handles svcall exception.
  * @param  none
  * @retval none
  */
void SVC_Handler(void)
{
}

/**
  * @brief  this function handles debug monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  this function handles pendsv_handler exception.
  * @param  none
  * @retval none
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  this function handles systick handler.
  * @param  none
  * @retval none
  */
void SysTick_Handler(void)
{
}

/**
  * @brief  This function handles the spi1 interrupt request.
  * @param  None
  * @retval None
  */
 void SPI1_IRQHandler(void)
{
  if(spi_i2s_flag_get(SPI1, SPI_I2S_RDBF_FLAG) != RESET)
  {
    spi_i2s_buffer_rx[rx_index++] = spi_i2s_data_receive(SPI1);
  }
}

/**
  * @brief  This function handles the i2sf5 interrupt request.
  * @param  None
  * @retval None
  */
void I2SF5_IRQHandler(void)
{
  if(spi_i2s_flag_get(I2SF5, SPI_I2S_TDBE_FLAG) != RESET)
  {
    spi_i2s_data_transmit(I2SF5, i2sf5_buffer_tx[tx_index++]);
    if(tx_index == TXBUF_SIZE)
    {
      spi_i2s_interrupt_enable(I2SF5, SPI_I2S_TDBE_INT, FALSE);
    }
  }
}

/**
  * @}
  */

/**
  * @}
  */

