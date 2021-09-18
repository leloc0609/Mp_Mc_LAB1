/*
 * matrix_clock.h
 *
 *  Created on: Sep 17, 2021
 *      Author: Win10
 */

#ifndef INC_MATRIX_CLOCK_H_
#define INC_MATRIX_CLOCK_H_


void setRow(uint8_t val);
void setCol(uint8_t val);
void setNumberOnClock(uint8_t layout[]);
void updateClock(void);
void setClock(uint8_t hour, uint8_t minute, uint8_t second);

#endif /* INC_MATRIX_CLOCK_H_ */
