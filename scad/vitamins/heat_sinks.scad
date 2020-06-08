//###############################################################################
//# DIYWaterChiller - Vitamins - Heat Sinks                                     #
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
//#   Heat sink configurations                                                  #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  8, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
//                          base           fins               holes
//                        X   Y   Z   X   Y   Z   cnt   X  Y D   X  Y D
HS_WB40x40 = ["WB40x40", 58, 40,  4, 40, 40, 17.5, 9, [[4,20,4],[54,20,4]]];

heat_sinks = [HS_WB40x40];

use <heat_sink.scad>
