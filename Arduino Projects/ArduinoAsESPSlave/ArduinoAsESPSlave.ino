/****************************************************************************************************************************\
   
   ***MODEFIED BY Mohamed Asim  @ 15/4/2019
   
   Arduino project "ESP Easy"  Copyright www.esp8266.nu

   This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
   You received a copy of the GNU General Public License along with this program in file 'License.txt'.

   IDE download    : https://www.arduino.cc/en/Main/Software
   ESP8266 Package : https://github.com/esp8266/Arduino

   Source Code     : https://sourceforge.net/projects/espeasy/
   Support         : http://www.esp8266.nu
   Discussion      : http://www.esp8266.nu/forum/

   Additional information about licensing can be found at : http://www.gnu.org/licenses
  \*************************************************************************************************************************/

// This file is to be loaded onto an Arduino Pro Mini so it will act as a simple IO extender to the ESP module.
// Communication between ESP and Arduino is using the I2C bus, so only two wires needed.
// It best to run the Pro Mini on 3V3, although the 16MHz versions do not officially support this voltage level on this frequency.
// That way, you can skip levelconverters on I2C.
// Arduino Mini Pro uses A4 and A5 for I2C bus. ESP I2C can be configured but they are on GPIO-4 and GPIO-5 by default.

#include <Wire.h>

#define I2C_MSG_IN_SIZE    4
#define I2C_MSG_OUT_SIZE   4

#define CMD_DIGITAL_WRITE  1
#define CMD_DIGITAL_READ   2
#define CMD_ANALOG_WRITE   3
#define CMD_ANALOG_READ    4

/*************************************************************************************************************************/

#include <Servo.h>

#define Servo_port 40       //if port is 40 then excute servo task  
Servo myservo;  // create servo object to control a servo

#define dc_motor_pwm 50         //if port is 50 then excute dc motor task (speed)
#define line_follower 100       //if port is 100 then excute dc line follower task
#define buzzer_task 46
#define led_task 45
#define forward_task 51
#define reverse_task 52

#define servo_pin 9           //
#define ena        6           // l298 en pin connected to arduino
#define forward_pin      5           // l298 forward pin connected to arduino
#define reverse_pin      4           // l298 reverse pin connected to arduino
#define led_pin        3       // led pin connected to arduino
#define buzzer_pin       2      // buzzer pin connected to arduino

/*************************************************************************************************************************/
volatile uint8_t sendBuffer[I2C_MSG_OUT_SIZE];

void setup()
{
  myservo.attach(servo_pin);

  Wire.begin(0x7f);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void loop() {}

void receiveEvent(int count)
{
  if (count == I2C_MSG_IN_SIZE)
  {
    byte cmd = Wire.read();
    byte port = Wire.read();
    int value = Wire.read();
    value += Wire.read() * 256;
    switch (cmd)
    {
      case CMD_DIGITAL_WRITE:

/*************************************************************************************************************************/
      
        if (port == Servo_port) {           // excute servo
            myservo.write(70 + (value * 2));             // sets the servo position according to the scaled value
          delay(5);
        }
        else if (port == dc_motor_pwm) {          // excute
          analogWrite(ena, value * 2);
        }
        else if (port == led_task) {          // excute
          digitalWrite(led_pin, value);
        }
        else if (port == buzzer_task) {          // excute
          digitalWrite(buzzer_pin, value);
        }
         else if (port == forward_task) {          // excute
          digitalWrite(forward_pin, value);
        }
        else if (port == reverse_task) {          // excute
          digitalWrite(reverse_pin, value);
        }
        else if (port == line_follower) {          // excute
          if (value==1){
            //exute line follower
          }
          else {
            //disable line follower 
          }
        }

 
/*************************************************************************************************************************/       
        else
        {
          pinMode(port, OUTPUT);
          digitalWrite(port, value);
        }
        break;
      case CMD_DIGITAL_READ:
        pinMode(port, INPUT_PULLUP);
        clearSendBuffer();
        sendBuffer[0] = digitalRead(port);
        break;
      case CMD_ANALOG_WRITE:
        analogWrite(port, value);
        break;
      case CMD_ANALOG_READ:
        clearSendBuffer();
        int valueRead = analogRead(port);
        sendBuffer[0] = valueRead & 0xff;
        sendBuffer[1] = valueRead >> 8;
        break;
    }
  }
}

void clearSendBuffer()
{
  for (byte x = 0; x < sizeof(sendBuffer); x++)
    sendBuffer[x] = 0;
}

void requestEvent()
{
  Wire.write((const uint8_t*)sendBuffer, sizeof(sendBuffer));
}

