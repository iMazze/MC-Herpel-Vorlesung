#include <Arduino.h>

// Mode for the switch state machine
int mode = 0;
int E;

void setup() {
	// Set the LED to output
	DDRB |= (1 << PB3);

	// Set the button on to input
	DDRC &= ~(1 << PC0);
}

void setLED(bool state)
{
	if(state == true )
	{
		PORTB |= (1 << PB3);
	}
	else
	{
		PORTB &= ~(1 << PB3);
	}
}

void loop() {
	E = PINC;

	switch(mode)
	{
	case 0:
		setLED(0);
		if(E == 0)
		{
			mode = 0;
		}
		else
		{
			mode = 1;

		}
		break;
	case 1:
		setLED(1);
		if(E == 1)
		{
			mode = 0;
		}
		else
		{

			mode = 1;
		}
		break;
	}

	delay(200);

}


