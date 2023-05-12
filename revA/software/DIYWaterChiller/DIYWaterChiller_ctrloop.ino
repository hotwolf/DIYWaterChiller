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

//Control loop definitions
#define CONTROL_LOOP_PERIOD 

//Libraries
#include <TimerTwo.h>

const uint16_t Control_period = 1000;

//Minimal setup
inline void setup_Control() __attribute__((always_inline));
void setup_Control() {
}

/Start control loop
inline void start_Control() __attribute__((always_inline));
void start_Control() {
  //Initialize timer 2
  Timer2.init(, ISR_Control);
  //

…}

//ISRs
//Control loop cycle
void ISR_Control() {



   flowSense_next->in++;
}

























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

