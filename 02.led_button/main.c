/*
 * 02.led_button.c
 *
 * Created: 2024-04-25 오후 1:13:16
 * Author : HARMAN-27
 */ 

#include "button.h"
extern void init_button(void); // init_button함수는 button.c에 있다 "extern키워드"
// extern : 해당 함수가 다른 파일에 있음을 컴파일러에게 알려준다.

int main(void)
{
	LED_DDR = 0xff; // LED가 출력 모드 이므로 all 1로 설정을 한다.
	LED_PORT = 0x00; // LED를 모두 off한다.

	init_button();

    /* Replace with your application code */
    while (1) 
    {
    }
}

