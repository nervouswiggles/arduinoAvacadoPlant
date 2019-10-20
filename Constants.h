#ifndef _Constants_H
#define _Constants_H
//UNSIGNED = 
//PROGMEM = tells the compiler to place this into the flash memory, not of the SRAM

//For MoistureSensor
const int moistureSensorPin = A0; //Moisture Sensor
const int ledPin = 13; //LED light that flickers on and off for testing
const int lightSensorPin = A1; //Light Sensor

const int lightSensorThreshold = 550;

const int waterPumpDuration=10000;
const int RELAY_PIN = 7;

int moistureThreshold = 500;

int timeOfDay = 0; //Determines if it's Day or night (Day=1, Night=0)
byte waterSensorPin[] = {8, 9, 10};
const byte sensors = 3;

int previousWaterLevel = -1;
unsigned long timeCheckMillis = 0;
unsigned long startMillis = millis();
unsigned long lastWaterMillis = 0;
//const int timeBetweenWatering = 10000; //Available to run every 10 seconds
//const long timeBetweenWatering = 3600000; //Available to run every hour
//const long timeBetweenWatering = 10800000; //Available to run every hour
const long timeBetweenWatering = 21600000; //Available to run every hour
//unsigned const int timeBetweenWatering = 32770; //Testing out int threshold
#endif
