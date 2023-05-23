//###############################################################################
//# DIYWaterChiller - Firmware                                                  #
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
//#   Firmware for the DIYWaterChiller                                          #
//#                                                                             #
//#   !!! Set the Sketchbook location to               !!!                      #
//#   !!!  <DIYWaterChiller repository>/revA/software/ !!!                      #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   May 4, 2023                                                               #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################

#include "DIYWaterChiller_main.h"

//Global variables
uint16_t perint_cnt; //Periodic interrupt down counter

//Setup
void main_setup() {
  //Configure IOs
  //safety_ioSetup();
  //pump_ioSetup();
  //sound_ioSetup();
  disp_ioSetup();
  flow_ioSetup();
  //temp_ioSetup();
  //keys_ioSetup();
  serial_ioSetup();
 
  //Start functions
  Serial.println("Setup Display");
  //yield();
  //disp.fillTriangle(217,8, 217,13, 219,13, 0);

  disp_setup();
  //eeprom_setup();
  //temp_setup();
  flow_setup();


  Serial.println("Setup done");

  //Start Periodic interrupt
  //Use output compare register OCR0A to trigger one interrupt ert TCNT0 counter cycle
  //perint_cnt = PERINT_CYC_CNT; //Initialize cycle count
  //OCR0A      = 0xAF;           //Random point in the TCNTO counter cycle
  //TIMSK0    |= bit(OCIE0A);
}

//Loop
void main_loop() {
   Serial.println("Loop");
   Serial.print("Inlet: ");
   Serial.println(flow_getInletFlowRate());
   Serial.print("Outlet: ");
   Serial.println(flow_getOutletFlowRate());
   delay(1000);

   //execute once after each periodic ISR
  //  if (ctrloop_is_new_cycle()) {
     
      //Check for leakage

      //Read temperatures
      
      //Check inlet temperature

      //Calculate control loop cyccle

      //Drive pumps


      //Update display


  //  }
}

//Periodic Interrupt (Timer/Counter0 compare match A)
//This ISR is called every 1.024ms
ISR(TIMER0_COMPA_vect) 
{
  switch(perint_cnt--) {
    case 500:
      //Capture flow sensor data within ISR
      //Called every 1.000448s (1 7/15625 s)
      flow_capture();
    break;

    case 0:
      //Reset counter
       perint_cnt = PERINT_CYC_CNT; //Initialize cycle count
    break;
  }
}




