//###############################################################################
//# DIYWaterChiller - Firmware - Pumps                                          #
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
//#   Firmware for the DIYWaterChiller (pump functions)                         #
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

#ifndef DIYWATERCHILLER_PUMP_H_INCLUDED
#define DIYWATERCHILLER_PUMP_H_INCLUDED

//IO definitions 
#define PUMP_WARM  10
#define PUMP_COLD   9

//Libraries
#include <Arduino.h>
#include <TimerOne.h>

//Pump drive data
typedef struct {
        uint16_t  cold; //Cold water pump power [0..1023]
        uint16_t  warm; //Warm water pump power [0..1023]
} pump_data_t;

//IO setup
void pump_ioSetup();

//Set pump power
void pump_set(uint16_t cold, uint16_t warm);

//Check if settings have changed
bool pump_newColdData();
bool pump_newWarmData();

//Get current pump power in %
float pump_getColdPower();
float pump_getWarmPower();

#endif
