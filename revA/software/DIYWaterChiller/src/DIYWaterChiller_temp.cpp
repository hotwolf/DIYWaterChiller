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

//Includes
#include "DIYWaterChiller_temp.h"

//Temperature data
float  temp_data[2][4] = {{NAN,NAN,NAN,NAN},{NAN,NAN,NAN,NAN}};
float *temp_dataCur    = temp_data[1];
float* temp_dataPrev   = temp_data[0];

//OneWire and DallasTemperature objects
OneWire           ow(ONEWIRE_PIN);
DallasTemperature temp(&ow);

//IO setup
void temp_ioSetup() {
}

//Start temp sensors
void temp_setup() {

  //Get sensor address list
  uint8_t* devAddrs = eeprom_getTempAddrs();
  //Serial.print(F("devAddrs: "));
  //Serial.println((int)devAddrs,HEX);
 
  //Check if all known sensors are connected
  while (!temp_valDevAddrs(devAddrs)) {

    //New sensor detection

    //1st step: All sensors must be unplugged
    //Serial.println(F("Unplug all sensors"));
    if (temp_anyDev()) {
      disp_disconMsg();       //Prompt to unplug all sensors
      while (temp_anyDev()) { //Wait until all sensors are unplugged
	 delay(100);
      }
    }
    disp_clrMsg();
    //Serial.println(F("done"));

    //2nd step: Register the sensors one by one
    //disp_conMsg();              //Prompt to connect indicated sensors
    for (uint8_t i=0; i<4; i++) {
      disp_markTemp(i, false);  //Show next sensor to be plugged in
      while (!temp_findNewDev(i, devAddrs)) {
	delay(100);
      }
      disp_markTemp(i, true);   //Flag sensor as registerd
    }

    //3rd step: Store sensor information in EEPROM
    eeprom_flushRec();           //Flush EEPROM
   
  }

  //Set 12bit resolution
  for (uint8_t i=0; i<3; i++) {
    if (temp.getResolution(devAddrs+(i*8)) != 12) {
      temp.setResolution(devAddrs+(i*8),12,true);
    }
  }

  //Do initial conversion
  temp.setWaitForConversion(true);
  temp.requestTemperatures();
  temp.setWaitForConversion(false);
  
}

//Validate address list
uint8_t temp_valDevAddrs(uint8_t* devAddrs) {
  //Check if a valid EEPROM record exists
  if (eeprom_checkRec()) {
    //Check each address entry
    for (uint8_t i=0; i<4; i++) {
      if (!temp.isConnected(devAddrs+(i*8))) {
        //Serial.println(F("Sensor mismatch"));
        temp_printAddr("Sensor mismatch", devAddrs+(i*8));
	return false;;
      }
    }
    Serial.println(F("EEPROM data valid"));
    return true;
  }
  Serial.println(F("EEPROM data invalid"));
  return false;
}

//Check if any sensor is connected
bool temp_anyDev() {
  ow.reset_search();
  uint8_t dummy[8];
  bool result = ow.search(dummy);
  temp_printAddr("dummy ", dummy);
  Serial.print(F("result: "));
  Serial.println(result,DEC);


  
  return result;
  return  ow.search(dummy);
}

//Find new sensor
bool temp_findNewDev(uint8_t index, uint8_t* devAddrs) {
  bool newSensor;
  ow.reset_search();
  //Serial.print(F("index: "));
  //Serial.println(index,DEC);
  //Serial.print(F("devAddrs: "));
  //Serial.println((int)devAddrs+(index*8),HEX);
  while (ow.search(devAddrs+(index*8))) {
    //temp_printAddr("detected:", devAddrs+(index*8));   
    newSensor = true;
    for (uint8_t i=0; i<index; i++) {  
      if (temp_addrMatch(devAddrs+(i*8),devAddrs+(index*8))) {
        newSensor = false;
        break;
      }
    }
    if (newSensor) {
      return true;
    }
  }
  return false;
}

//Compare sensor addresses
bool temp_addrMatch(uint8_t* addrA, uint8_t* addrB) {
  for (uint8_t i=0; i<8; i++) {
    //temp_printAddr("addrA:", addrA);
    //temp_printAddr("addrB:", addrB);    
    if (*(addrA+i) != *(addrB+i)) {
      return false;
    }
  }
  return true;
}

//print sensor addresses
void temp_printAddr(char* label, uint8_t* addr) {
  Serial.print(label);
  for (uint8_t i=0; i<8; i++) {
    Serial.print(" ");
    Serial.print((uint8_t)*addr++,HEX);
  }
  Serial.println("");
}





