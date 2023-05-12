//###############################################################################
//# DIYWaterChiller - Firmware - Controller                                     #
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
//#   Firmware for the DIYWaterChiller (dontroller functions)                   #
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
#include <TimerTwo.h>


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

typedef struct {
        uint8_t  in;       //Inlet flow rate [pulse/s]
        uint8_t  out;      //Outlet flow rate [pulse/s]
} flowSensors

flowSensors[3] flowSense_mem;
flowSensors   *flowSensors_next;     //upcoming status
flowSensors   *flowSensors_current;  //Current status
flowSensors   *flowSensors_previous; //Previous status

//Actuator data
typedef struct
{
        uint16_t in_pump;       //Inlet pump strength [100%/1023]
        uint16_t out_pump;      //Ou sensors_next->in_flow = 0;tlet pump strength [100%/1023]
        bool     enable_laser;  //Relais control 
} actuators

actuators[3] actuator_mem;
actuators   *actuators_next;     //upcoming status
actuators   *actuators_current;  //Current status
actuators   *actuators_previous; //Previous status

//Control cycle
bool start_cycle; //Start new iteration

