//###############################################################################
//# DIYWaterChiller - Firmware - Sound                                          #
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
//#   Firmware for the DIYWaterChiller (sound functions)                        #
//#                                                                             #
//#   !!! Set the Sketchbook location to               !!!                      #
//#   !!!  <DIYWaterChiller repository>/revA/software/ !!!                      #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   May 17, 2023                                                              #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
 
#ifndef DIYWATERCHILLER_SOUND_H_INCLUDED
#define DIYWATERCHILLER_SOUND_H_INCLUDED

//IO definitions
#define SOUND_OUT_A  18 //A4
#define SOUND_OUT_B  17 //A3

//Tone definitions
#define TONE_H6  1976
#define TONE_A6  1760
#define TONE_G6  1568
#define TONE_F6  1397
#define TONE_E6  1319
#define TONE_D6  1175
#define TONE_C6  1047
#define TONE_H5   988
#define TONE_A5   880
#define TONE_G5   784
#define TONE_F5   698
#define TONE_E5   659
#define TONE_D5   587
#define TONE_C5   523
#define TONE_H4   494
#define TONE_A4   440
#define TONE_G4   392
#define TONE_F4   349
#define TONE_E4   330
#define TONE_D4   294
#define TONE_C4   262

//Libraries
#include <Arduino.h>
#include <toneAC2.h>

//IO setup
void sound_ioSetup();

//Request input
void sound_playReqForInput();

#endif
