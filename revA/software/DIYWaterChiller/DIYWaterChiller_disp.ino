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
//#    This project makes use of the NopSCADlib library                         #
//#    (see https://github.com/nophead/NopSCADlib).                             #
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

//IO definitions
#define TFT_DC  12
#define TFT_CS  -1
#define TFT_RST -1
#define TFT_SDI 11
#define TFT_SCK 13

//Libraries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);

//Colors
const uint16_t col_background = (0xF0&0xF8)<<8  | //red
                                (0xF0&0xFC)<<3  | //green
                                (0xD2&0xF8)>>3;   //blue
const uint16_t col_coldWater  = (0xD2&0xF8)<<8  | //red
                                (0xF0&0xFC)<<3  | //green
                                (0xEE&0xF8)>>3;   //blue
const uint16_t col_warmWater  = (0xF0&0xF8)<<8  | //red
                                (0xDC&0xFC)<<3  | //green
                                (0xD2&0xF8)>>3;   //blue
const uint16_t col_waterTank  = (0x23&0xF8)<<8  | //red
                                (0x1E&0xFC)<<3  | //green
                                (0x3C&0xF8)>>3;   //blue
const uint16_t col_pipe       = col_waterTank;
const uint16_t col_pump       = (0x4E&0xF8)<<8  | //red
                                (0x44&0xFC)<<3  | //green
                                (0x88&0xF8)>>3;   //blue
const uint16_t col_laserBase1 = (0x3C&0xF8)<<8  | //red
                                (0x3D&0xFC)<<3  | //green
                                (0x41&0xF8)>>3;   //blue
const uint16_t col_laserBase2 = (0x85&0xF8)<<8  | //red
                                (0x85&0xFC)<<3  | //green
                                (0x8F&0xF8)>>3;   //blue
const uint16_t col_laserTop1  = (0x32&0xF8)<<8  | //red
                                (0x7D&0xFC)<<3  | //green
                                (0xD0&0xF8)>>3;   //blue
const uint16_t col_laserTop2  = (0x93&0xF8)<<8  | //red
                                (0xB9&0xFC)<<3  | //green
                                (0xEC&0xF8)>>3;   //blue


//Minimal setup
inline void setup_Display() __attribute__((always_inline));
void setup_Display() {
  //Setup TFT display
  tft.begin();
}

//Clear screen
inline void clear_screen() __attribute__((always_inline));
void clear_screen() {
   tft.fillScreen(col_background); 
}



//Screen background
inline void draw_background() __attribute__((always_inline));
void draw_background() {
  tft.fillScreen(col_background); 

  //Laser cutter
  tft.fillRect(20,14,  200, 60, col_laserBase1);
  tft.fillRect(26,14,  140, 10, col_laserTop1);
  tft.fillRect(172,14,  42, 10, col_laserTop1);

  tft.fillTriangle(20,13, 22,8, 22,13,    col_laserBase2);
  tft.fillTriangle(217,8, 217,13, 219,13, col_laserBase2);
  tft.fillRect(23,8, 194, 6,              col_laserBase2);

  tft.fillTriangle(26,13,   28,8,  28,13, col_laserTop2);
  tft.fillTriangle(163,13, 163,8, 165,13, col_laserTop2);
  tft.fillRect(29,8, 134, 6,              col_laserTop2);

  tft.fillTriangle(170,8, 172,8,  172,13, col_laserTop2);
  tft.fillTriangle(211,8, 213,13, 211,13, col_laserTop2);
  tft.fillRect(173,8,  38, 6,             col_laserTop2);

  //Cold water tank
  tft.fillRect(10,250, 100, 60,  col_coldWater);
  tft.drawFastHLine(10,310, 100, col_waterTank);
  tft.drawFastVLine(9,240,   71, col_waterTank);
  tft.drawFastVLine(110,240, 71, col_waterTank);

  //Warm water tank
  tft.fillRect(130,250, 100, 60,  col_warmWater);
  tft.drawFastHLine(130,310, 100, col_waterTank);
  tft.drawFastVLine(129,240,  71, col_waterTank);
  tft.drawFastVLine(230,240,  71, col_waterTank);

  //Pipes
  tft.fillTriangle(40,76, 34,90, 46,90,       col_pipe);
  tft.fillRect(38,91,     5, 159,             col_pipe);
  tft.fillRect(158,185,   5,  65,             col_pipe);
  tft.fillRect(43,185,  115,   5,             col_pipe);
  tft.fillTriangle(200,249, 194,235, 206,235, col_pipe);
  tft.fillRect(198,76,    5, 159,             col_pipe);

  //Pumps
  tft.fillRoundRect( 10,210, 60, 20, 10, col_pump);
  tft.fillRoundRect(130,210, 60, 20, 10, col_pump);
}

