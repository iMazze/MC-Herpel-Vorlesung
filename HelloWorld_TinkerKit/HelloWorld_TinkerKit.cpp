#include <Arduino.h>

void setup() {
	// Set the LED on Pin PB3 (Tinkerkit O0) to output
	DDRB |= (1 << PB3);

	// Set the button on Pin PC0 (Tinkerkit I0) to input
	DDRC &= ~(1 << PC0);

	// Start the Serialcommunication on 9600 Baud
	Serial.begin(9600);
}

// Endless Loop
void loop() {
	// If PC0 is HIGH turn LED PD3 ON
	if(PINC & (1 << PC0) )
	{
		PORTB |= (1 << PB3);
	}
	// Else LED is LOW
	else
	{
		PORTB &= ~(1 << PB3);

	}

	// Print the PINC register to the console for debugging
	Serial.println(PINC, BIN);

	// Make a small Delay for debouncing
	delay(100);
}
