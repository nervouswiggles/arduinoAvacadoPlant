/*
  Test.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/


// include this library's description file
#include "WaterMoisture.h"

#include "Arduino.h"
// include description files for other libraries used (if any)
//#include "HardwareSerial.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances
WaterMoisture::WaterMoisture(char* pinValue)
{
  // do whatever is required to initialize the library
  Serial.println("Within WaterMoisture");
  pinMode(pinValue, OUTPUT); 
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void WaterMoisture::doSomething(void)
{
  // eventhough this function is public, it can access
  // and modify this library's private variables
  Serial.print("pinValue is ");
  Serial.println(pinValue);

  // it can also call private functions of this library
  doSomethingSecret();
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

void WaterMoisture::doSomethingSecret(void)
{
  //digitalWrite(13, HIGH);
  digitalWrite(13, 1);
  delay(220);
  //digitalWrite(13, LOW);
  digitalWrite(13, 0);
  delay(220);
}

