/*
 * ramn_config.h
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 TOYOTA MOTOR CORPORATION.
 * ALL RIGHTS RESERVED.</center></h2>
 *
 * This software component is licensed by TOYOTA MOTOR CORPORATION under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

//This module holds the configuration of current build

#ifndef INC_RAMN_CONFIG_H_
#define INC_RAMN_CONFIG_H_

#if !defined(TARGET_ECUA) && !defined(TARGET_ECUB) && !defined(TARGET_ECUC) && !defined(TARGET_ECUD)
#define TARGET_ECUA
//#define TARGET_ECUB
//#define TARGET_ECUC
//#define TARGET_ECUD
#endif

//Loop time for the "simulator" that is executed periodically
#define SIM_LOOP_CLOCK_MS 10

//Enable watchdogs - Application needs to kick it every 1s
#define WATCHDOG_ENABLE

#if defined(TARGET_ECUA)
#define ENABLE_USB
#define ENABLE_SCREEN

//Automatically stops transceiving when serial port close is detected. May not work well with some OS/Applications
//#define ENABLE_USB_AUTODETECT
//#define GENERATE_RUNTIME_STATS //requires to add "volatile" keyword to static uint32_t ulTotalRunTime = 0UL;
//If CAN_ECHO is enabled, ECU A will repeat whatever message it accepts over USB
//#define CAN_ECHO
//#define ENABLE_REPROGRAMMING
#define ENABLE_UDS
//#define ENABLE_KWP
//#define ENABLE_XCP
#endif

#if defined(TARGET_ECUB)
//#define ENABLE_SCREEN
#define EXPANSION_CHASSIS
#define ENABLE_REPROGRAMMING
#define ENABLE_UDS
#define ENABLE_KWP
#define ENABLE_XCP
#endif

#if defined(TARGET_ECUC)
//#define ENABLE_SCREEN
#define EXPANSION_POWERTRAIN
#define ENABLE_REPROGRAMMING
#define ENABLE_UDS
#define ENABLE_KWP
#define ENABLE_XCP
#endif

#if defined(TARGET_ECUD)
#define EXPANSION_BODY
#define ENABLE_REPROGRAMMING
#define ENABLE_UDS
#define ENABLE_KWP
#define ENABLE_XCP
#endif

#if defined(ENABLE_UDS) || defined(ENABLE_KWP) || defined(ENABLE_XCP)
#define ENABLE_DIAG
#define ENABLE_EEPROM_EMULATION
#endif

#if defined(ENABLE_UDS) || defined(ENABLE_KWP)
#define ENABLE_ISOTP
#endif

#define ISOTP_RXBUFFER_SIZE 			4096
#define ISOTP_TXBUFFER_SIZE 			4096
#define ISOTP_CONSECUTIVE_BLOCK_SIZE 	0
#define ISOTP_CONSECUTIVE_ST 			0
#define ISOTP_RX_TIMEOUT_MS 			200000
#define ISOTP_TX_TIMEOUT_MS 			2000
#define TRNG_POOL_SIZE 	   				256

#ifdef TARGET_ECUA
#define USB_RX_BUFFER_SIZE 				20000
#define USB_TX_BUFFER_SIZE 				40000
#define CAN_RX_BUFFER_SIZE 				20000
#define CAN_TX_BUFFER_SIZE 				60000
#define UDS_ISOTP_RX_BUFFER_SIZE 		0xFFF+2 //Add +2 for buffer-size
#define UDS_ISOTP_TX_BUFFER_SIZE 		0xFFF+2

#else
#define CAN_RX_BUFFER_SIZE 				20480
#define CAN_TX_BUFFER_SIZE 				20480
#define UDS_ISOTP_RX_BUFFER_SIZE 		(4097*6)
#define UDS_ISOTP_TX_BUFFER_SIZE 		(4097*6)
#define KWP_ISOTP_RX_BUFFER_SIZE 		(4097*6)
#define KWP_ISOTP_TX_BUFFER_SIZE 		(4097*6)
#define XCP_RX_BUFFER_SIZE 				(4000)
#define XCP_TX_BUFFER_SIZE 				(4000)
#endif


#endif /* INC_RAMN_CONFIG_H_ */
