#include "Arduino.h"
#include "cd4511.h"

CD4511::CD4511(int pin_a, int pin_b, int pin_c, int pin_d, bool inverse)
{
  _pin_a = pin_a;
  _pin_b = pin_b;
  _pin_c = pin_c;
  _pin_d = pin_d;
  _inverse = inverse;

  pinMode(_pin_a, OUTPUT);
  pinMode(_pin_b, OUTPUT);
  pinMode(_pin_c, OUTPUT);
  pinMode(_pin_d, OUTPUT);
}

void CD4511::write(int number)
{
  switch (number)
  {
    case 0:
      digitalWrite(_pin_a, _low());
      digitalWrite(_pin_b, _low());
      digitalWrite(_pin_c, _low());
      digitalWrite(_pin_d, _low());
      break;
    case 1:
      digitalWrite(_pin_a, _high());
      digitalWrite(_pin_b, _low());
      digitalWrite(_pin_c, _low());
      digitalWrite(_pin_d, _low());
      break;
    case 2:
      digitalWrite(_pin_a, _low());
      digitalWrite(_pin_b, _high());
      digitalWrite(_pin_c, _low());
      digitalWrite(_pin_d, _low());
      break;
    case 3:
      digitalWrite(_pin_a, _high());
      digitalWrite(_pin_b, _high());
      digitalWrite(_pin_c, _low());
      digitalWrite(_pin_d, _low());
      break;
    case 4:
      digitalWrite(_pin_a, _low());
      digitalWrite(_pin_b, _low());
      digitalWrite(_pin_c, _high());
      digitalWrite(_pin_d, _low());
      break;
    case 5:
      digitalWrite(_pin_a, _high());
      digitalWrite(_pin_b, _low());
      digitalWrite(_pin_c, _high());
      digitalWrite(_pin_d, _low());
      break;
    case 6:
      digitalWrite(_pin_a, _low());
      digitalWrite(_pin_b, _high());
      digitalWrite(_pin_c, _high());
      digitalWrite(_pin_d, _low());
      break;
    case 7:
      digitalWrite(_pin_a, _high());
      digitalWrite(_pin_b, _high());
      digitalWrite(_pin_c, _high());
      digitalWrite(_pin_d, _low());
      break;
    case 8:
      digitalWrite(_pin_a, _low());
      digitalWrite(_pin_b, _low());
      digitalWrite(_pin_c, _low());
      digitalWrite(_pin_d, _high());
      break;
    case 9:
      digitalWrite(_pin_a, _high());
      digitalWrite(_pin_b, _low());
      digitalWrite(_pin_c, _low());
      digitalWrite(_pin_d, _high());
      break;
  }
}

uint8_t CD4511::_high()
{
  if (_inverse)
  {
    return 0;
  }
  return 1;
}

uint8_t CD4511::_low()
{
  if (_inverse)
  {
    return 1;
  }
  return 0;
}

