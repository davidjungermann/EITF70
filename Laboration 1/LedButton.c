//Home Assignment 2.1
//Write a program that toggles a LED when a button is clicked, see the state diagram in Figure 2.1.
//Use the functions provided in the course library, see Appendix A.1.

#include <yoda.h>

int main()
{
    led_init();    // Initierar led-lampor
    button_init(); // Initierar buttom

    unsigned int current; // gällande tillstånd
    unsigned int previous = 0; // föregående tillstånd

    while (1)
    {
        current = button_read(1); // gällande tillstånd sätts till antingen 0 eller 1
        if (current > previous)  // om knappen är intryckt, alltså om current = 1 och previous = 0
        {
            led_toggle(0); // slå antingen av eller på
        }
        previous = current; // föregående läge sätts till gällande
    }
    return 0;
}