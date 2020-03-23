//###############################################################################
//#                                                                             #
//###############################################################################
//#    Copyright 2020 Dirk Heisswolf                                            #
//#    This file is part of the DIY Laser Bed project.                          #
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
//#   This is a cover to block the UV light at the openings of the tub.         #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   February 27, 2020                                                         #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
//Parameters
$d_hole      = 18.4;                  //diameter 
$d_cable     =  9;                  //diameter of the cable
$w_cable     = 18;                  //width of the cable slot
$fn          = 48;

module uv_cover() {
    //Body
    difference() {
        union() {
          translate([0,0,0])  cylinder(10,d=$d_hole); 
          translate([0,0,0])  cylinder(5,d=$d_hole+20); 
         }
        union() {
          translate([(($d_hole+$d_cable)/2)-$w_cable,0,-1])  cylinder(12,d=$d_cable); 
          translate([30+(($d_hole-$w_cable-$d_cable)/2),0,5])       cube([60,$d_cable,12],true); 
        }
    }
}

//if ($preview) {

   uv_cover();
//}