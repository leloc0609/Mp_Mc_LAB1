/*
 * matrix_clock.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Win10
 */
#include "main.h"
#include "matrix_clock.h"

static uint8_t conversion[8]={
		0x80,		// 1st dot in row/column
		0x40,		// 2nd dot
		0x20,		// 3rd dot
		0x10,    	// 4th dot
		0x08,		// 5th dot
		0x04,		// 6th dot
		0x02,		// 7th dot
		0x01 		// 8th dot
};

static uint8_t clockLayout[8]={
		0x7E, 	//01111110
		0x81,	//10000001
		0x81,	//10000001
		0x81,	//10000001
		0x81,	//10000001
		0x81,	//10000001
		0x81,	//10000001
		0x7E	//01111110
};

void setRow(uint8_t val){
	HAL_GPIO_WritePin(ROW_1_PORT, ROW_1_PIN, ((val>>7)&0x01));
	HAL_GPIO_WritePin(ROW_2_PORT, ROW_2_PIN, ((val>>6)&0x01));
	HAL_GPIO_WritePin(ROW_3_PORT, ROW_3_PIN, ((val>>5)&0x01));
	HAL_GPIO_WritePin(ROW_4_PORT, ROW_4_PIN, ((val>>4)&0x01));
	HAL_GPIO_WritePin(ROW_5_PORT, ROW_5_PIN, ((val>>3)&0x01));
	HAL_GPIO_WritePin(ROW_6_PORT, ROW_6_PIN, ((val>>2)&0x01));
	HAL_GPIO_WritePin(ROW_7_PORT, ROW_7_PIN, ((val>>1)&0x01));
	HAL_GPIO_WritePin(ROW_8_PORT, ROW_8_PIN, ((val>>0)&0x01));
}

void setCol(uint8_t val){
	HAL_GPIO_WritePin(COL_1_PORT, COL_1_PIN, !((val>>7)&0x01));
	HAL_GPIO_WritePin(COL_2_PORT, COL_2_PIN, !((val>>6)&0x01));
	HAL_GPIO_WritePin(COL_3_PORT, COL_3_PIN, !((val>>5)&0x01));
	HAL_GPIO_WritePin(COL_4_PORT, COL_4_PIN, !((val>>4)&0x01));
	HAL_GPIO_WritePin(COL_5_PORT, COL_5_PIN, !((val>>3)&0x01));
	HAL_GPIO_WritePin(COL_6_PORT, COL_6_PIN, !((val>>2)&0x01));
	HAL_GPIO_WritePin(COL_7_PORT, COL_7_PIN, !((val>>1)&0x01));
	HAL_GPIO_WritePin(COL_8_PORT, COL_8_PIN, !((val>>0)&0x01));
}
void checkConnection(void){
	for(int i = 0; i < 8; i++){
		setRow(conversion[i]);
		for(int j = 0; j < 8; j++){
			setCol(conversion[j]);
			HAL_Delay(500);
		}
	}
}
void setAllClock(void){
	//setRow(0x7E);
	//setCol(0x7E);
	for(int i = 0; i < 8; i++){
		setRow(conversion[i]);
		setCol(clockLayout[i]);
		HAL_Delay(50);

	}

}
