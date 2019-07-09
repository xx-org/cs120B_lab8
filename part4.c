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
	unsigned char tmp = 0x00;
	while(1) {
		//continue;
		x = ADC;
		tmp = 0x00;
		
		if(x> 0x0008)
				tmp |= 0x80;
		if(x > 0x0007)
				tmp|=0x40;
		if(x> 0x0006)
				tmp |= 0x20;
		if(x > 0x0005)
				tmp|=0x10;
		if(x> 0x0004)
				tmp |= 0x08;
		if(x > 0x0003)
				tmp|=0x04;
		if(x> 0x0002)
				tmp |= 0x02;
		if(x > 0x0001)
				tmp|=0x01;
		PORTB = tmp;
		//PORTB = (char)x;
		//PORTD = (char)(x >> 8);

	}
	return 1;
}
