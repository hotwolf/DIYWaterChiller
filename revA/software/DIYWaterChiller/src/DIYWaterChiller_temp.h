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

#ifndef DIYWATERCHILLER_TEMP_H_INCLUDED
#define DIYWATERCHILLER_TEMP_H_INCLUDED

//DS18B20 definitions 
#define ONEWIRE_PIN     4
#define REQUIRESALARMS  false

#define TEMP_COLD       0
#define TEMP_WARM       1
#define TEMP_INLET      2
#define TEMP_OUTLET     3

//Libraries
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DIYWaterChiller_eeprom.h"
#include "DIYWaterChiller_disp.h"
#include "DIYWaterChiller_sound.h"

//IO setup
void temp_ioSetup();

//Start temp sensors
void temp_setup();

//Validate address list
uint8_t temp_valDevAddrs(uint8_t* devAddrs);

//Check if any sensor is connected
bool temp_anyDev();

//Find new sensor
bool temp_findNewDev(uint8_t index, uint8_t* devAddrs);

//Compare sensor addresses
bool temp_addrMatch(uint8_t* addrA, uint8_t* addrB);

//print sensor addresses
void temp_printAddr(char* label, uint8_t* addr);

//Capture sensor data
void temp_capture();  

//Check if readings have changed
bool temp_newColdData();
bool temp_newWarmData();
bool temp_newInletData();
bool temp_newOutletData();

//Get temoerature in °C
float temp_getColdData();
float temp_getWarmData();
float temp_getInletData();
float temp_getOutletData();

#endif
