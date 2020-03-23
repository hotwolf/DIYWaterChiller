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
//#   A bracket to secure a square water flow ibdicator.                        #
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
          translate([0,0,3])      cube([45,45,6],true); 

          translate([0,-27,0])    cylinder(6,d=10);
          translate([0,-25,3])    cube([10,5,6],true); 
            
          translate([27,17.5,0])  cylinder(6,d=10); 
          translate([25,17.5,3])  cube([5,10,6],true); 

          translate([-27,17.5,0]) cylinder(6,d=10);             
          translate([-25,17.5,3]) cube([5,10,6],true); 
        }
        union() {
          translate([0,0,7])       cube([41,41,10],true); 
          translate([0,0,0])       cube([36,36,20],true); 

          translate([0,-27,-1])    cylinder(8,d=5);
          translate([0,-27,-1])    cylinder(3,d1=10,d2=4);

          translate([27,17.5,-1])  cylinder(8,d=5); 
          translate([27,17.5,-1])  cylinder(3,d1=10,d2=4);

          translate([-27,17.5,-1]) cylinder(8,d=5);             
          translate([-27,17.5,-1]) cylinder(3,d1=10,d2=4);
        }
    }
}

//if ($preview) {

   flowind_bracket();
//}