#include <Arduino.h>

void setup() {
	DDRB |= (1 << PB3);
	DDRC &= ~(1 << PC0);

	Serial.begin(9600);
}

void loop() {
	// If PC0 is HIGH turn LED PD3 ON
	if(PINC & (1 << PC0) )
	{
		PORTB |= (1 << PB3);
	}
	else // Else LED is LOW
	{
		PORTB &= ~(1 << PB3);

	}
	Serial.println(PINC, BIN);
	delay(100);
}
