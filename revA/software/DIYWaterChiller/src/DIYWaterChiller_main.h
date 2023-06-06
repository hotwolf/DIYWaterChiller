//###############################################################################
//# DIYWaterChiller - Firmware                                                  #
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
//#   Firmware for the DIYWaterChiller                                          #
//#                                                                             #
//#   !!! Set the Sketchbook location to               !!!                      #
//#   !!!  <DIYWaterChiller repository>/revA/software/ !!!                      #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   May 4, 2023                                                               #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################

#ifndef DIYWATERCHILLER_MAIN_H_INCLUDED
#define DIYWATERCHILLER_MAIN_H_INCLUDED

//Includes
#include <Arduino.h>
#include "DIYWaterChiller_disp.h"
#include "DIYWaterChiller_flow.h"
#include "DIYWaterChiller_temp.h"
#include "DIYWaterChiller_pump.h"
#include "DIYWaterChiller_serial.h"
#include "DIYWaterChiller_safety.h"
#include "DIYWaterChiller_eeprom.h"
#include "DIYWaterChiller_sound.h"
#include "DIYWaterChiller_keys.h"

//Common definitions
#define PERINT_CYC_CNT 977 //Cycle count of the periodic interrupt to approximate one second

//Setup
void main_setup();

//Loop
void main_loop();

//Reset
void main_reset(); 

#endif

