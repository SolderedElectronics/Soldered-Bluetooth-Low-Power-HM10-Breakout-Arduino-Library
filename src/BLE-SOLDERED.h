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
#include "SoftwareSerial.h"

class BLE : public SoftwareSerial
{
  public:
    SoftwareSerial::SoftwareSerial;

  protected:
  private:
};

#endif
