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

module chiller() {
    //Body
    difference() {
        color("Green") union() {
            //Shell 
            translate([0,0,16])   cube([94,60,32],true);
            //Mounting screws
            translate([53,0,0])  cylinder(5,d=12);
            translate([-53,0,0]) cylinder(5,d=12);
            translate([0,0,2.5]) cube([106,12,5],true);
          
         }
        color("Red") union() {
          //Cooling blocks  
          translate([0,0,5]) { 
            translate([0,0,15])                         cube([81,41,30],true);

            translate([40,15.5,5])  rotate([0,90,0]) cylinder(20,d=10);
            translate([40,11.5,5])  rotate([0,90,0]) cylinder(20,d=10);
            translate([40,11.5,0])                      cube([20,4,10]);
            translate([40,6.6,5])                       cube([20,14,25]);
   
            translate([40,-15.5,5])  rotate([0,90,0]) cylinder(20,d=10);
            translate([40,-11.5,5])  rotate([0,90,0]) cylinder(20,d=10);
            translate([40,-15.5,0])                      cube([20,4,10]);
            translate([40,-20.5,5])                       cube([20,14,25]);

            translate([36,20,12])                       cube([24,20,18]);
            translate([-4,20,12])                       cube([8,20,18]);
            translate([-40.5,20,12])                    cube([4,20,18]);              
          }
          //Cooler screws
          translate ([20,25,-1])                        cylinder(34,d=4,$fn=8);
          translate ([20,25,-1])                        cylinder(28,d=7,$fn=6);
         
          translate ([-20,25,-1])                       cylinder(34,d=4,$fn=8);
          translate ([-20,25,-1])                       cylinder(28,d=7,$fn=6);
         
          translate ([20,-25,-1])                       cylinder(34,d=4,$fn=8);
          translate ([20,-25,-1])                       cylinder(28,d=7,$fn=6);
         
          translate ([-20,-25,-1])                      cylinder(34,d=4,$fn=8);
          translate ([-20,-25,-1])                      cylinder(28,d=7,$fn=6);
          //Mounting screws
          translate([53,0,-1])                          cylinder(7,d=5);
          translate([-53,0,-1])                         cylinder(7,d=5);
         
          
        }
    }
}

//if ($preview) {

   chiller();
//}