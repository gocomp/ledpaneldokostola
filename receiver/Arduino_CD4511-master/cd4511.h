/* CD4511 Library for Arduino
 *
 * Written by Tom "TBSliver" Bloor
 */

#ifndef cd4511_h
#define cd4511_h

#include "Arduino.h"

class CD4511
{
  public:

  CD4511(int pin_a, int pin_b, int pin_c, int pin_d, bool inverse);
  void write(int number);

  private:

  int _pin_a;
  int _pin_b;
  int _pin_c;
  int _pin_d;
  bool _inverse;
  uint8_t _high();
  uint8_t _low();
};

#endif
