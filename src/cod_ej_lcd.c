#include "lcd.h"
#include "stm32f103xb.h"

lcd_t peron;

int main(){
    peron.puerto_lcd=GPIOA;
    peron.puerto_RS_RW=GPIOB;
    for(int i=0;i<8;i++){
    peron.pin_lcd[i]=i+1;
    }
    peron.pin_RS=13;
    peron.pin_RW=14;
    lcd_init(&peron);

    while(1){
    lcd_backlight(&peron);
    lcd_clear(&peron);
    lcd_setcursor(&peron, 0, 0);
    lcd_print(&peron, "viva Peron");
    lcd_setcursor(&peron, 0, 1);
    lcd_print(&peron, "cristina kirchner");
    lcd_clear(&peron);
    lcd_noBacklight(&peron);
    }
}