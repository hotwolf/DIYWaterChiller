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
//#    This project makes use of the NopSCADlib library                         #
//#    (see https://github.com/nophead/NopSCADlib).                             #
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

// Common definitions
#define VERSION_STR "DIYWaterChiller FW00.00"

//Inlined functions
inline void safety_IoSetup()  __attribute__((always_inline));
inline void pump_IoSetup()    __attribute__((always_inline));
inline void sound_IoSetup()   __attribute__((always_inline));
inline void disp_IoSetup()    __attribute__((always_inline));
inline void flow_IoSetup()    __attribute__((always_inline));
inline void temp_IoSetup()    __attribute__((always_inline));
inline void keys_IoSetup()    __attribute__((always_inline));
inline void serial_IoSetup()  __attribute__((always_inline));
inline void eeprom_setup()    __attribute__((always_inline));
inline void temp_setup()      __attribute__((always_inline));
inline void flow_setup()      __attribute__((always_inline));

// inline void eeprom_setup()  __attribute__((always_inline));
// inline void ctrloop_setup() __attribute__((always_inline));

// inline void flow_start() __attribute__((always_inline));
// inline void ctrloop_start() __attribute__((always_inline));

// inline bool ctrloop_is_new_cycle() __attribute__((always_inline));



//Setup
void setup() {
  //Configure IOs
  safety_IoSetup();
  pump_IoSetup();
  sound_IoSetup();
  disp_IoSetup();
  flow_IoSetup();
  temp_IoSetup();
  keys_IoSetup();
  serial_IoSetup();
 
  //Start functions
  eeprom_setup();
  temp_setup();
  flow_setup();


  //Detect temperature sensors
  //temp_detect();
  
  //Start application
  // //disp_drawBackground();
  // flow_start();
  // ctrloop_start();
}

//Loop
void loop() {
   //execute once after each periodic ISR
  //  if (ctrloop_is_new_cycle()) {
     
      //Check for leakage

      //Read temperatures
      
      //Check inlet temperature

      //Calculate control loop cyccle

      //Drive pumps


      //Update display


  //  }
}
