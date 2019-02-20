//Lab Question 1.1

Is it necessary to wait for the whole sequence that is generated when a lion passes through the
hallway?

No, since the lion can't go backwards, we already know that they will go in or out, depending on what sensor goes off first. 
As soon as any 1 is given, we know we have A LION!!!! 

//Lab Question 1.2

How fast can an obstacle move through the sensor array without it being missed?

vERY fAST!!1!

Can be calculated using the clock freqency of 16MHz. It depends on the polling.  

// Lab Question 1.3

If a lion moves fast through the senors is it still registered? If not, why? Isn’t that a strange(r)
thing(s)? Are there any limitations to consider while polling sensors?

No, it's not registered. Since we don't poll often enough. Since the sampling time is too low to register we can miss a lion if it runs too fast, and it will therefore not be sent to the YAT-terminal. Nyqvists theorem can be applied, but it means that we have to sample extremely often in order to accurately represent the lions. 

// Lab Question 2.1

What is the value of the variable?

4, due to the 4 states of the sensor. 

// Lab Question 2.2

Are there any disadvantages to consider while using interrupts? Can it be known which part
of the code that is executed just before an interrupt?

No, we can't know that. Therefore we can interrupt something more important than the task at hand. 

// Lab Question 2.3

What is the value of the variable? What did you send from the terminal? Is it correct? (Hint:
An ASCII table might help.)

We sent an "a", we got value 97, so correct!

// Lab Question 2.4

Do you observe anything strange regarding the Neo-pixels while transmitting the string?

It sometimes blinks in blue and green. 

// Lab Question 2.5

What is causing the Neo-pixels to randomly light up? (Hint: When does the interrupt occur?
Is it possible to know what part of the code that is executed when the interrupt occurs?)

Since we don't know what code is executed when the interrupt happens, we can execute parts code in various states of the neoPixels, which causes them to light on different colors. 

// Lab Question 2.6

How could you solve the problem?

If you use cli() you can't use global interrupts, since it clears it. If you clear the global interrupt flag before executing code, the problem goes away. 

// Lab Question 2.7

At what cost is the problem solved?

We can't send any data, since the interrupts are disabled. 




