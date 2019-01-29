//Home Assignment 2.1
//Write a program that toggles a LED when a button is clicked, see the state diagram in Figure 2.1.
//Use the functions provided in the course library, see Appendix A.1.

#include <yoda.h>

int main()
{
    led_init();    // Initierar led-lampor
    button_init(); // Initierar buttom

    unsigned int current;
    unsigned int previous = 0;

    while (1)
    {
        current = button_read(1);
        if (current > previous)
        {
            led_toggle(0);
        }
        previous = current;
    }
    return 0;
}