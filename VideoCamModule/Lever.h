#pragma once

#include "Timings.h"
#include <Arduino.h>

#ifndef LEVER_H
#define LEVER_H

class Lever {
public:
    Lever(int pinNumber, Timings *timings);

    Lever();

    bool isChangedFlag = false;

    const Lever &operator=(const Lever &B);

    bool isOn();

    bool isDoubleClicked();

    unsigned long getLastTimeTurnedOff();

    unsigned long getLastTimeTurnedOn();

    void checkState();

private:
    Timings *timings;
    bool state = false;
    bool doubleClicked = false;
    int pinNumber = -1;
    unsigned long lastTimeChanged = 0;
    unsigned long lastTimeTurnedOn = 0;
    unsigned long lastTimeTurnedOff = 0;

    bool isDoubleClicking(unsigned long timeStamp);
};

#endif