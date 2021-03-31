#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
int cnt = 0;

void setup()
{
	Serial.begin(115200);
	LightSensor.begin();
	pinMode(0, INPUT);
	pinMode(2, OUTPUT);
	Serial.println("\n\n\n");
}

void loop()
{	
	lux = LightSensor.GetLightIntensity();
	Serial.print("Light: ");
	Serial.print(lux);
	Serial.println(" lux");
	int val = digitalRead(0);
	Serial.printf("======= read %d\n", val);
	 if (lux < 900) {
		digitalWrite(2, LOW);
	} else {
		digitalWrite(2, HIGH);
	}
	delay(100);
}
