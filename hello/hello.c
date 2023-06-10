#include "msp.h"

#define BSET(port, bit) (port |=  (bit))
#define BCLR(port, bit) (port &= ~(bit))

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
	P1DIR = BIT0;               // red LED
	P2DIR = BIT0 | BIT1 | BIT2; // RGB LED

	for(;;) {
		BSET(P1OUT, BIT0);
		BCLR(P2OUT, BIT0 | BIT1 | BIT2);
		__delay_cycles(1000000);

		BCLR(P1OUT, BIT0);
		BSET(P2OUT, BIT0 | BIT1 | BIT2);
		__delay_cycles(1000000);
	}
}
