/*
 * \brief Get data from wireless remote controller asynchronously (interrupts)
 *
 * This example is using the trigger signal from the remote controller to
 * asynchronously launch a function every time a data is received.
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 27 December 2021
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2021 Quentin Comte-Gaz
 * \version 1.0
 */

#include <WirelessRemoteController.h>

// Create wireless remote controller instance with D3, D4, D5, D6 pins as data pins
WirelessRemoteController remote_controller(3, 4, 5, 6);

void receiveFromRemoteController()
{
  bool current_rx[4];
  if(remote_controller.getCurrentValue(current_rx))
  {
    Serial.print("Data received: ");
    for (int i = 0; i < 4; i++)
    {
      Serial.print(current_rx[i]);
      Serial.print(" ");
    }
    Serial.print("\n");
  }
  else
  {
    Serial.print("No data received (!!should not happen!!)\n");
  }
}

void setup(void)
{
  Serial.begin(9600);

  // Trigger interrupt by putting D2 pin as DT remote controller pin (trigger)
  remote_controller.addTrigger(2, receiveFromRemoteController);

  Serial.print("Data sent from remote controller will be printed when received.\n");
}

void loop()
{
  // Nothing to do in loop since everything is asynchronous
}
