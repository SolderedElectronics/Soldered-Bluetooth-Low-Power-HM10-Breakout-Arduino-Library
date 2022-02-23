/**
 **************************************************
 *
 * @file        ReceiveAndSendData.ino
 * @brief       Example for Bluetooth Low Energy breakout, for this you will need some king of app on mobile to
 *comunicate with breakout
 *
 *
 *
 * @authors     @ soldered.com
 * @link        www.solde.red/101685
 ***************************************************/

#include "BLE-SOLDERED.h"

// Define pins as transmitter and receiver
// must be same as pins that module is connected to Soldered Microcontroller
int BT_RX = 2;  //This library is based on SoftwareSerial library,
int BT_TX = 3;  //so refer to documentation of that library for more details
int baudrate = 9600;

String msg;

// LED initialisation
#define LED 9

BLE bt(BT_RX, BT_TX); //Create instance of class and specify pins for UART 
                      //communication with BLE module

void setup()
{
  bt.begin(baudrate);  //Start serial communication with BLE module using 9600 bauds/s
  bt.println("Bt is on");
  pinMode(LED, OUTPUT);  //Set pin LED to OUTPUT mode,
                           //so LED can be turned on and off
} 
// Wait for message
// analise it and then either turn LED on or off

void loop()
{
    if (bt.available())        //Check if BLE is available for communication
    {
        msg = bt.readString(); // Read data
        if (msg == "on")  //If received message is "on"
        {
            digitalWrite(LED, HIGH);  //Turn on LED
            bt.print("LED");          //Send feedback information
            bt.print(LED);
            bt.println("On!");
        }
        else if (msg == "off")  //If received message is "off"
        {
            digitalWrite(LED, LOW);  //Turn on LED
            bt.print("LED");         //Send feedback information
            bt.print(LED);
            bt.println("Off!");
        }
        else
        {
            bt.print("N/A"); // Send feedback information that
                             // unknown command is received
        }
    }
}
