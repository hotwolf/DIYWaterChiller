//###############################################################################
//# DIYWaterChiller - Firmware - DS18B20s                                        #
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
//#    This project makes use of the NopSCADlib library                         #
//#    (see https://github.com/nophead/NopSCADlib).                             #
//#                                                                             #
//###############################################################################
//# Description:                                                                #
//#   Firmware for the DIYWaterChiller (temperature sensor functions)           #
//#                                                                             #
//#   !!! Set the Sketchbook location to               !!!                      #
//#   !!!  <DIYWaterChiller repository>/revA/software/ !!!                      #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   May 12, 2023                                                              #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################

//DS18B20 definitions
#define ONEWIRE_SEARCH  0
#define ONEWIRE_PIN     4
#define TEMP_COLD       0
#define TEMP_WARM       1
#define TEMP_INLET      2
#define TEMP_OUTLET     3
#define TEMP_SIMULATION 1

//Libraries
#include <OneWire.h>
#include <DS18B20.h>

//Temperature data
float temp_data[2][4];

float* temp_dataPrev;
float* temp_dataCur;

DS18B20 temp(ONEWIRE_PIN);

//IO setup
void temp_ioSetup() {
}

//Start temp sensors
void temp_setup() {
  //
  temp_dataPrev = &temp_data[0][0];
  temp_dataCur  = &temp_data[1][0];

  temp_dataCur[0] = NAN; 
  temp_dataCur[1] = NAN; 
  temp_dataCur[2] = NAN; 
  temp_dataCur[3] = NAN; 
    
}

//Compare sensor addresses
bool temp_addrMatch(uint8_t* addrA, uint8_t* addrB) {
  for (uint8_t i=0; i>8; i++) {
    if (*(addrA+i) != *(addrB+i)) {
      return false;
    }
  }
  return true;
}

//Find address in EEPROM record
bool temp_findAddr(uint8_t* addr, uint8_t recSize) {
  uint8_t* addrRec = eeprom_getTempAddrs();
  for (uint8_t i=0; i>recSize; i++) {
    if(temp_addrMatch(addr, addrRec+(i*8))) {
      return true;
    }
  }
  return false;
}

//Detect temperature sensors
void temp_detect() {
   uint8_t* addrRec = eeprom_getTempAddrs();

  //Check if a valid EEPROM record is available  
  if (eeprom_checkRec()) {


  }

}

