/*
 * matrix_clock.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Win10
 */
#include "main.h"
#include "matrix_clock.h"

#define NUMBER_OF_LED 3

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

static uint8_t clockLayout[]={
		0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1 o'clock
		0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // 2 o'clock
		0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, // 3 o'clock
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, // 4 o'clock
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, // 5 o'clock
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, // 6 o'clock
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, // 7 o'clock
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, // 8
		0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, // 9
		0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, // 10
		0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 11
		0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // 12
};

static uint8_t clockBuffer[NUMBER_OF_LED];

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

void setNumberOnClock(uint8_t layout[]){
	for(int i = 0; i < 8; i++){
		setRow(conversion[i]);
		setCol(layout[i]);
		HAL_Delay(50);// delay 50 for simulation purpose
		//HAL_Delay(8);
	}
}
//For human eyes to see a LED lights up it only need to blink at least 14 times in a second
//So I calculate the minimum of delay for each row to blink
//I made the LED blink 16 times/s for easier calculation
// 1000/16 =~ 62.5 ms
// 62.5/8  =~ 8ms so this the amount of delay for each row

void updateClock(void){
	uint8_t layout[8];
	for (uint8_t i = 0; i < 8; i++){
		layout[i] = clockLayout[8*clockBuffer[0]+i]|clockLayout[8*clockBuffer[1]+i]|clockLayout[8*clockBuffer[2]+i];
	}
	setNumberOnClock(layout);
}
void setClock(uint8_t hour, uint8_t minute, uint8_t second){
	clockBuffer[0]=hour;
	clockBuffer[1]=minute;
	clockBuffer[2]=second;
}
