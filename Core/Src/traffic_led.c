/*
 * traffic_led.c
 *
 *  Created on: Sep 17, 2021
 *      Author: Win10
 */

#include "main.h"
#include "traffic_led.h"


void cross4way(void){
	HAL_GPIO_WritePin(RED1_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_Port, GREEN2_Pin, RESET);
	HAL_Delay(3000);
	HAL_GPIO_WritePin(GREEN2_Port, GREEN2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_Port, YELLOW2_Pin, RESET);
	HAL_Delay(2000);
	HAL_GPIO_WritePin(RED1_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(YELLOW1_Port, YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW2_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(RED2_Port, RED2_Pin, RESET);
	HAL_Delay(2000);
	HAL_GPIO_WritePin(YELLOW1_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_Port, GREEN1_Pin, RESET);
	HAL_Delay(3000);
	HAL_GPIO_WritePin(GREEN1_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_Port, RED2_Pin, SET);


}
