#include "../unity/unit_testing.h"

/**
 * @file Fanfunc.c
 * @author Navin
 * @brief Fan control according with temperature
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


void lcdCommand(unsigned char cmd)                        // function to send commands to LCD in 4 bit mode
{
	LCD_PRT = (LCD_PRT & 0x0F) | (cmd & 0xF0);            // load higher nibble of command to LCD PORT
	LCD_PRT &= ~(1<<LCD_RS);                              // RS = 0, Select Command Register
	LCD_PRT &= ~(1<<LCD_RW);                              // RW = 0, Write LCD
	LCD_PRT |= (1<<LCD_EN);                               // EN = 1
	_delay_us(1);                                         // delay
	LCD_PRT &= ~(1<<LCD_EN) ;                             // EN = 0, High to Low Pulse
	
	_delay_us(20);
	
	LCD_PRT = (LCD_PRT & 0x0F) | (cmd<<4);                // Load Lower nibble of command to LCD PORT
	LCD_PRT |= (1<<LCD_EN);                               // start of HIgh to Low pulse on Enable pin
	_delay_us(1);
	LCD_PRT &= ~(1<<LCD_EN);                              // End of high to low pulse on Enable pin
}

void lcdData(unsigned char data)                          // function to send data to LCD in 4 bit mode
{
	LCD_PRT = (LCD_PRT & 0x0F) | (data & 0xF0);           // load higher nibble of command to LCD PORT
	LCD_PRT |= (1<<LCD_RS);
	LCD_PRT &= ~(1<<LCD_RW);
	LCD_PRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_PRT &= ~(1<<LCD_EN);
	
	_delay_us(20);
	
	LCD_PRT = (LCD_PRT & 0x0F) | (data<<4);
	LCD_PRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_PRT &= ~(1<<LCD_EN);
}

void lcd_init()                                            // Function to initialize LCD in 5*7 pixels and 4 bit mode, required only once after reset
{
	LCD_DDR = 0xFF;
	
	LCD_PRT &= ~(1<<LCD_EN);
	_delay_us(2000);
	lcdCommand(0x33);
	_delay_us(100);
	lcdCommand(0x32);
	_delay_us(100);
	lcdCommand(0x28);
	_delay_us(100);
	lcdCommand(0x0e);
	_delay_us(100);
	lcdCommand(0x01);
	_delay_us(2000);
	lcdCommand(0x06);
	_delay_us(100);
}

void lcd_gotoxy (unsigned char col, unsigned char row)      // function to position cursor
{
	unsigned char firstCharAdr[]={0x80,0xc0};
	lcdCommand(firstCharAdr[row-1]+col-1);
	_delay_us(100);
}

void lcd_print (char *str)                                 // function to print strings
{
	unsigned char i = 0;
	while(str[i]!=0)
	{
		lcdData(str[i]);
		i++;
	}
}

void lcd_print_int (unsigned int value, int digits)       // function to print integers
{
	unsigned int temp;
	unsigned int unit;
	unsigned int tens;
	unsigned int hundred;
	unsigned int thousand;
	unsigned int million;
	unsigned char flag=0;
	
	if(digits==5 || flag==1)
	{
		million=value/10000+48;
		lcdData(million);
		flag=1;
	}
	if(digits==4 || flag==1)
	{
		temp = value/1000;
		thousand = temp%10 + 48;
		lcdData(thousand);
		flag=1;
	}
	if(digits==3 || flag==1)
	{
		temp = value/100;
		hundred = temp%10 + 48;
		lcdData(hundred);
		flag=1;
	}
	if(digits==2 || flag==1)
	{
		temp = value/10;
		tens = temp%10 + 48;
		lcdData(tens);
		flag=1;
	}
	if(digits==1 || flag==1)
	{
		unit = value%10 + 48;
		lcdData(unit);
	}
	if(digits>5)
	{
		lcdData('E');
	}
	
}

