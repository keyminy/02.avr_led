/*
 * button.c
 *
 * Created: 2024-04-25 오후 1:30:32
 *  Author: HARMAN-27
 */ 
#include "button.h"

void init_button(void);

// 76543210
// DDRD &= 0x0f; // port[7:4]까지 input으로 선언된것
void init_button(void){
	// one's complement
	BUTTON_DDR &= ~((1<< BUTTON1)|(1 << BUTTON2)|(1 << BUTTON3)|(1 << BUTTON4));
	

}