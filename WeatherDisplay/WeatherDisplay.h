
// ensure this library description is only included once
#ifndef Test_h
#define Test_h

// include types & constants of Wiring core API
#include "WConstants.h"

// library interface description
class WeatherDisplay
{
  // user-accessible "public" interface
  public:
    WeatherDisplay(int);
    void doSomething(void);

  // library-accessible "private" interface
  private:
    int value;
    void doSomethingSecret(void);
};

#endif

