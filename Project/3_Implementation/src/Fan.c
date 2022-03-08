/**
 * @file Fan.c
 * @author Navin
 * @brief Fan control according to temperture
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "Fan.h"

void adc_init()                                      // To initialixe the adc
{
	DDRC = DDRC & ~(1<<PINC0);                       // PORTC INPUT for ADC
	ADCSRA = 0x87;                                   // ADC Enable, Select clk/128 for ADC
	ADMUX = 0x60;                                    // 0100 0000 AVCC(5V) reference voltage, ADC0 single ended input, left justified,
}


int main(void)
{
    lcd_init();
	adc_init();
	lcd_gotoxy(1,1);
	lcd_print("Temperature:");
	TCCR0A = 0xC3;                                  // fast pwm , inverted mode with no pre scaling
	TCCR0B = 0x01;
	DDRD = DDRD |(1<<PORTD6);                       // PORTD OUTPUT for PWM
	lcd_gotoxy(1,2);                                
	lcd_print("Fanspeed:");

    while(1) 
    {
		ADCSRA|= (1<<ADSC);                        // start conversion
		while((ADCSRA&(1<<ADIF))==0);              // wait till ADIF becomes q, end of conversion
		float val = ADCH;                          // Number between 0 to 255 proportional to input voltage
		OCR0A = val;
		float val_mv= val*19.53;
		float tempC = val_mv/10;
		lcd_gotoxy(13,1);
		lcd_print_int(tempC,2);
		lcdData(223);
		lcdData('C');
		float tempC1 = val_mv/10;
		lcd_gotoxy(10,2);
		lcd_print_int(tempC1,2);
		lcdData('%');
		_delay_ms(1000);
		lcdCommand(0x0C);
	    _delay_us(100);
    }
}
