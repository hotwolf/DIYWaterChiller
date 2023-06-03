//###############################################################################
//# DIYWaterChiller - Testcase                                                  #
//###############################################################################
//#    Copyright 2023 Dirk Heisswolf                                            #
//#    This file is part of the DIYWaterChiller project.                        #
//#                                                                             #
//#    This project is free software: you can redistribute it and/or modify     #
//#    it under the terms of the GNU General Public License as published by     #
//#    the Free Software Foundation, either version 3 of the License, or        #
//#    (at your option) any later version.                                      #
//#                                                                             #
//#    This project is distributed in the hope that it will be useful,          #
//#    but WITHOUT ANY WARRANTY; without even the implied warranty of           #
//#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
//#    GNU General Public License for more details.                             #
//#                                                                             #
//#    You should have received a copy of the GNU General Public License        #
//#    along with this project.  If not, see <http://www.gnu.org/licenses/>.    #
//#                                                                             #
//###############################################################################
//# Description:                                                                #
//#   Testcase                                                                  #
//#                                                                             #
//#   !!! Set the Sketchbook location to               !!!                      #
//#   !!!  <DIYWaterChiller repository>/revA/software/ !!!                      #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June 4, 2023                                                              #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################

//DS18B20 definitions 
#define ONEWIRE_PIN     4
#define REQUIRESALARMS  false

#define TEMP_COLD       0
#define TEMP_WARM       1
#define TEMP_INLET      2
#define TEMP_OUTLET     3

//Libraries
#include <OneWire.h>
#include <DallasTemperature.h>

//OneWire and DallasTemperature objects
OneWire           ow(ONEWIRE_PIN);
DallasTemperature temp(&ow);

//Print sensor addresse
void printAddr(char* label, uint8_t* addr) {
  Serial.print(label);
  for (uint8_t i=0; i<8; i++) {
    Serial.print(" ");
    Serial.print((uint8_t)*addr++,HEX);
  }
  Serial.println("");
}

//Setup
void setup() { 
  Serial.begin(115200);
  Serial.println(F(""));
  Serial.println(F("#######################"));
  Serial.println(F("   RESET!"));
  Serial.println(F("######################"));
  Serial.println(F(""));
}

//Loop
void loop() {

   //Scan and print sensor addresses
   Serial.println(F("Connected temp sensors: "));
   uint8_t sensorAddress[8];
   while (ow.search(sensorAddress)) {
     printAddr("  -> ", sensorAddress);
   }
   Serial.println(F(""));
   delay(1000);

}




