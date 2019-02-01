// Home assignment 6.1 Write a program that blinks a LED with the frequency of 1 Hz. Use the functions described in
//Appendix A.1.

#define F_CPU 16000000UL
#include <yoda.h>
#include <util/delay.h>

int main()
{
    unsigned int num = 0;
    led_init(); // Initierar led-lampor

    while (1)
    {
        led_toggle(num); // togglar av och på
        _delay_ms(1000); // väntar 1 sekund
    }
    return 0;
}