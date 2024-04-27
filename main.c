#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "led.h"
#include "button.h"

extern uint8_t get_button(int button_pin, int button_number);
extern void init_button();
extern void shift_left_ledon();
extern void shift_right_ledon();
extern void flower_on();
extern void flower_off();

int main()
 { 
	uint8_t state = 0;
	uint8_t button2_state = 0;
	uint8_t button3_state = 1;
	uint8_t last_state = 0;
	
	LED_DDR = 0xff; // LED 모두 출력모드로 PORTA를 출력으로 설정함
	LED_PORT = 0x00; //LED all off
   // Write your code here
	init_button();
	
   while (1){
	if(get_button(BUTTON1_PIN,BUTTON1)){
		if(state > 3)
			state = 1;
		else
			state++;
	}else if(get_button(BUTTON2_PIN,BUTTON2)){
		button2_state = !button2_state;
		if(button2_state){
			state = 5;
		}else
			state = 6;
	}
	else if(get_button(BUTTON3_PIN,BUTTON3)){
		button3_state = !button3_state;
		if(!button3_state){
			//다시 한번 누르면 동작중이던 작업을 재개한다.
			last_state = state;
			state = 0;
		}else{
			state = last_state; // state goes to 0
		}
	}
	
	switch(state){
		case 0:
			LED_PORT = 0x00;
			break;
		case 1:
			shift_left_ledon();
			break;
		case 2:
			shift_right_ledon();
			break;
		case 3:
			LED_PORT = 0xff;
			break;
		case 4:
			LED_PORT = 0x00;
			break;
		case 5:
			flower_off();
			break;
		case 6:
			flower_on();
			break;
	}
   }
   return 0;
 }
 
