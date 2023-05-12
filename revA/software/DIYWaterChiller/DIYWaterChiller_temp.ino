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

//Libraries
#include <OneWire.h>
#include <DS18B20.h>

//Sensor data
typedef struct {
        float    cold;     //Water temperature in the cold tank [°C]
        float    warm;     //Water temperature in the warm tank [°C]
        float    in;       //Inlet water temperature [°C]
        float    out;      //Outlet water temperature [°C]
} tempSensors
tempSensors[2] tempSense_mem;
tempSensors   *tempSense_current;  //Current status
tempSensors   *tempSense_previous; //Previous status

DS18B20          ds(ONEWIRE_PIN);

//Minimal setup
inline void setup_DS18B20s() __attribute__((always_inline));
void setup_DS18B20s() {

}

//Detect temperature sensors
inline void detect_DS18B20s() __attribute__((always_inline));
void detect_DS18B20s() {

  //Check if sensors have been detected before
  bool detection_required = false;

  //Check for EEPROM record
  if(EEPROM_record_exists) {
    //Check if 4 temp sensors are connected
    if (ds.getNumberOfDevices() == 4) {
      //Check if sensors are known
      while (!detection_required && ds.selectNext()) {
        //Check family code
        if (ds.getFamilyCode() == MODEL_DS18B20) {
          if (!is_known_tempSense(ds.getAddress(address))) {
             detection_required = true; //Unknown sensor address
          }
        } else {
          detection_required = true; //One sensor model
        }
      }
    } else  {
      detection_required = true; //Wrong number of sensors connected
    }
  } else {
    detection_required = true; //No EEPROM record
  }

  //Run sensor detection if required
  if (detection_required) {
    //Step 1: Unplug all temperature sensors
    draw_DS18B20_detection_screen1()                   //Prompt for action
    while (ds.getNumberOfDevices() != 0) {delay(500);} //Wait until all sensors are unplugged

    //Step 2: Plug in ininlet sensors
    draw_DS18B20_detection_screen2()                   //Prompt for action
    while (ds.getNumberOfDevices() == 1) {delay(500);} //Wait until one sensor is plugged in

    //Step 3: Plug in outlet sensors
    draw_DS18B20_detection_screen3()                   //Prompt for action
    while (ds.getNumberOfDevices() == 2) {delay(500);} //Wait until two sensors are plugged in

    //Step 4: Plug in cold water sensors
    draw_DS18B20_detection_screen4()                   //Prompt for action
    while (ds.getNumberOfDevices() == 3) {delay(500);} //Wait until three sensor are plugged in

    //Step 5: Plug in cold water sensors
    draw_DS18B20_detection_screen4()                   //Prompt for action
    while (ds.getNumberOfDevices() == 4) {delay(500);} //Wait until four sensor are plugged in





  }

}

