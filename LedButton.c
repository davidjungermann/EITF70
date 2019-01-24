//Home Assignment 2.1
//Write a program that toggles a LED when a button is clicked, see the state diagram in Figure 2.1.
//Use the functions provided in the course library, see Appendix A.1.

#include <yoda.h>

int main()
{
    uint8_t numLed = 0;
    uint8_t numButton = 1;
    
    led_init();    // Initierar led-lampor
    button_init(); // Initierar buttom

    while (1)
    {
        if (button_read(numButton) == 1)
        {
        led_toggle(numLed);
        }
    }
    return 0;
}