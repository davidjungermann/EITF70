// Write a program that blinks a LED with the frequency of 1 Hz. Use the functions described in
//Appendix A.1.

#include <yoda.h>
int main()
{
    int num = 0;
    void led_init();  // Initierar led-lampor
    
    while(1){
        void led_on(num);
        printf("LED on\n");
        delay(1000);
        void led_off(num);
        printf("LED off\n");
        delay(1000);
    }
    return 0;
}


#include <yoda.h>
int main()
{
    int num = 0;
    void led_init();  // Initierar led-lampor
    
    while(1){
        void led_toggle(num);
        delay(1000);
    }
    return 0;
}