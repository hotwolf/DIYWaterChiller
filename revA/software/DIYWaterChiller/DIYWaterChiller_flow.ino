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

//IO definitions
#define FLOW_IN   2
#define FLOW_OUT  3

//Sensor definitions
#define FLOW_CNT_TO_FLOWRATE 2*23 //2*23 pulses/sec => 1/min (both edges)

//Flow sensor data
typedef struct {
        uint8_t  inlet;       //Inlet flow rate [pulse/s]
        uint8_t  outlet;      //Outlet flow rate [pulse/s]
} flow_data_t;

flow_data_t  flow_data[3]  = {{0,0},{0,0},{0,0}};
flow_data_t *flow_dataNext = &flow_data[2];     //Upcoming status
flow_data_t *flow_dataCur  = &flow_data[1];     //Current status
flow_data_t *flow_dataPrev = &flow_data[0];     //Previous status

//IO setup
void flow_IoSetup() {
  //Configure inputs
  pinMode(FLOW_IN,  INPUT_PULLUP);  
  pinMode(FLOW_OUT, INPUT_PULLUP);
}

//Start flow sensors
void flow_setup() {
  //Enable ISRs
  attachInterrupt(digitalPinToInterrupt(FLOW_IN),  ISR_flow_inlet,  CHANGE); //Count both edges
  attachInterrupt(digitalPinToInterrupt(FLOW_OUT), ISR_flow_outlet, CHANGE); //Count both edges
}

//ISRs
//Flow meter inlet event
void ISR_flow_inlet() {
   flow_dataNext->inlet++;
}

//Flow meter outlet event
void ISR_flow_outlet () {
    flow_dataNext->outlet++;
}

//Capture sensor data
void flow_capture() {
  //Swap sensor data  
  flow_dataPrev = flow_dataCur;
  flow_dataCur  = flow_dataNext;
  flow_dataNext->inlet  = 0;
  flow_dataNext->outlet = 0;
}

//Check if readings have changed
bool flow_newInletData() {
  return (flow_dataPrev->inlet != flow_dataCur->inlet);
}
bool flow_newOutletData() {
  return (flow_dataPrev->outlet != flow_dataCur->outlet);
}

//Get current flow rate in l/min
float flow_getInletFlowRate() {
  return flow_dataCur->inlet / (FLOW_CNT_TO_FLOWRATE);
}
float flow_getOutetFlowRate() {
  return flow_dataCur->outlet / (FLOW_CNT_TO_FLOWRATE);
}



