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

//Display definitions
#define TFT_DC   9
#define TFT_CS  -1
#define TFT_RST 8
#define TFT_SDI 11
#define TFT_SCK 13
#define TFT_LED  7

//Timer interrupt definitions
#define USE_TIMER_1           false
#define USE_TIMER_2           true
#define TIMER_INTERVAL_100MS  100L
#define TIMER_INTERVAL_1S     1000L

//Flow meter definitions
#define FLOW_IN   2
#define FLOW_OUT  3

//Libraries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <TimerInterrupt.h>
#include <ISR_Timer.h>

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);
ISR_Timer ISR_timer;

int flow_in_cnt, flow_out_cnt;   //Flow meter counters
int flow_in_freq, flow_out_freq; //Flow meter frequency
int flow_in_disp, flow_out_disp; //Flow meter display value

//Code running every 100ms
//inline void execute_every_100ms() __attribute__((always_inline));
void execute_every_100ms ()
{

}

//Code running every 1s
//inline void execute_every_1s() __attribute__((always_inline));
void execute_every_1s ()
{
  flow_in_freq = flow_in_cnt;
  flow_in_cnt  = 0;
  flow_out_freq = flow_in_cnt;
  flow_out_cnt  = 0;

  Serial.println("execute_every_1s()"); 

}

//Flow meter inlet event
void flow_in_isr()
{
   flow_in_cnt++;
  Serial.println("flow_in_isr()"); 
}

//Flow meter inlet event
void flow_out_isr ()
{
    flow_out_cnt++;
   Serial.println("flow_out_isr()"); 
}

//Setup
void setup() {

  //Setup SCI
  Serial.begin(9600);
  Serial.println(VERSION_STR); 
  Serial.println("Set up dispay!"); 
 
  //Setup TFT display
  tft.begin();
  Serial.println("1!"); 
  tft.fillScreen(ILI9341_BLUE);  
  Serial.println("2!"); 
  tft.setTextSize(1);
  Serial.println("3!"); 
  tft.setCursor(0, 0);
  Serial.println("4!"); 
  tft.setTextColor(ILI9341_WHITE);
  Serial.println("5!"); 
  tft.println(VERSION_STR);
  Serial.println("Dispay set up!"); 

   //Setup flow meters
  pinMode(FLOW_IN, INPUT);  
  pinMode(FLOW_OUT, INPUT);
  attachInterrupt(digitalPinToInterrupt(FLOW_IN), flow_in_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(FLOW_OUT), flow_out_isr, CHANGE);
  flow_in_cnt   =  0;
  flow_out_cnt  =  0;
  flow_in_freq  =  0; 
  flow_out_freq =  0;
  flow_in_disp  = -1;
  flow_out_disp = -1;
  tft.setCursor(0, 10);
  tft.println("IN [Hz]:");
  tft.setCursor(0, 30);
  tft.println("OUT [Hz]:");

  //Setup timer
  ITimer2.init();
  // Interval in unsigned long millisecs
  ITimer2.attachInterruptInterval(TIMER_INTERVAL_100MS, TimerHandler);
  ISR_timer.setInterval(TIMER_INTERVAL_1S, execute_every_1s);


}

//Loop
void loop(void) {

  //Display IN flow
  if (flow_in_disp != flow_in_freq) {
    flow_in_disp = flow_in_freq;
      tft.setCursor(0, 20);
      tft.println(flow_in_disp);
  }

  //Display OUT flow
  if (flow_out_disp != flow_out_freq) {
    flow_out_disp = flow_out_freq;
      tft.setCursor(0, 40);
      tft.println(flow_in_disp);
  }
}


//Timer handler
void TimerHandler()
{
  execute_every_100ms ();

  ISR_timer.run();
}
