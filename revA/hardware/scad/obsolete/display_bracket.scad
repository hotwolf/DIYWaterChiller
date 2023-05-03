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
//#   A bracket to secure a temperature display.                                #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   February 27, 2020                                                         #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
//Parameters
$d_cable     =  8;                  //diameter of the cable
$fn          = 24;

module flowind_bracket() {
    //Body
    difference() {
        union() {
          translate([0,0,1.5])      cube([50,32,3],true); 
           
          translate([27,0,0])  cylinder(3,d=10); 
          translate([25,0,1.5])  cube([5,10,3],true); 

          translate([-27,0,0]) cylinder(3,d=10);             
          translate([-25,0,1.5]) cube([5,10,3],true); 
        }
        union() {
          translate([0,0,0])       cube([46,28,10],true); 

          translate([27,0,-1])  cylinder(8,d=5); 
 
          translate([-27,0,-1]) cylinder(8,d=5);             
        }
    }
}

//if ($preview) {

   flowind_bracket();
//}