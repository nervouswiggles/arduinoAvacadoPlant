#ifndef TestLED_h
#define TestLED_h

class TestLED
{
  public:
    TestLED(int pin);
    void turnOnOffLED(void);
		
  private:
    int _pin;
};

#endif
