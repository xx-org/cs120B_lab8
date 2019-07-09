/*
 * test.c
 *
 * Created: 2019/7/6 18:06:56
 * Author : Coco
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1<<ADEN) |(1<<ADSC)| (1<<ADATE);
	
}

unsigned short Max = 0x0001;
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short x = ADC;
	unsigned char tmpMax;
	unsigned char curr = 0x01;
	unsigned char tmp;
	unsigned char i = 0;
	ADC_init();
	while(1) {
		//continue;
		curr = 0x00;
		x = ADC;
		if(x > Max)
		  Max = x;
		tmpMax = Max/16;
		tmp = Max/2;
		for(i = 0; i < 8; i++){
			tmp +=tmpMax;
			if(x >=tmp){
				if(curr == 0)
					curr = 1;
				else{
				curr = curr << 1;
				curr +=1;}
			}
		}
		PORTB = curr;
		//PORTB = (char)x;
		//PORTD = (char)(x >> 8);

	}
	return 1;
}
