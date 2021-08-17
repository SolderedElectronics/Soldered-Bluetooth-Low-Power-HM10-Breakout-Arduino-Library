/**
 **************************************************
 *
 * @file        ReceiveAndSendData.ino
 * @brief       Example for Bluetooth Low Energy breakout, for this you will need some king of app on mobile to comunicate with breakout
 *
 *
 *
 * @authors     @ soldered.com
 * @link        www.solde.red/101685
 ***************************************************/

#include "BLE-SOLDERED.h"

//Define pins as transmitter and receiver, must be same as pins that module is connected to Soldered Microcontroller
int BT_RX = 2;
int BT_TX = 3;

BLE bt(BT_RX, BT_TX);

String msg;

// LED initialisation
int LED = USER_LED;

void setup() {
  bt.begin(9600);
  bt.println("Bt is on");
  pinMode(LED, OUTPUT);
}
 //Wait for message
 //analise it and then either turn LED on or off
 
void loop() {
  if (bt.available()){      // data available
     msg = bt.readString(); // Read data
     if (msg == "on") {
         digitalWrite(LED, HIGH);
         bt.print("LED");
         bt.print(LED);
         bt.println("On!");
      } 
      else
      if (msg == "off") {
         digitalWrite(LED, LOW);
         bt.print("LED");
         bt.print(LED);
         bt.println("Off!");
      }
      else {
         bt.print("N/A"); //send unknown message arived
      }
    }
}   