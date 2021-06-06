/* LED Blink Example with USB Debug Channel for Teensy USB Development Board
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2008, 2010 PJRC.COM, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "usb_debug_only.h"
#include "print.h"


#define CONFIGURE_LED_FOR_OUTPUT (DDRD |= (1<<6))
#define CONFIGURE_LED_FOR_INPUT	(DDRD &= ~(1<<6))
#define LED_ON (PORTD |= (1<<6))
#define LED_OFF (PORTD &= ~(1<<6))

#define CONFIGURE_LAMI_FOR_OUTPUT (DDRB |= (1<<DDB6))
#define CONFIGURE_LAMI_FOR_INPUT (DDRB &= ~(1<<DDB6))
#define LAMI_ON (PORTB |= (1<<PB6))
#define LAMI_OFF (PORTB &= ~(1<<PB6))
#define LAMI_IS_PRESSED (PINB & (1<<PINB6))

#define CONFIGURE_CTRL_FOR_OUTPUT (DDRB |= (1<<DDB3))
#define CONFIGURE_CTRL_FOR_INPUT (DDRB &= ~(1<<DDB3))
#define CTRL_ON	(PORTB |= (1<<PB3))
#define CTRL_OFF (PORTB &= ~(1<<PB3))
#define CTRL_IS_PRESSED (PINB & (1<<PINB3))

#define CONFIGURE_RAMI_FOR_OUTPUT (DDRB |= (1<<DDB2))
#define CONFIGURE_RAMI_FOR_INPUT (DDRB &= ~(1<<DDB2))
#define RAMI_ON (PORTB |= (1<<PB2))
#define RAMI_OFF (PORTB &= ~(1<<PB2))
#define RAMI_IS_PRESSED (PINB & (1<<PINB2))

#define CONFIGURE_STA1_FOR_OUTPUT (DDRF |= (1<<DDB5))
#define CONFIGURE_STA1_FOR_INPUT (DDRF &= ~(1<<DDB5))
#define STA1_ON (PORTF |= (1<<PF5))
#define STA1_OFF (PORTF &= ~(1<<PF5))

#define CONFIGURE_STA2_FOR_OUTPUT (DDRF |= (1<<DDB4))
#define CONFIGURE_STA2_FOR_INPUT (DDRF &= ~(1<<DDB4))
#define STA2_ON (PORTF |= (1<<PF4))
#define STA2_OFF (PORTF &= ~(1<<PF4))

#define CONFIGURE_STA3_FOR_OUTPUT (DDRF |= (1<<DDB3))
#define CONFIGURE_STA3_FOR_INPUT (DDRF &= ~(1<<DDB3))
#define STA3_ON (PORTF |= (1<<PF3))
#define STA3_OFF (PORTF &= ~(1<<PF3))

#define CONFIGURE_KCLK_FOR_OUTPUT (DDRF |= (1<<DDB6))
#define CONFIGURE_KCLK_FOR_INPUT (DDRF &= ~(1<<DDB6))
#define KCLK_ON (PORTF |= (1<<PF6))
#define KCLK_OFF (PORTF &= ~(1<<PF6))

#define CONFIGURE_KDAT_FOR_OUTPUT (DDRF |= (1<<DDB7))
#define CONFIGURE_KDAT_FOR_INPUT (DDRF &= ~(1<<DDB7))
#define KDAT_ON (PORTF |= (1<<PF7))
#define KDAT_OFF (PORTF &= ~(1<<PF7))

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

void configureIOPins()
{
	CONFIGURE_LED_FOR_OUTPUT;
	CONFIGURE_LAMI_FOR_INPUT;
	CONFIGURE_CTRL_FOR_INPUT;
	CONFIGURE_RAMI_FOR_INPUT;
	CONFIGURE_STA1_FOR_OUTPUT;
	CONFIGURE_STA2_FOR_OUTPUT;
	CONFIGURE_STA3_FOR_OUTPUT;
	CONFIGURE_KCLK_FOR_OUTPUT;
	CONFIGURE_KDAT_FOR_OUTPUT;
}

void switchLEDsOn()
{
	LED_ON;
}

void switchLEDsOff()
{
	LED_OFF;
}

int main(void)
{
	// set for 16 MHz clock, and make sure the LED is off
	CPU_PRESCALE(0);
	configureIOPins();
	switchLEDsOff();

	// initialize the USB, but don't want for the host to
	// configure.  The first several messages sent will be
	// lost because the PC hasn't configured the USB yet,
	// but we care more about blinking than debug messages!
	usb_init();

	while (1) {
		if( CTRL_IS_PRESSED ) {
			STA3_ON;
		} else {
			STA3_OFF;
		}
		if( LAMI_IS_PRESSED ) {
			STA2_ON;
		} else {
			STA2_OFF;
		}
		if( RAMI_IS_PRESSED ) {
			STA1_ON;
		} else {
			STA1_OFF;
		}
	}
}


