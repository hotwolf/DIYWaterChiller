//###############################################################################
//# DIYWaterChiller - Vitamins - Water Blocks                                   #
//###############################################################################
//#    Copyright 2020 Dirk Heisswolf                                            #
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
//#   Water block configurations                                                #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  7, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
//                  dimensions    connector offsets
//                   X   Y   Z    X  Z      X  Z
WB40x40 = ["40x40", 40, 40, 12.5, 6, 6.25, 34, 6.25];
WB40x80 = ["40x80", 40, 80, 12.5, 6, 6.25, 34, 6.25];

water_blocks = [WB40x40, WB40x80];

use <water_block.scad>
