// Home Assignment 1.1

How do you initialize the used I/O-pins? The pins can be found on port C, use the schematic
in Figure 2

Opto-sensor S1 -> PORTC PIN6
Opto-sensor S2 -> PORTC PIN7

#define PINC 0x26
#define DDRC 0x27
#define PINC6 6
#define PINC7 7

DDRC ^= ~(1<<DDRC6); 
DDRC ^= ~(1<<DDRC7); 
PINC |= (1<<PINC6)|(1<<PINC7); 

OR: 

DDRC ^= ~(1<<DDRC6); 
DDRC ^= ~(1<<DDRC7); 
PINC |= (1<<PINC6)|(1<<PINC7);

//Home Assignment 1.2

Write code that polls the opto interrupters and counts the number of lions that are out in the
wild zone. 

See LionCounter.c. 

//Home Assignment 2.1

Look in the datasheet to see which Pin Change Interrupt the sensors are connected to. Use the
pin configurations picture on page 13 in the datasheet.

PCINT23 and PCINT22. 

// Home Assignment 2.2

Write code that enables the correct Pin Change Interrupt in the corresponding Pin Change
Mask Register, PCMSK. See page 92, 93, 94 and 95 in the datasheet for the details.

#define interuptPins PCMSK2
#define S1Interupt PCINT23
#define S2Interupt PCINT22
void interupt_init(){
	SREG |= (1<<7); // Enables interrupts on the microcontroller
	PCICR |= (1<<PCIE2); // Since we have PCINT22/23, we use PCIE2 in PCICR to enable Pin change interrupt
	interuptPins |= (1<<S1Interupt)|(1<<S2Interupt); // Enable the pins
}

// Home Assignment 2.3

How do you enable the pin change interrupt for the corresponding port in the Pin Change
Interrupt Control Register, PCICR? See page 90 in the datasheet

See code above!

// Home Assignment 2.4
Write code that keeps track of the lions.

See LionCounteXTREME.c

// Home Assignment 2.5

How do you enable the USART RX complete interrupt. For details please refer to the datasheet.

USCR0B |=(1<<RXCIE);

