/*
 * LionCounterXTREME.c
 *
 * Created: 2019-02-20 12:19:31
 * Author : dic15dju
 */

#define interuptPins PCMSK2
#define S1Interupt PCINT23
#define S2Interupt PCINT22
#define S1 PORTC6
#define S2 PORTC7
#include <avr/io.h>
#include <avr/interrupt.h>
volatile uint8_t onWayOut = 0;
volatile uint8_t onWayIn = 0;
volatile uint8_t halfway = 0;
volatile uint8_t almostOut = 0;
volatile int lions = 4;

int main(void)
{
    interupt_init();
    sensors_init();
    led_init();
    led_toggle(lions);
    while (1)
    {
    }
}

ISR(PCINT2_vect)
{
    if (onWayIn || onWayOut)
    {

        if (onWayOut)
        {
            if (halfway)
            {
                if (almostOut)
                {
                    if (!S1_read() && !S2_read())
                    {
                        led_toggle(lions);
                        lions++;
                        led_toggle(lions);
                        almostOut = 0;
                        halfway = 0;
                        onWayOut = 0;
                    }
                    else
                    {
                        almostOut = 0;
                    }
                }
                else
                {
                    if (S1_read())
                    {
                        almostOut = 1;
                    }
                    else
                    {
                        halfway = 0;
                    }
                }
            }
            else
            {
                if (S1_read())
                {
                    halfway = 1;
                }
                else
                {
                    onWayOut = 0;
                    halfway = 0;
                }
            }
        }
        if (onWayIn)
        {
            if (halfway)
            {
                if (almostOut)
                {
                    if (!S1_read() && !S2_read())
                    {
                        led_toggle(lions);
                        lions--;
                        led_toggle(lions);
                        almostOut = 0;
                        halfway = 0;
                        onWayIn = 0;
                    }
                    else
                    {
                        almostOut = 0;
                    }
                }
                else
                {
                    if (S2_read())
                    {
                        almostOut = 1;
                    }
                    else
                    {
                        halfway = 0;
                    }
                }
            }

            if (S2_read())
            {
                halfway = 1;
            }
            else
            {
                onWayIn = 0;
                halfway = 0;
            }
        }
    }
    else
    {

        if (S2_read())
        {
            onWayOut = 1;
        }

        if (S1_read())
        {
            onWayIn = 1;
        }
    }
}

void interupt_init()
{
    SREG |= (1 << 7);
    PCICR |= (1 << PCIE2);
    interuptPins |= (1 << S1Interupt) | (1 << S2Interupt);
}

void sensors_init()
{
    DDRC |= (0 << DDRC6) | (0 << DDRC7);
}

int S1_read()
{
    return (PINC & (1 << S1));
}
int S2_read()
{
    return (PINC & (1 << S2));
}

void led_init()
{
    DDRB |= 0b11111111; // initializes all LEDs
}

void led_toggle(uint8_t num)
{
    PORTB ^= (1 << num);
}