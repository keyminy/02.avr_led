/*
 * button.h
 *
 * Created: 2024-04-25 오후 1:15:19
 *  Author: HARMAN-27
 */ 


#ifndef BUTTON_H_

#define BUTTON_H_
#define F_CPU 16000000UL
#include <avr/io.h> // PORTA DDRA 등의 symbom이 정의 되어 있다.
#include <util/delay.h> // _delay_ms 등의 함수가 들어있다.

#define LED_DDR		DDRA // 이렇게 하는 이유는 LED_DDR에서 바꿔주면 compiler가 알아서 변경해준다
#define LED_PORT	PORTA
#define BUTTON_DDR  DDRD;
#define BUTTON_PIN  PIND; // PORTD를 read하는 register, 전압5v를 읽으면 1, 0v를 읽으면 0

#define BUTTON1 4 // PORTD.4
#define BUTTON2 5 // PORTD.5
#define BUTTON3 6 // PORTD.6
#define BUTTON4 7 // PORTD.7

#endif //  BUTTON_H

// portA는 write모드
// portD는 button이 연결되었음




#endif /* BUTTON_H_ */