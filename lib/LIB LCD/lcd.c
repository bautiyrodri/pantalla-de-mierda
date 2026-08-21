#include "lcd.h"
volatile int est_RS;
int row_shift[2]={0x00,0x40};
void lcd_init (lcd_t* a){
if(a->puerto_lcd == GPIOA) RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
else if(a->puerto_lcd == GPIOB) RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
else if(a->puerto_lcd == GPIOC) RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;
else if(a->puerto_lcd == GPIOD) RCC->APB2ENR|=RCC_APB2ENR_IOPDEN;
else if(a->puerto_lcd == GPIOE) RCC->APB2ENR|=RCC_APB2ENR_IOPEEN;


    for(int i=0;i<8;i++){
if(a->pin_lcd[i]<9){
            a->puerto_lcd -> CRL &=~ (0xF<<a->pin_lcd[i]*4);
            a->puerto_lcd -> CRL |=  (0x1<<a->pin_lcd[i]*4);
}else{
            a->puerto_lcd ->CRH &=~ (0XF<<(a->pin_lcd[i]%8)*4);
            a->puerto_lcd ->CRH |= (0X1<<(a->pin_lcd[i]%8)*4);
}
 }
if(a->puerto_RS_RW == GPIOA) RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
else if(a->puerto_RS_RW == GPIOB) RCC->APB2ENR|=RCC_APB2ENR_IOPBEN;
else if(a->puerto_RS_RW == GPIOC) RCC->APB2ENR|=RCC_APB2ENR_IOPCEN;
else if(a->puerto_RS_RW == GPIOD) RCC->APB2ENR|=RCC_APB2ENR_IOPDEN;
else if(a->puerto_RS_RW == GPIOE) RCC->APB2ENR|=RCC_APB2ENR_IOPEEN;
           
            a->puerto_RS_RW->CRL &=~ (0XF<<a->pin_RS*4);
            a->puerto_RS_RW->CRL |= (0X1<<a->pin_RS*4);

            
            a->puerto_RS_RW->CRL &=~ (0XF<<a->pin_RW*4);
            a->puerto_RS_RW->CRL |= (0X1<<a->pin_RW*4);
}
int lcd_clear(lcd_t* lcd){
     uint8_t com=0x51;
    lcd_send(lcd,com,0);
    
}
int lcd_send(lcd_t*lcd,uint8_t dato,int est_RS){
lcd->puerto_RS_RW->BSRR|=(1<<(lcd->pin_RW+16));
if(est_RS)lcd->puerto_RS_RW->BSRR|=(1<<(lcd->pin_RS));
else lcd->puerto_RS_RW->BSRR|=(1<<(lcd->pin_RS+16));
for(int i=0;i<8;i++){
    if(dato&(1<<i))lcd->puerto_RS_RW->BSRR|=(1<<lcd->d[i]);
        else lcd->puerto_RS_RW->BSRR|=(1<<(lcd->d[i]+16));
    
}
}

void lcd_setcursor(lcd_t*lcd,int row,int col){ 
    uint8_t com=col+row_shift[row];
    lcd_send(lcd,com,0);
}

void lcd_print(lcd_t* lcd ,char *str){
   {
    while(*str){
        lcd_send(lcd, *str, 1);
        str++;
    }
}
}

void lcd_scrollDisplayLeft(lcd_t* lcd){
    uint8_t com=0x55;
    lcd_send(lcd,com,0);
}

void lcd_scrollDisplayRight(lcd_t*lcd){
       uint8_t com=0x56;
    lcd_send(lcd,com,0);
}
void lcd_backlight(lcd_t*lcd){
        uint8_t com=0x41;
    lcd_send(lcd,com,0);
}
void lcd_noBacklight(lcd_t*lcd){
        uint8_t com=0x42;
        lcd_send(lcd,com,0);
}

