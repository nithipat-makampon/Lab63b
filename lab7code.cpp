#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BH1750FVI.h> //ประกาศ binary ของ light senosr 
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
int cnt = 0;

void setup()
{
	Serial.begin(115200); 
	LightSensor.begin(); //ประกาศใช้ Light sensor 
	pinMode(0, INPUT); 
	pinMode(2, OUTPUT);
	Serial.println("\n\n\n");
}

void loop()
{	
	lux = LightSensor.GetLightIntensity(); //ประกาศตัวแปรในการวัดแสง
	Serial.print("Light: "); // ค่าแสงที่วัดได้จาก Light sensor
	Serial.print(lux);
	Serial.println(" lux");
	int val = digitalRead(0); 
	Serial.printf("======= read %d\n", val); // ไฟติดขึ้นว่า read 0 ไฟดับขึ้นว่า read 1
	 if (lux > 1000) { // ค่า 1000  สามารถกำหนดปรับได้ตามค่าแสงในห้องต่างๆ
		digitalWrite(2, LOW); // ถ้าค่าแสงมากกว่า 1000 ไฟจะดับ
	} else {
		digitalWrite(2, HIGH); // ถ้าค่าแสงน้อยกว่า 1000 ไฟจะติด
	}
	delay(100);
}
