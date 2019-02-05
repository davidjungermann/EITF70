#include "yoda.h"

int main()
{
    *((char) 0x24) |= 0b00000001; // sätter led 1 till output
    *((char) 0x21) |= 0b00000001; // sätter knapp 1 till input

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