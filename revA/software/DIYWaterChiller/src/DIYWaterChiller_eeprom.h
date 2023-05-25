//###############################################################################
//# DIYWaterChiller - Firmware - EEPROM                                         #
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
//#   Firmware for the DIYWaterChiller (EEPROM functions)                       #
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

//Libraries
#include <Arduino.h>
#include <EEPROM.h>

//EEprom record 
typedef struct {
  uint8_t check;   
  uint8_t tempAddrs[4][8] = {{0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},        
                             {0,0,0,0,0,0,0,0},  
                             {0,0,0,0,0,0,0,0}};
} eeprom_rec_t;

//Minimal setup
void eeprom_setup();

//Calculate check byte
uint8_t eeprom_calcCheck();

//Check if an EEPROM record is correct
bool eeprom_checkRec();

//Store EEPROM record
void eeprom_flushRec();

//Get temp sensor addresses
uint8_t* eeprom_getTempAddrs();
