/*
 * led.h
 *
 * Created: 2024-04-25 오후 4:46:14
 *  Author: HARMAN-27
 */ 
#ifndef LED_H_
#define LED_H_

#include <avr/io.h> // PORTA DDRA 등의 symbom이 정의 되어 있다.
#include <util/delay.h> // _delay_ms 등의 함수가 들어있다.

#define LED_DDR		DDRA // 이렇게 하는 이유는 LED_DDR에서 바꿔주면 compiler가 알아서 변경해준다
#define LED_PORT	PORTA

// declare function
void shift_left_ledon(void);
void shift_right_ledon(void);
void flower_on(void);
void flower_off(void);

#endif /* LED_H_ */