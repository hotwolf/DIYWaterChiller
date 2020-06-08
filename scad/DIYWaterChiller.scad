//###############################################################################
//# DIYWaterChiller - Main Assembly                                             #
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
//#   Main assembly of the DIYWaterChiller                                      #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  7, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
  
//! Project description in Markdown format before the first include.
include <NopSCADlib/lib.scad>   // Includes all the vitamins and utilities in NopSCADlib but not the printed parts.
include <./vitamins/water_blocks.scad>
include <./vitamins/peltiers.scad>
include <./vitamins/heat_sinks.scad>
include <./vitamins/pump.scad>




//! Assembly instructions in Markdown format in front of each module that makes an assembly.
module main_assembly()
assembly("main") {
    
//        water_block(WB40x80, true);
//        peltier(TEC1_12706, true);
//        heat_sink(HS_WB40x40, true); 
         pump();    
}

if($preview)
    main_assembly();
