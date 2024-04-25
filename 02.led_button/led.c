/*
 * led.c
 *
 * Created: 2024-04-25 오후 4:45:56
 *  Author: HARMAN-27
 */ 
#include "led.h"

void shift_left_ledon(void);
void shift_right_ledon(void);

// left to right
void shift_left_ledon(void){
	for(int i = 0; i < 8; i++){
		LED_PORT = 0b00000001 << i;
		_delay_ms(1000);
	}
}
void shift_right_ledon(void){
	for(int i = 0; i < 8; i++){
		LED_PORT = 0b10000000 >> i;
		_delay_ms(1000);
	}
}

// left to right
void flower_on(void){
	PORTA = 0x00;
	_delay_ms(1000);
	for(int i = 0; i < 4; i++){
		PORTA = PORTA | ((0b00001000 >> i) | (0b00010000 << i));
		_delay_ms(1000);
	}
	_delay_ms(1000);
}
void flower_off(void){
	PORTA = 0xff;
	_delay_ms(1000);
	for(int i = 0; i < 4; i++){
		PORTA = PORTA & ((0b01111111 >> i) & (0b11111110 << i));
		_delay_ms(1000);
	}
	_delay_ms(1000);
}