/*
 * Assembler1.S
 *
 * Created: 2019-02-17 17:10:15
 *  Author: dic15dju
 */ 

 #define PORTD 0x0B
 #define PIND 5
 #define PINA 0x00
 .global read_buttons
 .global send_one
 .global send_zero
 .global send_reset 
 .extern button_state

 send_one: 

	 ldi r20, (1<<PIND)
	 in  r21, PORTD
	 or  r21, r20
	 out PORTD,r21
	 // Börja räkna
	 //11.2 cc

	 lpm
	 lpm
	nop
	nop

	 ldi r20, (1<<PIND)
	 eor r21, r20
	 out PORTD, r21
	 // Sluta räkna

	 // Börja Räkna
	 // 9.6 cc
	 lpm
	 lpm
	 lpm
	 nop
	ret
	
send_zero:

	 ldi r20, (1<<PIND)
	 in  r21, PORTD
	 or  r21, r20
	 out PORTD, r21
	 // Börja räkna
	 //6 cc

	 nop

	 ldi r20, (1<<PIND)
	 eor r21, r20
	 out PORTD, r21
	 // Sluta räkna

	 // Börja Räkna
	 // 12,8 cc
	 ldi r18, 4
	 loop:
	 dec r18
	 brne loop
	 nop

ret

 send_reset:
	 ldi r18, 2
	 ldi r19, 9
	 loopie:
	 dec r19
	 brne loopie
	 dec r18
	 brne loopie
 ret

 read_buttons:
	in r20, PINA
	lsr r20
	lsr r20
	sts button_state, r20
ret