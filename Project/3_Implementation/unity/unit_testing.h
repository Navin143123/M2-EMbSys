/**
 * @file Fan.h
 * @author Navin 
 * @brief Fan control according with temperature 
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef __AVR_ATmega328__                                 // Defining the Atmega328 controller
#define __AVR_ATmega328__
#endif

#ifndef UNIT_TESTING_H_
#define TEST_PROJECT_H_

#define F_CPU 1000000UL                                   // Macro for crystal frequency (1MHZ)
#include <avr/io.h>                                       // Header file for general input/output
#include <util/delay.h>                                    // Header file used for delay
#define LCD_PRT PORTB
#define LCD_DDR DDRB
#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2

void lcdCommand(unsigned char cmd);

void lcdData(unsigned char data);

void lcd_init();

void lcd_gotoxy (unsigned char col, unsigned char row);

void lcd_print (char *str);

void lcd_print_int (unsigned int value, int digits);

#endif