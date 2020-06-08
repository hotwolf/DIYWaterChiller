//###############################################################################
//# DIYWaterChiller - Vitamins - Peltier Elements                               #
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
//#   Peltier element configurations                                            #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  8, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
//                          dimensions
//                           X   Y   Z
TEC1_12706 = ["TEC1_12706", 40, 40,  3.7];

peltiers = [TEC1_12706];

use <peltier.scad>
