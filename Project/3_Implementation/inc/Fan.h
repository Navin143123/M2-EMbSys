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
#define F_CPU 1000000UL                                   // Macro for crystal frequency (1MHZ)
#include <avr/io.h>                                       // Header file for general input/output
#include <util/delay.h>                                    // Header file used for delay
#define LCD_PRT PORTB
#define LCD_DDR DDRB
#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2
#ifndef __FAN_H__
#define __FAN_H__
void lcdCommand(unsigned char cmd);
/**
 * @brief function to send commands to LCD in 4 bit mode
 * @param[in] load higher nibble of command to LCD PORT
 * @param[in] RS = 0, Select Command Register , RW = 0, Write LCD, EN = 1
 * @param[in] EN = 0, High to Low Pulse
 * @param[in] Load Lower nibble of command to LCD PORT
 * @return none
 */

void lcdData(unsigned char data);
/**
 * @brief function to send data to LCD in 4 bit mode
 * @param[in] load higher nibble of command to LCD PORT
 * @param[in] RS = 1, Select Command Register , RW = 0, Write LCD, EN = 1
 * @param[in] EN = 0, High to Low Pulse
 * @param[in] Load Lower nibble of command to LCD PORT
 * @return none
 */
void lcd_init();
/**
 * @brief // Function to initialize LCD in 5*7 pixels and 4 bit mode, required only once after reset
 * @param[in] Display on curson on
 * @param[in] clear screen
 * @param[in] cursor placed on required position
 * @return none
 */
void lcd_gotoxy (unsigned char col, unsigned char row);
/**
 * @brief  function to position cursor
 * @param[in] Number of rows
 * @param[in] Number of columns
 * @return none
 */
void lcd_print (char *str);
/**
 * @brief  function to print strings
 * @param[in] String value to be   printed on lcd
 * @return none
 */
void lcd_print_int (unsigned int value, int digits);
/**
 * @brief function to print integers
 * @param[in] Number of digits
 * @param[in] value of digit
 * @return none
 */
#endif