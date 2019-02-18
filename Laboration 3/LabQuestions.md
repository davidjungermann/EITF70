// Lab Question 1.1

How can you use your delay code in order to create arbitrary delays? What is the limitation?

We only have three registers, all with room for 255 bits. So unless we increase the amount of loops used, we can only store 3*255 bits worth of data in the delay. 

// Lab Question 2.1

What is the value of the stack pointer directly after allocation? Use the debugger.

16637 -> 16632

// Lab Question 2.2
What happens if we do not return the allocated memory in the subroutine?

Memory leak since we lose access to memory that we have currently allocated for. 

// Lab Question 2.3
Do we need to store the values in the allocated array? What happens if we just store the values
randomly on the stack?

Yes, since virtual memory is allocated to the process. If we don't allocate memory the process might not be able to access the right partition, which could cause errors. 

//Lab Question 3.1

When calling the subroutine, led_on, what is being pushed to the stack and why?

0x40FF - 0100000011111111. The last bits inits the leds, and the first ones indicate which led that was turned on. 

// Lab Question 3.2

When the ret instruction is executed, what happens with the stack pointer?

Goes from 0x40FD to 0x40FB, because when we go into a assembly funtion it adds two values, which then are decremented when we return the function. 

//Lab Question 3.3

In the check_button subroutine, comment out the instruction where you place the return value
in r24 and run the code. Does the LED blink? If so, why?

No, cause we don't add anything to the register, so the button is never checked. 

// Lab Question 4.1

What does the code do?

It sends three strings to to the OLED-screen. 

// Lab Question 4.2

Without running the code, does it seem like the function hacked is ever called?

No, it's never called. 

// Lab Question 4.3

Run the code once, what happens?

The H4CK3D-text shows that is put in hack(). 

// Lab Question 4.4

When calling the secure_function function, what will be pushed to the stack and at which
addresses?

Stack pointer is moved 14 steps, but we only allocate for 8 bytes. Which means we write to memory that's not free. 

// Lab Question 4.5

At which addresses do strcpy copy the last values? Is this correct? If not, is something
overwritten?

r22 and r24

// Lab Question 4.6

As you exit strcpy and executing the ret instruction in secure_function, what is the return
address? Where do we end up?

We end up at hacked, which means this code is executed at the stack instead of secure function. 


