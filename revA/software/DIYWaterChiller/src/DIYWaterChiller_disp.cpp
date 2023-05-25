//###############################################################################
//# DIYWaterChiller - Firmware - Display                                         #
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
//#   Firmware for the DIYWaterChiller (display functions)                      #
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

#include "DIYWaterChiller_disp.h"

//Display object
Adafruit_ILI9341 disp = Adafruit_ILI9341(DISP_CS, DISP_DC, DISP_RST);

//IO setup
void disp_ioSetup() {
  //Setup TFT display
  disp.begin();
}

//IO setup
void disp_setup() {
  //Draw background
  Serial.println("disp_setup");
  //disp.fillRect(20,14,  200, 60, COL_REDTEXT);
  //disp_clear();
  disp_drawBackground(); 
}

//Clear screen
void disp_clear() {
  disp.fillScreen(COL_BACKGROUND);  
}

//Draw screen background
void disp_drawBackground() {
  disp.fillScreen(COL_BACKGROUND); 

  //Laser cutter
  disp.fillRect(20,14,  200, 60, COL_LASERBASE1);
  disp.fillRect(26,14,  140, 10, COL_LASERTOP1);
  disp.fillRect(172,14,  42, 10, COL_LASERTOP1);

  disp.fillTriangle(20,13, 22,8, 22,13,    COL_LASERBASE2);
  disp.fillTriangle(217,8, 217,13, 219,13, COL_LASERBASE2);
  disp.fillRect(23,8, 194, 6,              COL_LASERBASE2);

  disp.fillTriangle(26,13,   28,8,  28,13, COL_LASERTOP2);
  disp.fillTriangle(163,13, 163,8, 165,13, COL_LASERTOP2);
  disp.fillRect(29,8, 134, 6,              COL_LASERTOP2);

  disp.fillTriangle(170,8, 172,8,  172,13, COL_LASERTOP2);
  disp.fillTriangle(211,8, 213,13, 211,13, COL_LASERTOP2);
  disp.fillRect(173,8,  38, 6,             COL_LASERTOP2);

  //Cold water tank
  disp.fillRect(10,250, 100, 60,  COL_COLDWATER);
  disp.drawFastHLine(10,310, 100, COL_WATERTANK);
  disp.drawFastVLine(9,240,   71, COL_WATERTANK);
  disp.drawFastVLine(110,240, 71, COL_WATERTANK);

  //Warm water tank
  disp.fillRect(130,250, 100, 60,  COL_WARMWATER);
  disp.drawFastHLine(130,310, 100, COL_WATERTANK);
  disp.drawFastVLine(129,240,  71, COL_WATERTANK);
  disp.drawFastVLine(230,240,  71, COL_WATERTANK);

  //Pipes
  disp.fillTriangle(40,76, 34,90, 46,90,       COL_PIPE);
  disp.fillRect(38,91,     5,   6,             COL_PIPE);
  disp.fillRect(38,137,    5, 113,             COL_PIPE);
  disp.fillRect(158,185,   5,  65,             COL_PIPE);
  disp.fillRect(43,185,  115,   5,             COL_PIPE);
  disp.fillTriangle(200,249, 194,235, 206,235, COL_PIPE);
  disp.fillRect(198,76,     5, 21,             COL_PIPE);
  disp.fillRect(198,137,    5, 98,             COL_PIPE);

  //Metering points
  disp.drawRoundRect(  2,97, 87, 40, 4, COL_PIPE);
  disp.drawRoundRect(151,97, 87, 40, 4, COL_PIPE);
  
  //Pumps
  disp.fillRoundRect( 15,210, 50, 20, 10, COL_PUMP);
  disp.fillRoundRect(135,210, 50, 20, 10, COL_PUMP);
}

//Draw data
void disp_drawData(bool update) {

  //Inlet flow rate
  disp_drawInFlow(update);
    
  //Outlet flow rate
  disp_drawOutFlow(update);
  
  //Cold tank temperature
  disp_drawColdTemp(update);
    
  //Warm tank temperature
  disp_drawWarmTemp(update);

  //Inlet temperature
  disp_drawInTemp(update);
    
  //Outlet temperature
  disp_drawOutTemp(update);

  //Laser heat dissapation
  disp_drawHeat(update);

  //Cold water pump power
  disp_drawColdPump(update);
  
  //Warm Water pump power
  disp_drawWarmPump(update);
}

//Draw inlet flow rate
void disp_drawInFlow(bool update) {

   if (!update || flow_newInletData()) {
     disp_drawFloat(3,118,flow_getInletFlowRate(),COL_DARKTEXT,COL_BACKGROUND,2,2);
   }
   if (!update) {
     disp_drawLpm(64,COL_DARKTEXT);
   }
}
    
//Draw outlet flow rate
void disp_drawOutFlow(bool update) {

   if (!update || flow_newOutletData()) {
     disp_drawFloat(152,118,flow_getOutletFlowRate(),COL_DARKTEXT,COL_BACKGROUND,2,2);
   }//
   if (!update) {
    disp_drawLpm(213,COL_DARKTEXT);
  }  
}
  
//Draw cold tank temperature
void disp_drawColdTemp(bool update) {

  if (!update) {
    const float temp = 4.38;
    disp_drawFloat(18,274,temp,COL_COLDTEXT,COL_COLDWATER,2,2);
    disp_drawDegC(79,274,COL_COLDTEXT,COL_COLDWATER);
  }
}
    
//Draw warm tank temperature
void disp_drawWarmTemp(bool update) {

  if (!update) {
    const float temp = 24.78;
    disp_drawFloat(138,274,temp,COL_WARMTEXT,COL_WARMWATER,2,2);
    disp_drawDegC(199,274,COL_WARMTEXT,COL_WARMWATER);
  }
}

//Draw inlet temperature
void disp_drawInTemp(bool update) {

  if (!update) {
    const float temp = 24.27;
    disp_drawFloat(3,100,temp,COL_GREENTEXT,COL_BACKGROUND,2,2);
    disp_drawDegC(64,100,COL_GREENTEXT,COL_BACKGROUND);
  }
}
    
//Draw outlet temperature
void disp_drawOutTemp(bool update) {

  if (!update) {
    const float temp = 31.93;
    disp_drawFloat(152,100,temp,COL_GREENTEXT,COL_BACKGROUND,2,2);
    disp_drawDegC(213,100,COL_GREENTEXT,COL_BACKGROUND);
  }
}

//Draw laser heat dissapation
void disp_drawHeat(bool update) {

  if (!update) {
    const float temp = 123.45;
    disp_drawFloat(47,35,temp,COL_LIGHTTEXT,COL_LASERBASE1,4,4);
    disp_drawWatt();
  }
}

//Draw cold water pump power
void disp_drawColdPump(bool update) {

  if (!update || pump_newColdData()) {
    disp_drawFloat(20,213,pump_getColdPower(),COL_LIGHTTEXT,COL_PUMP,1,2);
  }
  if (!update) {
    disp_drawPercent(51,COL_LIGHTTEXT);
  }  
}
  
//Draw warm water pump power
void disp_drawWarmPump(bool update) {

   if (!update || pump_newColdData()) {
     disp_drawFloat(140,213,pump_getWarmPower(),COL_LIGHTTEXT,COL_PUMP,1,2);
   }
   if (!update) {
     disp_drawPercent(171,COL_LIGHTTEXT);
  }
}

//Draw floating point number
void disp_drawFloat(int16_t x, int16_t y, float num, uint16_t textCol, uint16_t bgCol, uint8_t sizeX, uint8_t sizeY) {
  char buf[6]; //String buffer
  dtostrf(num,5,1,buf);

  disp.setCursor(x,y);
  disp.setTextColor(textCol,bgCol);
  disp.setTextSize(sizeX,sizeY);
  disp.print(buf);
}

//Draw L/min unit
void disp_drawLpm(int16_t x, uint16_t textCol) {
  const int16_t y = 118;
  
  disp.setTextColor(textCol,COL_BACKGROUND);
  disp.setTextSize(1); 

  disp.setCursor(x+4,y-1);
  disp.print(F("L"));
  
  disp.setCursor(x+5,y+8);
  disp.print(F("min"));

  disp.drawLine(x,y+10,x+18,y+3,textCol);
}

//Draw Celsius unit
void disp_drawDegC(int16_t x, int16_t y, uint16_t textCol, uint16_t bgCol) {
  disp.setCursor(x,y);
  disp.setTextColor(textCol,bgCol);
  disp.setTextSize(2);
  disp.print(F("\xF7\C"));
}

//Draw Watts unit
void disp_drawWatt() {
  const int16_t x = 170;
  const int16_t y = 35;
  disp.setCursor(x,y);
  disp.setTextColor(COL_LIGHTTEXT,COL_LASERBASE1);
  disp.setTextSize(4);
  disp.print(F("W"));
  
}

//Draw % unit
void disp_drawPercent(int16_t x, uint16_t textCol) {
  const int16_t y = 213;
  disp.setCursor(x,y);
  disp.setTextColor(textCol,COL_PUMP);
  disp.setTextSize(1,2);
  disp.print(F("%"));
  

  
}
