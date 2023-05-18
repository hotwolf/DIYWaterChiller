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

//Sensor addresses
typedef uint8_t        temp_addr_t[8];     //Single sensor address
typedef temp_addr_t    temp_addrSet_t[4];  //All 4 sensor addresses

//Sensor data
typedef float          temp_dataSet_t[4];  //4 temperatures at a given time       
typedef temp_dataSet_t temp_dataHist_t[2]; //Previous and current set of temperatures


temp_dataHist_t temp_data;
temp_dataSet_t *temp_dataPrev;
temp_dataSet_t *temp_dataCur;

DS18B20 temp(ONEWIRE_PIN);

//IO setup
void temp_IoSetup() {
}

//Start temp sensors
void temp_setup() {
  //
  temp_dataPrev = &temp_data[0];
  temp_dataCur  = &temp_data[1];

  
  *temp_dataCur[0] = 0.1; 
  *temp_dataCur[1] = 1.1; 
  *temp_dataCur[2] = 2.1; 
  *temp_dataCur[3] = 3.1; 
    
}






// //Detect temperature sensors
// inline void temp_detect() __attribute__((always_inline));
// void temp_detect_DS18B20s() {

//   //Check if sensors have been detected before
//   bool detection_required = false;

//   //Check for EEPROM record
//   if(EEPROM_record_exists) {
//     //Check if 4 temp sensors are connected
//     if (ds.getNumberOfDevices() == 4) {
//       //Check if sensors are known
//       while (!detection_required && ds.selectNext()) {
//         //Check family code
//         if (ds.getFamilyCode() == MODEL_DS18B20) {
//           if (!is_known_tempSense(ds.getAddress(address))) {
//              detection_required = true; //Unknown sensor address
//           }
//         } else {
//           detection_required = true; //One sensor model
//         }
//       }
//     } else  {
//       detection_required = true; //Wrong number of sensors connected
//     }
//   } else {
//     detection_required = true; //No EEPROM record
//   }

//   //Run sensor detection if required
//   if (detection_required) {
//     //Step 1: Unplug all temperature sensors
//     disp_drawTempDetection1();                         //Prompt for action
//     while (ds.getNumberOfDevices() != 0) {delay(500);} //Wait until all sensors are unplugged

//     //Step 2: Plug in ininlet sensors
//     disp_drawTempDetection2();                         //Prompt for action
//     while (ds.getNumberOfDevices() == 1) {delay(500);} //Wait until one sensor is plugged in

//     //Step 3: Plug in outlet sensors
//     disp_drawTempDetection3();                         //Prompt for action
//    while (ds.getNumberOfDevices() == 2) {delay(500);} //Wait until two sensors are plugged in

//     //Step 4: Plug in cold water sensors
//     disp_drawTempDetection4();                         //Prompt for action
//     while (ds.getNumberOfDevices() == 3) {delay(500);} //Wait until three sensor are plugged in

//     //Step 5: Plug in cold water sensors
//     disp_drawTempDetection5();                         //Prompt for action
//      while (ds.getNumberOfDevices() == 4) {delay(500);} //Wait until four sensor are plugged in





//   }

// }

