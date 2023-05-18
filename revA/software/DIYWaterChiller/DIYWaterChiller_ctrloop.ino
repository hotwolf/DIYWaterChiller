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

// //Libraries
// #include <TimerTwo.h>

// //Inlined functions
// inline void flow_capture() __attribute__((always_inline));



// bool           ctrloop_new_cycle;
// const uint16_t ctrloop_period = 1000; //1s

// //Minimal setup
// void ctrloop_setup() {
//   //Control loop not started 
//   ctrloop_new_cycle = false;
// }

// //Start control loop
// void ctrloop_start() {
//   //Initialize timer 2
//   Timer2.init(ctrloop_period, ISR_ctrloop);
//   //Start timer
//   Timer2.start();
// }

// //ISRs
// //Control loop cycle (executed once per second)
// void ISR_ctrloop() {
//    //Capture flow sensors immediately
//    flow_capture();
//    //Signal start of new control loop cycle
//    ctrloop_new_cycle = true;
// }

// //Check for new control loop cycle
// bool ctrloop_is_new_cycle() {
//   bool result = ctrloop_new_cycle;
//   ctrloop_new_cycle = false;
//   return result;
// }


// // //Actuator data
// // typedef struct
// // {
// //         uint16_t in_pump;       //Inlet pump strength [100%/1023]
// //         uint16_t out_pump;      //Ou sensors_next->in_flow = 0;tlet pump strength [100%/1023]
// //         bool     enable_laser;  //Relais control 
// // } actuators_t

// // actuators_t[3] actuator_mem ;
// // actuators_t   *actuators_next;     //upcoming status
// // actuators_t   *actuators_current;  //Current status
// // actuators_t   *actuators_previous; //Previous status

// //Control cycle
// bool start_cycle; //Start new iteration

