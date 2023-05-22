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
  disp.fillRect(38,91,     5, 159,             COL_PIPE);
  disp.fillRect(158,185,   5,  65,             COL_PIPE);
  disp.fillRect(43,185,  115,   5,             COL_PIPE);
  disp.fillTriangle(200,249, 194,235, 206,235, COL_PIPE);
  disp.fillRect(198,76,    5, 159,             COL_PIPE);

  //Pumps
  disp.fillRoundRect( 10,210, 60, 20, 10, COL_PUMP);
  disp.fillRoundRect(130,210, 60, 20, 10, COL_PUMP);
}

