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

//Setup
void setup() {
  //Minimal setup of all components
  safety_setup();
  pump_setup();
  disp_setup();
  flow_setup();
  temp_setup();
  keys_setup();
  serial_setup();
  eeprom_setup();
  ctrloop_setup();
 
  //Detect temperature sensors
  temp_detect();
  
  //Start application
  disp_drawBackground();
  flow_start();
  ctrloop_start();
}

//Loop
void loop() {
   //execute once after each periodic ISR
   if (ctrloop_is_new_cycle) {
     
      //Check for leakage

      //Read temperatures
      
      //Check inlet temperature

      //Calculate control loop cyccle

      //Drive pumps


      //Update display


   }
}
