/*
 * sd.h
 *
 *  Created on: Jan 3, 2024
 *      Author: witol
 */

#ifndef SD_H_
#define SD_H_
//--------------------------------------------------

#include "stm32h7xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define CS_SD_GPIO_PORT GPIOA
#define CS_SD_PIN GPIO_PIN_3
#define SS_SD_SELECT() HAL_GPIO_WritePin(CS_SD_GPIO_PORT, CS_SD_PIN, GPIO_PIN_RESET)
#define SS_SD_DESELECT() HAL_GPIO_WritePin(CS_SD_GPIO_PORT, CS_SD_PIN, GPIO_PIN_SET)
// LED zamiast PC13 czerwona jest PE3 niebieska
#define LD_ON HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET); //BLUE
#define LD_OFF HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET); //BLUE
/* Card type flags (CardType) */

#define CT_MMC 0x01 /* MMC ver 3 */
#define CT_SD1 0x02 /* SD ver 1 */
#define CT_SD2 0x04 /* SD ver 2 */
#define CT_SDC (CT_SD1|CT_SD2) /* SD */
#define CT_BLOCK 0x08 /* Block addressing */

//--------------------------------------------------
typedef struct sd_info {

  volatile uint8_t type;//тип карты

} sd_info_ptr;

//--------------------------------------------------
void SPI_Release(void);
uint8_t sd_ini(void);
void SPI_SendByte(uint8_t bt);
uint8_t SPI_ReceiveByte(void);
uint8_t SPIx_WriteRead(uint8_t Byte);
void SD_PowerOn(void);
static uint8_t SD_cmd (uint8_t cmd, uint32_t arg);

#endif /* SD_H_ */
