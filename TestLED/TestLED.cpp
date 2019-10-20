#include "TestLED.h"

TestLED::TestLED(int givenValue)
{
  pinMode(13, OUTPUT);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void TestLED::turnOnOffLED(void)
{
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}
