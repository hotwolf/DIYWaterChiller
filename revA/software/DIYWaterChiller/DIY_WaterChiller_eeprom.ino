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
//#    This project makes use of the NopSCADlib library                         #
//#    (see https://github.com/nophead/NopSCADlib).                             #
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
#include <EEPROM.h>

//Address locations
const uint16_t eeprom_recAddr = 0;

//EEprom record 
typedef struct {
  uint8_t check;   
  uint8_t tempAddrs[4][8] = {{0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},        
                             {0,0,0,0,0,0,0,0},  
                             {0,0,0,0,0,0,0,0}};
} eeprom_rec_t;
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
inline bool eeprom_checkRec() __attribute__((always_inline));
bool eeprom_checkRec() {
   return (eeprom_rec.check == eeprom_calcCheck());
}

//Store EEPROM record
inline void eeprom_flushRec() __attribute__((always_inline));
void eeprom_flushRec() {
   eeprom_rec.check = eeprom_calcCheck();
   EEPROM.put(eeprom_recAddr, eeprom_rec);
}

//Get temp sensor addresses
inline uint8_t* eeprom_getTempAddrs() __attribute__((always_inline));
uint8_t* eeprom_getTempAddrs() {
   return (uint8_t*)eeprom_rec.tempAddrs;
}
