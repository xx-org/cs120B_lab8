/*
 * test.c
 *
 * Created: 2019/7/6 18:06:56
 * Author : Coco
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <io.h>
#include <io.c>
#include <string.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1<<ADEN) |(1<<ADSC)| (1<<ADATE);
	
}

const unsigned short Max = 0x001F;
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short x = ADC;
	ADC_init();
	while(1) {
		//continue;
		x = ADC;
		if(x > Max){PORTB = 1;}else{PORTB = 0;}
		//PORTB = (char)x;
		//PORTD = (char)(x >> 8);

	}
	return 1;
}
