//###############################################################################
//# DIYWaterChiller - Firmware - Pumps                                          #
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
//#   Firmware for the DIYWaterChiller (pump functions)                         #
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
#include "DIYWaterChiller_pump.h"

//Variables
pump_data_t  pump_data[2]  = {{0,0},{0,0}};
pump_data_t *pump_dataCur  = &pump_data[1];     //Current status
pump_data_t *pump_dataPrev = &pump_data[0];     //Previous status

//IO setup
void pump_ioSetup() {
  //Setup timer 1
  Timer1.initialize(40);  // 40 us = 25 kHz
  Timer1.pwm(PUMP_COLD, 0);
  Timer1.pwm(PUMP_WARM, 0);
}

//Set pump power
void pump_set(uint16_t cold, uint16_t warm) {
  //Set pump power
  Timer1.pwm(PUMP_COLD, cold);
  Timer1.pwm(PUMP_WARM, warm);

  //Record pump power
  pump_data_t *tmp = pump_dataPrev;
  tmp->cold = cold;
  tmp->warm = warm;
  pump_dataPrev = pump_dataCur;
  pump_dataCur  = tmp;
}

//Check if settings have changed
bool pump_newColdData() {
  return (pump_dataPrev->cold != pump_dataCur->cold);
}
bool pump_newWarmData() {
  return (pump_dataPrev->warm != pump_dataCur->warm);
}

//Get current pump power in %
float pump_getColdPower() {
  return (float)pump_dataCur->cold * (100/1023);
};
float pump_getWarmPower() {
  return (float)pump_dataCur->warm * (100/1023);
};
