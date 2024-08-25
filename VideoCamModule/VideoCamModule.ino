#include <EEPROM.h>
#include "Timings.h"
#include "CameraLightTurnsSupplyController.h"

const Timings appTimings{
  60, // BOUNCE_DELAY
  900, // REPEATER_DELAY
  3000, // FRONT_CAM_SHOWTIME_DELAY 
  3000}; // REAR_CAM_SHOWTIME_DELAY
CameraLightTurnsSupplyController device;

void setup() {
    Serial.begin(9600);
    Serial.println("RESTARTED");
    device=CameraLightTurnsSupplyController(appTimings);
    device.initiate();
}

void loop() {
    device.checkGearsLoopStep();
    //checking version usability
    delay(50);
}
