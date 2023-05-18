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

//Color definitions
#define COL_FROM_RGB(r,g,b) (((r&0xF8)<<8)|((g&0xFC)<<3)|((0xD2&0xF8)>>3))
#define COL_FROM_RGB(rgb)   (((rgb&0xF80000)>>8)|((rgb&0x00FC00)>>5)|((rgb&0x0000F8)>>3))
#define COL_BACKGROUND COL_FROM_RGB(0xF0F0D2)

//Libraries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

Adafruit_ILI9341 disp = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);

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
const uint16_t col_darkText   = col_waterTank;
const uint16_t col_lightText  = col_background;
const uint16_t col_redText    = (0xFF&0xF8)<<8  | //red
                                (0x00&0xFC)<<3  | //green
                                (0x00&0xF8)>>3;   //blue
const uint16_t col_greenText  = (0x00&0xF8)<<8  | //red
                                (0xFF&0xFC)<<3  | //green
                                (0x00&0xF8)>>3;   //blue

//IO setup
void disp_IoSetup() {
  //Setup TFT display
  disp.begin();
}

//Clear screen
//inline void disp_clear() __attribute__((always_inline));
void disp_clear() {
   disp.fillScreen(col_background); 
}

//Screens for temp sensor detection
//Step 1: Unplug all temperature sensors
inline void disp_drawTempDetection1() __attribute__((always_inline));
void disp_drawTempDetection1() {
  disp_clear();
  disp.setTextColor(col_darkText, col_background);
  disp.setTextSize(2);
  disp.setTextWrap(true);
  disp.setCursor(2,140);
  disp.println(F("Unplug all temperature sensors!"));
}
//Step 2: Plug in ininlet sensors
inline void disp_drawTempDetection2() __attribute__((always_inline));
void disp_drawTempDetection2() {
  disp_clear();
  disp.setCursor(2,140);
  disp.println(F("Plug in:"));
  disp.setCursor(20,120);
  disp.println(F("\0x1A  The inlet temperature sensor"));
}
//Step 3: Plug in outlet sensors
inline void disp_drawTempDetection3() __attribute__((always_inline));
void disp_drawTempDetection3() {
  disp.setCursor(20,140);
  disp.println(F("\0x1A  The outlet temperature sensor"));
}
//Step 4: Plug in cold water sensors
inline void disp_drawTempDetection4() __attribute__((always_inline));
void disp_drawTempDetection4() {
  disp.setCursor(20,160);
  disp.println(F("\0x1A  The cold water tank temperature sensor"));
}
//Step 5: Plug in warm water sensors
inline void disp_drawTempDetection5() __attribute__((always_inline));
void disp_drawTempDetection5() {
  disp.setCursor(20,160);
  disp.println(F("\0x1A  The warm water tank temperature sensor"));
}

//Screen background
inline void disp_drawBackground() __attribute__((always_inline));
void disp_drawBackground() {
  disp.fillScreen(col_background); 

  //Laser cutter
  disp.fillRect(20,14,  200, 60, col_laserBase1);
  disp.fillRect(26,14,  140, 10, col_laserTop1);
  disp.fillRect(172,14,  42, 10, col_laserTop1);

  disp.fillTriangle(20,13, 22,8, 22,13,    col_laserBase2);
  disp.fillTriangle(217,8, 217,13, 219,13, col_laserBase2);
  disp.fillRect(23,8, 194, 6,              col_laserBase2);

  disp.fillTriangle(26,13,   28,8,  28,13, col_laserTop2);
  disp.fillTriangle(163,13, 163,8, 165,13, col_laserTop2);
  disp.fillRect(29,8, 134, 6,              col_laserTop2);

  disp.fillTriangle(170,8, 172,8,  172,13, col_laserTop2);
  disp.fillTriangle(211,8, 213,13, 211,13, col_laserTop2);
  disp.fillRect(173,8,  38, 6,             col_laserTop2);

  //Cold water tank
  disp.fillRect(10,250, 100, 60,  col_coldWater);
  disp.drawFastHLine(10,310, 100, col_waterTank);
  disp.drawFastVLine(9,240,   71, col_waterTank);
  disp.drawFastVLine(110,240, 71, col_waterTank);

  //Warm water tank
  disp.fillRect(130,250, 100, 60,  col_warmWater);
  disp.drawFastHLine(130,310, 100, col_waterTank);
  disp.drawFastVLine(129,240,  71, col_waterTank);
  disp.drawFastVLine(230,240,  71, col_waterTank);

  //Pipes
  disp.fillTriangle(40,76, 34,90, 46,90,       col_pipe);
  disp.fillRect(38,91,     5, 159,             col_pipe);
  disp.fillRect(158,185,   5,  65,             col_pipe);
  disp.fillRect(43,185,  115,   5,             col_pipe);
  disp.fillTriangle(200,249, 194,235, 206,235, col_pipe);
  disp.fillRect(198,76,    5, 159,             col_pipe);

  //Pumps
  disp.fillRoundRect( 10,210, 60, 20, 10, col_pump);
  disp.fillRoundRect(130,210, 60, 20, 10, col_pump);
}

