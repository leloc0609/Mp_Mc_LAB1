#include "main.h"
#include "traffic_led.h"
#include "led_7_seg_disp.h"


void cross4way(void){
	HAL_GPIO_WritePin(RED1_PORT, RED1_PIN, SET);
	HAL_GPIO_WritePin(GREEN2_PORT, GREEN2_PIN, SET);
	for(uint8_t i=3; i>0;i--){
		update_seven_segment_driver(i);
		seven_segment_driver();
		HAL_Delay(1000);
	}
	HAL_GPIO_WritePin(GREEN2_PORT, GREEN2_PIN, RESET);
	HAL_GPIO_WritePin(YELLOW2_PORT, YELLOW2_PIN, SET);
	for(uint8_t i=2; i>0;i--){
		update_seven_segment_driver(i);
		seven_segment_driver();
		HAL_Delay(1000);
	}
	HAL_GPIO_WritePin(RED1_PORT, RED1_PIN, RESET);
	HAL_GPIO_WritePin(YELLOW1_PORT, YELLOW1_PIN, SET);
	HAL_GPIO_WritePin(YELLOW2_PORT, YELLOW2_PIN, RESET);
	HAL_GPIO_WritePin(RED2_PORT, RED2_PIN, SET);
	for(uint8_t i=2; i>0;i--){
		update_seven_segment_driver(i);
		seven_segment_driver();
		HAL_Delay(1000);
	}
	HAL_GPIO_WritePin(YELLOW1_PORT, YELLOW1_PIN, RESET);
	HAL_GPIO_WritePin(GREEN1_PORT, GREEN1_PIN, SET);
	for(uint8_t i=3; i>0;i--){
		update_seven_segment_driver(i);
		seven_segment_driver();
		HAL_Delay(1000);
	}
	HAL_GPIO_WritePin(GREEN1_PORT, GREEN1_PIN, RESET);
	HAL_GPIO_WritePin(RED2_PORT, RED2_PIN, RESET);
}
