#include "lcd.h"
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
            a->puerto_lcd ->CRH &=~ (0XF<<a->(pin_lcd[i]%8)*4);
            a->puerto_lcd ->CRH |= (0X1<<a->(pin_lcd[i]%8)*4);
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
int lcd_clear(lcd_t* b){
    b->puerto_RS_RW -> BSRR |= (1<<(b->pin_RS)+16);
    b->puerto_lcd -> BSRR |= (1<<b->pin_lcd[0]);
    for(int i=1;i<8;i++){
        b->puerto_lcd-> BSRR |= (1<<(b->pin_lcd[i])+16);
    }
}
int lcd_send(lcd_t*lcd,dato,char_cmd){
if(char_cmd)lcd->puerto_RS_RW->BSRR|=(1<<pin_RS);
else lcd->puerto_RS_RW->BSRR|=(1<<pin_RS+16);
lcd->puerto_RS_RW->BSRR|=(1<<pin_RW+16);
for(int i=0;i<8;i++){
    if(dato&(1<<i)){
        lcd->puerto_RS_RW->BSRR|=(1<<lcd->d[i]);
        else lcd->puerto_RS_RW->BSRR|=(1<<(lcd->d[i]+16));
    }
}
}

void lcd_setcursor(lcd_t*s , int col,int row){                //col y row en el main.c
    
}

void lcd_print(lcd_t* s ,char *str){
    while(str){
        funcion_mandar(*str++);
    }

}

void lcd_scrollDisplayLeft(lcd_t* s){
    s->puerto_RS_RW -> BSRR |= (1<<(s->pin_RS)+16);
    s->puerto_RS_RW -> BSRR |= (1<<(s->pin_RS)+16);
    for(int i=0;i<4;i++){
        s->puerto_datos -> BSRR |= (1<<(s->pin_datos[i])+16);
    };
    s->puerto_datos -> BSRR |= (1<<s->pin_datos[4]);
    for(int i=5;i<7;i++){
        s->puerto_datos -> BSRR |= (1<<(s->pin_datos[i])+16);
    };
}

void lcd_scrollDisplayRight(configuracion_t*);{
    s->puerto_otros -> BSRR |= (1<<(s->registro)+16);
    s->puerto_otros -> BSRR |= (1<<(s->registro)+16);
    for(int i=0;i<2;i++){
        s->puerto_datos -> BSRR |= (1<<(s->pin_datos[i])+16);
    };
    s->puerto_datos -> BSRR |= (1<<s->pin_datos[2]);
    s->puerto_datos -> BSRR |= (1<<s->pin_datos[4]);
    for(int i=5;i<7;i++){
        s->puerto_datos -> BSRR |= (1<<(s->pin_datos[i])+16);
    };
}

