;
; ButtonManagement1.asm
;
; Created: 2019-02-17 12:01:23
; Author : dic15dju
;


; Replace with your application code

#define STACK_H 0x3E ; Address to the high byte of the stack pointer
#define STACK_L 0x3D ; Address to the low byte of the stack pointer
#define N_ALLOC 5
#define DDRA 0x01
#define PINA 0x00

start:
	call button_init
	loop:
	call sample
	rjmp loop

sample:
	//prologue	
	push r28
	push r29
	in r28, STACK_L ; Load low byte of stack pointer to r28
	in r29, STACK_H ; Load high byte of stack pointer to r29 
	sbiw Y, N_ALLOC ; Subtract N from the loaded stack pointer
	out STACK_L, r28 ;
	out STACK_H, r29 ; Update stack pointer

	//body
	ldi r24, N_ALLOC

	loopie:
		dec r24
		in r20, PINA
		std Y+1, r20
        adiw Y, 1
		brne loopie
		call delay

	//epilogue
	in r28, STACK_L
	in r29, STACK_H
	adiw Y, N_ALLOC
	out STACK_L , r28
    out STACK_H , r29
	pop r29
	pop r28
ret

button_init:
	ldi r18, 0x00
    in  r19, DDRA
    or  r19, r18
    out DDRB, r19
ret

delay:
	ldi r22, 5
	ldi r23, 15
	ldi r24, 242

	loop1:
	  dec r24
	  brne loop1
	  dec r23
	  brne loop1
	  dec r22
	  brne loop1
ret
