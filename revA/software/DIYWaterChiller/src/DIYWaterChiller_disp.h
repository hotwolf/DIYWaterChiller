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

//Includes
#include <Arduino.h>
#include "DIYWaterChiller_flow.h"
#include "DIYWaterChiller_pump.h"

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
//#define COL_PUMP        COL_FROM_RGB(0x3B3366)
#define COL_PUMP        COL_PIPE
#define COL_LASERBASE1  COL_FROM_RGB(0x3C3D41)
#define COL_LASERBASE2  COL_FROM_RGB(0x85858F)
#define COL_LASERTOP1   COL_FROM_RGB(0x327DD0)
#define COL_LASERTOP2   COL_FROM_RGB(0x93B9EC)
#define COL_DARKTEXT    COL_FROM_RGB(0x231E3C)
#define COL_LIGHTTEXT   COL_FROM_RGB(0xFCFCF7)
#define COL_REDTEXT     COL_FROM_RGB(0xDF4040)
#define COL_GREENTEXT   COL_FROM_RGB(0x7FBF40)
#define COL_COLDTEXT    COL_FROM_RGB(0x0F2E2C)
#define COL_WARMTEXT    COL_FROM_RGB(0x2E1A0F)

//Libraries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

//IO setup
void disp_ioSetup();

//Display setup
void disp_setup(); 

//Clear screen
inline void disp_clear() __attribute__((always_inline));
//void disp_clear();

//Draw screen background
inline void disp_drawBackground() __attribute__((always_inline));

//Draw data
void disp_drawData(bool update);

//Draw inlet flow rate
inline void disp_drawInFlow(bool update) __attribute__((always_inline));
    
//Draw outlet flow rate
inline void disp_drawOutFlow(bool update) __attribute__((always_inline));
  
//Draw cold tank temperature
inline void disp_drawColdTemp(bool update) __attribute__((always_inline));
    
//Draw warm tank temperature
inline void disp_drawWarmTemp(bool update) __attribute__((always_inline));

//Draw inlet temperature
inline void disp_drawInTemp(bool update) __attribute__((always_inline));
    
//Draw outlet temperature
inline void disp_drawOutTemp(bool update) __attribute__((always_inline));

//Draw laser heat dissapation
inline void disp_drawHeat(bool update) __attribute__((always_inline));

//Draw cold water pump power
inline void disp_drawColdPump(bool update) __attribute__((always_inline));
  
//Draw warm water pump power
inline void disp_drawWarmPump(bool update) __attribute__((always_inline));

//Draw floating point number
void disp_drawFloat(int16_t x, int16_t y, float num, uint16_t textCol, uint16_t bgCol, uint8_t sizeX, uint8_t sizeY);

//Draw L/min unit
void disp_drawLpm(int16_t x, uint16_t textCol);

//Draw Celsius unit
void disp_drawDegC(int16_t x, int16_t y, uint16_t textCol, uint16_t bgCol);

//Draw Watts unit
inline void disp_drawWatt() __attribute__((always_inline));
  
//Draw % unit
void disp_drawPercent(int16_t x, uint16_t textCol);

//Mark temperature sensor
void disp_markTemp(uint8_t index, bool ok);

//Show disconnect message
void disp_disconMsg();

//Show connect message
void disp_conMsg();

//Show connect message
void disp_conMsg();

//Clear message
void disp_clrMsg();

#endif
