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

