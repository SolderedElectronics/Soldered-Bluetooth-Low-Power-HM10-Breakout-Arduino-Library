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
  BLE(int _rx , int _tx) : HardwareSerial(1)
  {
    rx = _rx;
    tx = _tx;
  }

  void begin(int _baudrate)
  {
    HardwareSerial::begin( _baudrate, SERIAL_8N1, rx, tx, false, 20000UL);
  }

  protected:
  private:
  int rx, tx;
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