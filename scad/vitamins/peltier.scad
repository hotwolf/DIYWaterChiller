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
//#   Generic model of a Peltier element                                        #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  8, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
  
//! Generic model of an aluminum water chiller block
include <NopSCADlib/utils/core/core.scad>

function pe_name(type)     = type[0]; //! Part code without shield type suffix
function pe_Xdim(type)     = type[1]; //! X dimensions
function pe_Ydim(type)     = type[2]; //! Y dimensions
function pe_Zdim(type)     = type[3]; //! Z dimensions

//Peltier element vitamin
module peltier(type, center=false) { //! Draw a Peltier element
    vitamin(str("peltier(", pe_name(type), "): Peltier Element Type:", pe_name(type)));
    //Local variables
    Xdim    = pe_Xdim(type);
    Ydim    = pe_Ydim(type);
    Zdim    = pe_Zdim(type);
    
    translate([(center) ? -Xdim/2 : 0,
               (center) ? -Ydim/2 : 0,
               (center) ? -Zdim/2 : 0]) {
                  
        color("white") cube([Xdim,Ydim,Zdim]);
        color("red")   translate([0,2,Zdim/2])      rotate([0,270,0,]) cylinder(2,d=1.8);          
        color("black") translate([0,Ydim-2,Zdim/2]) rotate([0,270,0,]) cylinder(2,d=1.8);                                      
    }
} 
    
if($preview) {      
         peltier(["TEC1_12706", 40, 40,  3.7], false);     
}
 
    