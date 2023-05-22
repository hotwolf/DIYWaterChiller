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

#ifndef DIYWATERCHILLER_DISP_H_INCLUDED
#define DIYWATERCHILLER_DISP_H_INCLUDED

//IO definitions
#define DISP_DC   8
#define DISP_CS  -1
#define DISP_RST -1
#define DISP_SDI 11
#define DISP_SCK 13

//Color definitions
#define COL_FROM_RGB(r,g,b) (((r&0xF8)<<8)|((g&0xFC)<<3)|((0xD2&0xF8)>>3))
#define COL_FROM_RGB(rgb)   (((rgb&0xF80000)>>8)|((rgb&0x00FC00)>>5)|((rgb&0x0000F8)>>3))
#define COL_BACKGROUND  COL_FROM_RGB(0xF0F0D2)
#define COL_COLDWATER   COL_FROM_RGB(0xD2F0EE)
#define COL_WARMWATER   COL_FROM_RGB(0xF0DCD2)
#define COL_WATERTANK   COL_FROM_RGB(0x231E3C)
#define COL_PIPE        COL_FROM_RGB(0x231E3C)
#define COL_PUMP        COL_FROM_RGB(0x4E4488)
#define COL_LASERBASE1  COL_FROM_RGB(0x3C3D41)
#define COL_LASERBASE2  COL_FROM_RGB(0x85858F)
#define COL_LASERTOP1   COL_FROM_RGB(0x327DD0)
#define COL_LASERTOP2   COL_FROM_RGB(0x93B9EC)
#define COL_DARKTEXT    COL_FROM_RGB(0x231E3C)
#define COL_LIGHTTEXT   COL_FROM_RGB(0xF0F0D2)
#define COL_REDTEXT     COL_FROM_RGB(0xFF0000)
#define COL_GREENTEXT   COL_FROM_RGB(0x00FF00)

//Libraries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

//IO setup
//inline void disp_ioSetup() __attribute__((always_inline));
void disp_ioSetup();

//Display setup
//inline void disp_setup() __attribute__((always_inline)); 
void disp_setup(); 

//Clear screen
//inline void disp_clear() __attribute__((always_inline));
void disp_clear();

//Draw screen background
//inline void disp_drawBackground() __attribute__((always_inline));
void disp_drawBackground();
						
#endif
