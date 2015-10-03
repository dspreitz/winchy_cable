/* 
    This file is part of
    
    Winchy Cable Segment Software (Winchy)
    
    Authors:
    <Dominic Spreitz>

    Winchy is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Winchy is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <HMC58X3.h>
#include <MS561101BA.h>
#include <I2Cdev.h>
#include <MPU60X0.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

//#define DEBUG
#include "DebugUtils.h"
#include "CommunicationUtils.h"
#include "FreeIMU.h"
#include <Wire.h>
#include <SPI.h>

float q[4];
float values[8];

// Set the FreeIMU object
FreeIMU my3IMU = FreeIMU();
SoftwareSerial XBee(0, 1); // RX, TX // Configures Software Serial Port for XBee

void setup() {
  Serial.begin(115200); // Opens Serial Port
  XBee.begin(9600); // Opens Software Serial Port XBee 
  Wire.begin();
  
  delay(5);
  my3IMU.init();
  delay(5);
  my3IMU.calLoad();
}

void loop() { 
  // XBee.print("Test");
  my3IMU.getQ(q);
  my3IMU.getValues(values);
  // serialPrintFloatArr(q, 4);
  // serialPrintFloatArr(values, 2);
  Serial.println(values[9]);
  Serial.println(values[10]);
  XBee.println(values[9]);
  XBee.println(values[10]);
  //Serial.println(magn_scale_z);
  delay(2000);
  
}


