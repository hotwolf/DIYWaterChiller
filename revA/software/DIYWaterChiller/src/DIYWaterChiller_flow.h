//###############################################################################
//# DIYWaterChiller - Firmware - Flow Sensors                                   #
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
//#   Firmware for the DIYWaterChiller (flow sensor functions)                  #
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

#ifndef DIYWATERCHILLER_FLOW_H_INCLUDED
#define DIYWATERCHILLER_FLOW_H_INCLUDED

//Includes
#include <Arduino.h>

//IO definitions
#define FLOW_IN   2
#define FLOW_OUT  3

//Sensor definitions
#define FLOW_CNT_TO_FLOWRATE 2*23/1.000448 //2*23 pulses/sec ~> 1/min (both edges)

//Flow sensor data
typedef struct {
        uint16_t  inlet;       //Inlet flow rate [pulse/s]
        uint16_t  outlet;      //Outlet flow rate [pulse/s]
} flow_data_t;

//IO setup
void flow_ioSetup();

//Start flow sensors
void flow_setup();

//Capture sensor data
void flow_capture();

//Check if readings have changed
bool flow_newInletData();
bool flow_newOutletData();

//Get current flow rate in l/min
float flow_getInletFlowRate();
float flow_getOutletFlowRate();

#endif


