/*
 * 02.led_button.c
 *
 * Created: 2024-04-25 오후 1:13:16
 * Author : HARMAN-27
 */ 

#include "button.h"
#include "led.h"
extern void init_button(void); // init_button함수는 button.c에 있다 "extern키워드"
// extern : 해당 함수가 다른 파일에 있음을 컴파일러에게 알려준다.
extern int get_button(int button_pin, int button_number); // button.c에 해당 함수가 있으므로 알려준다
extern void shift_left_ledon(void);
extern void shift_right_ledon(void);

int main(void)
{
	int button1_state = 0; // 초기상태는 버튼을 off상태로 출발합니다.

	LED_DDR = 0xff; // LED가 출력 모드 이므로 all 1로 설정을 한다.
	LED_PORT = 0x00; // LED를 모두 off한다.

	init_button();

    /* Replace with your application code */
    while (1) 
    {
		// 버튼1은 portd4에 연결됨
		// (1) 버튼1을 1번 눌렀다 때면 led전체를 on시키고
		// (2) 버튼1을 1번 눌렀다 떼면 led전체를 off
		//지금 get_button(BUTTON1_PIN,1)은 1로 하드코딩됨
		if(get_button(BUTTON1_PIN,BUTTON1)){ // 버튼을 1번 눌렀다 떼면 반전시킴
			button1_state++;
			button1_state %= 4;
		}
		switch(button1_state){
			case 0:
			shift_left_ledon();
			break;
			case 1:
			shift_right_ledon();
			break;
			case 2:
			LED_PORT = 0xff;
			break;
			case 3:
			LED_PORT = 0x00;
			break;
			default:
			break;
		}
	}
}
