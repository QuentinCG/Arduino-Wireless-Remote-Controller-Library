/*
 * \brief Check data from wireless remote controller every second
 *
 * This method is unsafe as you may not catch some of the sent data
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <WirelessRemoteController.h>

// Create wireless remote controller instance with D3, D4, D5, D6 pins as data pins
WirelessRemoteController remote_controller(3, 4, 5, 6);

void setup(void)
{
  Serial.begin(9600);
}

void loop()
{
  // Check remote controller data every second

  bool current_rx[4];
  if(remote_controller.getCurrentValue(current_rx)) {
    Serial.print("Data received: ");
    for (int i = 0; i < 4; i++) {
      Serial.print(current_rx[i]);
      Serial.print(" ");
    }
    Serial.print("\n");
  } else {
    Serial.print("No relevant data received\n");
  }

  delay(1000);
}
