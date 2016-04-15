// Four way Ping Sensor Robot Module
// Outputs a JSON String of the four sensor readings via Serial

#include <NewPing.h>
#include <ArduinoJson.h>

#define MAX_DISTANCE 200
#define LED 13

NewPing sensor1 = NewPing(5, 6, MAX_DISTANCE);
NewPing sensor2 = NewPing(7, 8, MAX_DISTANCE);
NewPing sensor3 = NewPing(9, 10, MAX_DISTANCE);
NewPing sensor4 = NewPing(11, 12, MAX_DISTANCE);

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop()
{
	digitalWrite(LED, HIGH);

	StaticJsonBuffer<75> jsonBuffer;
	JsonObject& object = jsonBuffer.createObject();

    object["sensor1"] = sensor1.ping_cm();
    object["sensor2"] = sensor2.ping_cm();
    object["sensor3"] = sensor3.ping_cm();
    object["sensor4"] = sensor4.ping_cm();

    object.printTo(Serial);
    Serial.println("");

    digitalWrite(LED, LOW);

    delay(50);
}
