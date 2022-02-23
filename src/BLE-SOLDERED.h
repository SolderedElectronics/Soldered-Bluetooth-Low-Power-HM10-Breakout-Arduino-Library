/**
 **************************************************
 *
 * @file        BLE-SOLDERED.h
 * @brief       Header file for Bluetooth Low Energy module.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     @ soldered.com, Robert Peric
 ***************************************************/

#ifndef _BLE_H
#define _BLE_H

#include "Arduino.h"

#ifdef ARDUINO_ESP32_DEV

class BLE : public HardwareSerial
{
  public:
    using HardwareSerial::HardwareSerial;

  protected:
  private:
};


#else

#include "SoftwareSerial.h"


class BLE : public SoftwareSerial
{
  public:
    using SoftwareSerial::SoftwareSerial;

  protected:
  private:
};

#endif //#ifdef ARDUINO_ESP32_dEV

#endif //