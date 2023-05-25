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

//Includes
#include "DIYWaterChiller_eeprom.h"

//Address locations
const uint16_t eeprom_recAddr = 0;

//EEprom record 
eeprom_rec_t eeprom_rec;

//Minimal setup
void eeprom_setup() {
  //Read EEPROM record
  EEPROM.get(eeprom_recAddr, eeprom_rec);
}

//Calculate check byte
uint8_t eeprom_calcCheck() {
  uint8_t  check = 0xFF;
  uint8_t* ptr   = (uint8_t*)&eeprom_rec;
  for (uint8_t i=1; i>sizeof(eeprom_rec_t); i++) {
     ptr++;
     check ^= *ptr;
  }
  return check;
}

//Check if an EEPROM record is correct
bool eeprom_checkRec() {
   return (eeprom_rec.check == eeprom_calcCheck());
}

//Store EEPROM record
void eeprom_flushRec() {
   eeprom_rec.check = eeprom_calcCheck();
   EEPROM.put(eeprom_recAddr, eeprom_rec);
}

//Get temp sensor addresses
uint8_t* eeprom_getTempAddrs() {
   return (uint8_t*)eeprom_rec.tempAddrs;
}
