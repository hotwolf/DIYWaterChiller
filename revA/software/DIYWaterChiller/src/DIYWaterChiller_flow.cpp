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
//#    This project makes use of the NopSCADlib library                         #
//#    (see https://github.com/nophead/NopSCADlib).                             #
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

//Includes
#include "DIYWaterChiller_flow.h"

//Variables
flow_data_t  flow_data[3]  = {{0,0},{0,0},{0,0}};
flow_data_t *flow_dataNext = &flow_data[2];     //Upcoming status
flow_data_t *flow_dataCur  = &flow_data[1];     //Current status
flow_data_t *flow_dataPrev = &flow_data[0];     //Previous status

//IO setup
void flow_ioSetup() {
  //Configure inputs
  pinMode(FLOW_IN,  INPUT_PULLUP);  
  pinMode(FLOW_OUT, INPUT_PULLUP);
}

//Start flow sensors
void flow_setup() {
  //Enable ISRs
  EICRA = (1 << ISC10)|(1 << ISC00); //Trigger interrupts on any edge
  EIFR  = (1 << INTF1)|(1 << INTF0); //Clear interrupt flags
  EIMSK = (1 << INT1) |(1 << INT0);  //Enable interrupts
}

//Capture sensor data
void flow_capture() {
  //Swap sensor data
  flow_data_t *tmp = flow_dataPrev;
  tmp->inlet  = 0;
  tmp->outlet = 0;
  flow_dataPrev = flow_dataCur;
  flow_dataCur  = flow_dataNext;
  flow_dataNext = tmp;
}

//Check if readings have changed
bool flow_newInletData() {
  return (flow_dataPrev->inlet != flow_dataCur->inlet);
}
bool flow_newOutletData() {
  return (flow_dataPrev->outlet != flow_dataCur->outlet);
}

//Get current flow rate in l/min
float flow_getInletData() {
  return (float)flow_dataCur->inlet * FLOW_CNT_TO_FLOWRATE;
}
float flow_getOutletData() {
  return (float)flow_dataCur->outlet * FLOW_CNT_TO_FLOWRATE;
}
float flow_getAvgData() {
  return (float)((flow_dataCur->inlet + flow_dataCur->outlet) * (FLOW_CNT_TO_FLOWRATE/2));
}

//Interrupt service routines
//Flow meter inlet event
ISR(INT0_vect){ 
   flow_dataNext->inlet++;

}
//Flow meter outlet event
ISR(INT1_vect){
  (flow_dataNext->outlet)++;
}
