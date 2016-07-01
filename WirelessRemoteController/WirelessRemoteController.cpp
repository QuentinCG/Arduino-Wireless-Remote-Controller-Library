/*
 * \brief Receive data from wireless remote controller (implementation)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include "WirelessRemoteController.h"

WirelessRemoteController::WirelessRemoteController(int pin_D0, int pin_D1, int pin_D2, int pin_D3)
{
  _pins[0] = pin_D0;
  _pins[1] = pin_D1;
  _pins[2] = pin_D2;
  _pins[3] = pin_D3;

  for (int i = 0; i < 4; i++) {
    pinMode(_pins[i], INPUT);
  }
}

bool WirelessRemoteController::getCurrentValue(bool data[4])
{
  bool is_valid = false;

  for (int i = 0; i < 4; i++) {
    data[i] = digitalRead(_pins[i]);
    is_valid |= data[i];
  }

  return is_valid;
}

void WirelessRemoteController::addTrigger(int pin_DT, void (*function)())
{
  attachInterrupt(digitalPinToInterrupt(pin_DT), function, RISING);
}
