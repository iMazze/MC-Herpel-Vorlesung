#include <Arduino.h>

// Calculates "human" friendly values for pwm fading
int calcPWM(int x)
{
	const float b = 10.0;
	const float r = 255.0;

	float y = (pow(b,x/r)-1)/(b-1) * x;

	// explicit cast to integer
	return (int)y;

}

void setup() {

	// sets the pin as output
	pinMode(11, OUTPUT);
	Serial.begin(9600);
}

// infinite loop
void loop() {
	for(int i = 0; i<0xFF; i++)
	{
		analogWrite(11, calcPWM(i));
		delay(5);
	}

	for(int i = 0xFF; i>0; i--)
	{
		analogWrite(11, calcPWM(i));
		delay(5);
	}
}
