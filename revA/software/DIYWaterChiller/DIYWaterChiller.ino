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
//#    This project makes use of the NopSCADlib library                         #
//#    (see https://github.com/nophead/NopSCADlib).                             #
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

// Common definitions
#define VERSION_STR "DIYWaterChiller FW00.00"

//Pump driver (TimerOne) definitions

//Periodical interript (TimerTwo) definitions




//Code running every 1s
//inline void execute_every_1s() __attribute__((always_inline));
void periodic_isr ()
{
  //Swap sensor data  
  flowSense_previous  = sensors_current;
  flowSense_current   = sensors_next;
  flowSense_next->in  = 0;
  flowSense_next->out = 0;
  start_cycle         = true;
}

//Flow meter inlet event
void flow_in_isr()
{
   flowSense_next->in++;
}

//Flow meter inlet event
void flow_out_isr ()
{
    flowSensors_next->out++;
}





//Setup
void setup() {
  //Basic setup of all components
  setup_Safety();
  setup_Pumps();
  setup_Display();
  setup_FlowSensors();
  setup_DS18B20s();
  setup_Keys();
  setup_Serial();
  setup_EEPROM();
  setup_Control();
 
  //Detect temperature sensors
  detect_DS18B20s();
)


  //Initialize variables
  sensors_next     = &sensors_mem[0]; //upcoming status
  sensors_current  = &sensors_mem[1]; //Current status
  sensors_previous = &sensors_mem[2]; //Previous status
  sensors_next->in_flow  = 0;
  sensors_next->out_flow = 0;

  actuators_current  = actuators_mem[0]; //Current status
  actuators_previous = actuators_mem[1]; //Previous status

  //Setup SCI
  Serial.begin(9600);
  Serial.println(VERSION_STR); 
 
  //Setup TFT display
  tft.begin();
  draw_background();
 
  //Setup Thermometers





  //Serial.print("Devices: ");
  //Serial.println(ds.getNumberOfDevices());
  //Serial.println();

  //Setup TFT display
  tft.begin();
  draw_background();
  //tft.fillScreen(ILI9341_BLUE);  
  // tft.setTextSize(1);
  // tft.setCursor(0, 0);
  // tft.setTextColor(ILI9341_WHITE);
  // tft.println(VERSION_STR);

  //  //Setup flow meters
  // pinMode(FLOW_IN, INPUT_PULLUP);  
  // pinMode(FLOW_OUT, INPUT_PULLUP);
  // // attachInterrupt(digitalPinToInterrupt(FLOW_IN), flow_in_isr, CHANGE);
  // // attachInterrupt(digitalPinToInterrupt(FLOW_OUT), flow_out_isr, CHANGE);
  // flow_in_cnt   =  0;
  // flow_out_cnt  =  0start_cycle ;
  // flow_in_freq  =  0; 
  // flow_out_freq =  0;
  // flow_in_disp  = -1;
  // flow_out_disp = -1;
  // tft.setCursor(0, 10);
  // tft.println("IN [Hz]:");
  // tft.setCursor(0, 30);
  // tft.println("OUT [Hz]:");

 
}

//Loop
void loop() {
   //execute once after each periodic ISR
   if (start_cycle) {
      start_cycle = false;

      //Read temperatures
      



   }
}
