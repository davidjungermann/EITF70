// Home assignment 6.1 Write a program that blinks a LED with the frequency of 1 Hz. Use the functions described in
//Appendix A.1.

#include <yoda.h>
int main()
{
    int num = 0;
    void led_init(); // Initierar led-lampor

    while (1)
    {
        void led_toggle(num); // togglar av och på
        _ms_delay(1000);      // väntar 1 sekund
    }
    return 0;
}