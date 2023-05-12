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
        uint8_t  in;       //Inlet flow rate [pulse/s]
        uint8_t  out;      //Outlet flow rate [pulse/s]
} flowSensors

flowSensors[3] flowSense_mem;
flowSensors   *flowSensors_next;     //upcoming status
flowSensors   *flowSensors_current;  //Current status
flowSensors   *flowSensors_previous; //Previous status

//Minimal setup
inline void setup_FlowSensors() __attribute__((always_inline));
void setup_FlowSensors() {
  //Configure inputs
  pinMode(FLOW_IN,  INPUT_PULLUP);  
  pinMode(FLOW_OUT, INPUT_PULLUP);
}

//Start flow sensors
inline void start_FlowSensors() __attribute__((always_inline));
void start_FlowSensors() {
  //Initialize counters
  flowSensors_current->in  = 0;
  flowSensors_current->out = 0; 
  flowSensors_next->in     = 0;
  flowSensors_next->out    = 0; 

  //Enable ISRs
  attachInterrupt(digitalPinToInterrupt(FLOW_IN),  ISR_FlowSensors_in,  CHANGE); //Count both edges
  attachInterrupt(digitalPinToInterrupt(FLOW_OUT), ISR_FlowSensors_out, CHANGE); //Count both edges
}

//ISRs
//Flow meter inlet event
void ISR_FlowSensors_in() {
   flowSense_next->in++;
}

//Flow meter outlet event
void ISR_FlowSensors_out () {
    flowSensors_next->out++;
}

//Capture sensor data
inline void capture_FlowSensors() __attribute__((always_inline));
void capture_FlowSensors() {
  //Swap sensor data  
  flowSense_previous  = sensors_current;
  flowSense_current   = sensors_next;
  flowSense_next->in  = 0;
  flowSense_next->out = 0;
}

//Check if readings have changed
inline bool has_new_data_FlowSensors_in()  __attribute__((always_inline));
inline bool has_new_data_FlowSensors_out() __attribute__((always_inline));
bool has_new_data_FlowSensors_in() {
  return (flowSense_previous->in != flowSense_current->in);
}
bool has_new_data_FlowSensors_out() {
  return (flowSense_previous->out != flowSense_current->out);
}

//Get current flow rate in l/min
inline float get_flowrate_FlowSensors_in()  __attribute__((always_inline));
inline float new_flowrate_FlowSensors_out() __attribute__((always_inline));
float has_new_data_FlowSensors_in() {
  return flowSense_current->in / (FLOW_CNT_TO_FLOWRATE);
}
float has_new_data_FlowSensors_out() {
  return flowSense_current->out / (FLOW_CNT_TO_FLOWRATE);
}



