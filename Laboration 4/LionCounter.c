/*
 * LionCounter.c
 *
 * Created: 2019-02-20 10:47:25
 * Author : dic15dju
 */
#define S1 PORTC6
#define S2 PORTC7
#define F_CPU 16000000
#include <avr/io.h>1
#include <util/delay.h>

int main(void)
{
    led_init();
    sensors_init();
    uint8_t lions = 4;
    led_toggle(lions);
    int onWayOut = 0;
    int onWayIn = 0;
    int halfWay = 0;

    while (1)
    {
        if (S1_read() && (!onWayOut || !onWayIn))
        {
            onWayOut = 1;
        }
        if (S2_read() && (!onWayOut || !onWayIn))
        {
            onWayIn = 1;
        }

        if (onWayIn)
        {
            if ((S1_read() && S2_read()) || halfWay)
            {
                halfWay = 1;
                if (!S1_read())
                {
                    led_toggle(lions);
                    lions--;
                    led_toggle(lions);
                    halfWay = 0;
                    onWayIn = 0;
                }
            }
        }

        if (onWayOut)
        {
            if ((S1_read() && S2_read()) || halfWay)
            {
                halfWay = 1;
                if (!S2_read())
                {
                    led_toggle(lions);
                    lions++;
                    led_toggle(lions);
                    halfWay = 0;
                    onWayOut = 0;
                }
            }
        }
    }
    return 0;
}

int S2_read()
{
    return (PINC & (1 << S2));
}

int S1_read()
{
    return (PINC & (1 << S1));
}
void sensors_init()
{
    DDRC |= (0 << DDRC6) | (0 << DDRC7);
}

void led_init()
{
    DDRB |= 0b11111111; // initializes all LEDs
}

void led_toggle(uint8_t num)
{
    PORTB ^= (1 << num);
}
