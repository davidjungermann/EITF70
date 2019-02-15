//Home Assignment 1.1

How many clock cycles are needed if a delay of 0.1 s is desired with a clock frequency of 16
MHz?

16MHz = 16000000 Hz 16000000 * 0.1 = 1600000 

//Home Assignment 1.2

How many bits do we need to count to the value above?

21 bits

//Home Assignment 1.3

How many registers do we need for the delay of 0.1 s?

1 register = 1 byte

We need three bytes, therefore we need 3 bytes. 

//Home Assignment 1.4

Write a snippet of assembly code that delays the program for roughly 0.1 s. Remember that
the jump instructions also take time to execute. 

    start; 

        ldi r2, 100 //1
        ldi r3, 90 //1
        ldi r4, 7 //1

        loop1: 
            dec r2 // 100
            loop2: 
                dec r3 // 90
                loop3: 
                    dec r4 // 7
                    brne loop3 // 6 * 2 +1
                brne loop2 // 89 *2 +1
            brne loop1 // 99 *2 +1 
    end: // 1

    loop1 = 299
    loop2 = 269
    loop3 = 20

    This gives us = 1608624 cycles 

    1608624/16000000 = 0.1005165s         

//Home Assignment 1.5

How do you turn on LED 2 on port B in assembly? Remember to set the direction to an output.
Refer to Appendix A for instructions.

#define DDRB 0x24
led_init:
    ldi r18, 0b11111111 
    in  r19, DDRB
    or  r19, r18
    out DDRB, r19

#define PORTB 0x25
led_on:
    ldi r20, 0b0000100
    in  r21, PORTB
    or  r21, r20
    out PORTB, r20


//Home Assignment 2.1

How do you allocate 10 integers on the stack?

#define STACK_H 0x3E ; Address to the high byte of the stack pointer
#define STACK_L 0x3D ; Address to the low byte of the stack pointer
#define N_ALLOC 10
warp:

in r28, STACK_L ; Load low byte of stack pointer to r28
in r29, STACK_H ; Load high byte of stack pointer to r29
sbiw Y, N_ALLOC ; Subtract N from the loaded stack pointer
out STACK_L , r28 ;
out STACK_H , r29 ; Update stack pointer

ret


//Home Assignment 2.2

If you allocate an array of bytes on the stack, and the stack pointer after allocation is 0x40E0,
what is the address of the value at index 3?

0x40E3

//Home Assignment 3.1
In AVR assembly, how do you declare a subroutine? How do you call it?

subroutine_name: 
    - prolouge -
    - subroutine body- 

Example: 

#define STACK_H 0x3E ; Address to the high byte of the stack pointer
#define STACK_L 0x3D ; Address to the low byte of the stack pointer
#define N_ALLOC 5
defense_routine:
;==================== Start of the prologue
push r28
push r29
in r28, STACK_L ; Load low byte of stack pointer to r28
in r29, STACK_H ; Load high byte of stack pointer to r29
sbiw Y, N_ALLOC ; Subtract N_ALLOC from the loaded stack pointer
out STACK_L , r28 ;
out STACK_H , r29 ; Update stack pointer
;==================== End of the prologue
;==================== Beginning of subroutine body

In order to call a subroutine: 

call subroutine_name

//Home Assignment 3.2
In AVR assembly, how are arguments passed to and returned from a subroutine?

You can use either put all arguments on the stack or by using registers together with the stack. 
In pure assembly, the programmer decides himself how he want to implement the calling conventions, but when mixing
assembly and C, there are specific rules one must follow in order for the compiler to understand. 

Say we want to pass a char, we place it in r24 and r25. Since the char is only one byte, we will r24 and leave r25 empty. 

To pass an argument into assembly using C, write:
functionName(arg). 

When returning use ret. 

//Home Assignment 3.3
How many clock cycles are needed for the delays in Figure 3.1.

Delay 1: 0.8 microsec * 16Mhz = 12.8
Delay 2: 0.6 microsec * 16MHZ = 9.6
Delay 3: 50 microsec * 16MHZ = 800 