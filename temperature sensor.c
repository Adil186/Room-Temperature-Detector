/*
 * temperature_sensor.c
 *
 * Created: 24-03-2018 10:33:54
 *  Author: Kamran
 */ 


# include <avr/io.h>
# define F_CPU 8000000
# include <util/delay.h>
# include "lcd.h"
int main(void)
{   int x,F;
	lcd_init();
	ADMUX=0x00;
	ADCSRA=0x86;
	lcd_string("Temp. in C");
	lcd_comm(0xC0);
	lcd_string("Temp. in F");
    while(1)
    {
      ADCSRA|=1<<ADSC;
	  while((ADCSRA&(1<<ADIF))==0);
	  ADCSRA|=1<<ADIF;
	  lcd_comm(0x8E);
	  lcd_number(ADC*0.49);
	  x=ADC*0.49;
	  F=(9/5)*x+32;
	  lcd_comm(0xCE);
	  lcd_number(F);
	  
    }
}