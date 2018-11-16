#include <Arduino.h>

void setup() {
	// Output to 01 on tinkerkit LED
	DDRB |= (1 << PB3);
}

// Lets LED blink!
void loop() {
	PORTB |= (1 << PB3);
	delay (500);
	PORTB &= ~(1 << PB3);
	delay(500);
}

//VS
/*
#include <Arduino.h>

#define LED_BUILTIN 13


void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
	digitalWrite(LED_BUILTIN, LOW);
	delay(1000);
}
*/
