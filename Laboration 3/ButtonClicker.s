/*
 * ButtonClicker.S
 *
 * Created: 2019-02-17 14:33:11
 *  Author: dic15dju
 */

 .global led_on
 .global led_off
 .global check_button
 .global led_init
 .global button_init

 #define LED 0
 #define PINA 0x00
 #define DDRA 0x01
 #define PORTB 0x05
 #define DDRB 0x04

led_on:
	in  r21, PORTB
	ldi r20, (1<<LED)
	or  r21, r20
	out PORTB, r21
ret


led_off:
  in  r21, PORTB
  ldi r20, (1<<LED)
  or  r21, r20
  eor r21, r20
  out PORTB, r21
ret

check_button:
	in r24, PINA
ret

button_init:
	out DDRA, 0x00
ret


led_init:
ldi r18, 0xFF
  in  r19, DDRB
  or  r19, r18
  out DDRB, r19
ret