#define LED 0
#define DDRB 0x04
#define PORTB 0x05

start:

call led_init

loop:
call delay
call led_toggle
rjmp loop


end:
rjmp end

led_init:
ldi r18, 0xFF 
in  r19, DDRB
or  r19, r18
out DDRB, r19 
ret

led_on:
in  r21, PORTB
ldi r20, (1<<LED)
or  r21, r20
out PORTB, r20
ret

led_toggle:
in  r21, PORTB
ldi r20, (1<<LED)
eor  r21, r20
out PORTB, r21
ret

delay:  

ldi r22, 17
ldi r23, 60
ldi r24, 204

loop1:
    dec r24
    brne loop1
    dec r23
    brne loop1
    dec r22
    brne loop1

ret