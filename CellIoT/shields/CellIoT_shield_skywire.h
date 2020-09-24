/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __CELLIOT_SHIELD_SKYWIRE_H__
#define __CELLIOT_SHIELD_SKYWIRE_H__

#include "board.h"
#include "pin_mux.h"
#include "gm01q_tools.h"
#include "fsl_clock.h"
#include "fsl_reset.h"
#include "FreeRTOS.h"

/* This file cannot be included directly in common code, it must pass through "CELLIOT_shield.h" */
#ifndef CELLIOTSHIELD_ENABLED
#   define CELLIOTSHIELD_ENABLED
#else
#   error "Other CELLIOT shield is already enabled !"
#endif

extern usart_rtos_handle_t g_uartRtosHandle;
extern usart_handle_t g_uartHandle;
extern usart_dma_handle_t g_uartDmaHandle;
extern dma_handle_t g_timerTransferHandle;

/* Pinmux function, generated by pinmuxtool */
#define CELLIOTSHIELD_PINMUX_INIT BOARD_InitSequansSkywireShield

/* USART settings */
#define CELLIOTSHIELD_USART (USART2)
#define CELLIOTSHIELD_USART_CLK ((clock_ip_name_t)kCLOCK_FlexComm2)
#define CELLIOTSHIELD_USART_CLK_CONNECT (kFRO12M_to_FLEXCOMM2)
#define CELLIOTSHIELD_USART_IP_RESET (kFC2_RST_SHIFT_RSTn)
#define CELLIOTSHIELD_USART_BAUDRATE (921600U)
#define CELLIOTSHIELD_USART_IRQ (FLEXCOMM2_IRQn)
#define CELLIOTSHIELD_USART_IRQ_MASK (USART_FIFOINTENSET_RXLVL_MASK | USART_FIFOINTENSET_RXERR_MASK)
#define CELLIOTSHIELD_USART_IRQ_PRIORITY (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY)
#define CELLIOTSHIELD_USART_RTOS_HANDLE (g_uartRtosHandle)
#define CELLIOTSHIELD_USART_HANDLE (g_uartHandle)
#define CELLIOTSHIELD_USART_RING_BUFFER (g_rxRingBuffer)
#define CELLIOTSHIELD_USART_TX_BUFFER (g_txBuffer)
#define CELLIOTSHIELD_USART_RX_BUFFER (g_rxBuffer)
#define CELLIOTSHIELD_USART_BUFFER_SIZE (AT_BUFFER_SIZE)
#define CELLIOTSHIELD_USART_QUEUE_SIZE (10U)

/* DMA settings */
#define CELLIOTSHIELD_DMA (DMA0)
#define CELLIOTSHIELD_DMA_RX_CH (10U)
#define CELLIOTSHIELD_DMA_TX_CH (11U)
#define CELLIOTSHIELD_DMA_SPARE_CH (0U)
#define CELLIOTSHIELD_DMA_HANDLE (g_uartDmaHandle)
#define CELLIOTSHIELD_DMA_RXHANDLE (g_timerTransferHandle)
#define CELLIOTSHILED_DMA_IRQ (DMA0_IRQn)
#define CELLIOTSHIELD_DMA_IRQ_PRIORITY (1/*configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1U*/)

#endif