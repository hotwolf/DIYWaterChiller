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
uint16_t pColdCnt = 0;
uint16_t pWarmCnt = 512;

//Setup
void main_setup() {
  //Configure IOs
  safety_ioSetup();
  pump_ioSetup();
  //sound_ioSetup();
  disp_ioSetup();
  flow_ioSetup();
  temp_ioSetup();
  //keys_ioSetup();
  serial_ioSetup();
 
  //Start functions
  disp_setup();
  eeprom_setup();
  temp_setup();
  flow_setup();
  disp_drawData(false);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.println("Setup done");

  //Start Periodic interrupt
  //Use output compare register OCR0A to trigger one interrupt ert TCNT0 counter cycle
  perint_cnt = PERINT_CYC_CNT; //Initialize cycle count
  OCR0A      = 0xAF;           //Random point in the TCNTO counter cycle
  TIMSK0    |= bit(OCIE0A);
}

//Loop
void main_loop() {
   //Serial.print("Inlet: ");
   //Serial.println(flow_getInletFlowRate(),DEC);
   //Serial.print("Outlet: ");
   //Serial.println(flow_getOutletFlowRate(),DEC);

   //execute once after each periodic ISR
  //  if (ctrloop_is_new_cycle()) {
     
      //Check for leakage

      //Read temperatures
      
  
      //Check inlet temperature

      //Calculate control loop cyccle

      //Drive pumps
      pump_set(pColdCnt,pWarmCnt);
      pColdCnt = (pColdCnt+10)%1024;
      pWarmCnt = (pWarmCnt+10)%1024;
      //Serial.print("Cold: ");
      //Serial.println(pump_getColdPower(),DEC);
      //Serial.print("Warm: ");
      //Serial.println(pump_getWarmPower(),DEC);


      //Update display
      disp_drawData(true);

   
      delay(1000);
  //  }
}

//Reset
void(* resetFunc) (void) = 0; //Reset function at address 0

//Periodic Interrupt (Timer/Counter0 compare match A)
//This ISR is called every 1.024ms
ISR(TIMER0_COMPA_vect) 
{
  //digitalWrite(5, 1);
  //digitalWrite(5, 0);
  
  switch(perint_cnt--) {
    case 500:
      //Capture flow sensor data within ISR
      //Called every 1.000448s (1 7/15625 s)
      flow_capture();

      digitalWrite(6, 1);
      digitalWrite(6, 0);

      
    break;

    case 0:
      //Reset counter
       perint_cnt = PERINT_CYC_CNT; //Initialize cycle count
    break;
  }
}




