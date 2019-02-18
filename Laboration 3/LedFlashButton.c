/*
 * LedFlashButton
 *
 * Created: 2019-02-17 14:22:40
 * Author : dic15dju
 */

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
extern void led_on();
extern void led_off();
extern uint8_t check_button();
extern void led_init();
extern void button_init();

int main(void)
{
led_init();
button_init();
    while (1)
    {

	    if (check_button())  // om knappen är intryckt, alltså om current = 1 och previous = 0
	    {
		    led_on();
			_delay_ms(500); // slå antingen av eller på
			led_off();
			_delay_ms(500);
	    }
    }
}