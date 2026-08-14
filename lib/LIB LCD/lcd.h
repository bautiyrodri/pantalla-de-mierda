#ifndef lcd_H
#define lcd_H
#include "stm32f103xb.h"
#include "stdint.h"

typedef struct{
    GPIO_TypeDef*puerto_lcd;
     int pin_lcd[8];
     GPIO_TypeDef*puerto_RS_RW;
     int pin_RS;// registro selector
     int pin_RW;// leer / escribir
}lcd_t;

uint8_t dato;
char char_cmd; 


void lcd_init(lcd_t*);
int lcd_clear(lcd_t*);
int lcd_send(lcd_t*,dato,char_cmd);
int lcd_setCursor(lcd_t*);
int lcd_print(lcd_t*);
int lcd_scrollDisplayLeft(lcd_t*);
int lcd_scrollDisplayRight(lcd_t*);
int lcd_backlight(lcd_t*);
int lcd_noBacklight(lcd_t*);
int lcd_createChar (lcd_t*);

#endif