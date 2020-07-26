//###############################################################################
//# DIYWaterChiller - Vitamins - Coolant Pump                                   #
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
//#   Model of a coolant pump with tank                                         #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  7, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//#   July 25, 2020                                                             #
//#      - Changed module name                                                  #
//#                                                                             #
//###############################################################################
  
//! Model of a water pump wirh tank
include <NopSCADlib/utils/core/core.scad>

//Water pump vitamin
module coolant_pump() { //! Draw a coolant pump
    vitamin(str("coolant_pump(): Coolant pump"));

    //Tube shape
    module tube(h=10,id=58,od=60) {
        difference() {
            translate([0,0,0])  cylinder(h,d=od);
            translate([0,0,-1]) cylinder(h+2,d=id);
        }
    }
    
    //Connector
    module connector() {
        color("silver") union() {
            translate([0,0,0]) cylinder(3,d=17);
            translate([0,0,3]) cylinder(2,d=17,$fn=6);       
            translate([0,0,0]) rotate_extrude() 
            polygon( points=[[3.0, 0],
                             [3.0,23],
                             [4.0,23],
                             [4.7,18],
                             [4.5,18],
                             [4.5,15],
                             [4.0,15],
                             [4.5,13],
                             [4.0,13],
                             [4.5,11],
                             [4.0,11],
                             [4.5, 9],
                             [4.5, 0]]);
        }
    }

    //Pump
    color("black")     translate([0,0,0])     cylinder(36,d=45);
    color("black")     translate([0,0,36])    cylinder(16,d=48);
    color("black")     translate([0,0,52])    cylinder(8,d=40);
    color("black")     translate([0,0,60])    cylinder(13,d=18);
    color("silver")    translate([0,0,73])    cylinder(5,d=18);
    color("black")     translate([0,0,78])    cylinder(6,d=50);
    color("black")     translate([0,0,84])    tube(h=8,id=10,od=48);
    color("black")     translate([0,0,226])   cylinder(8,d=48);  
    color([1,1,1,0.5]) translate([0,10,186])  tube(h=40,id=8,od=10);
    color([0,0,1,0.5]) translate([0,0,92])    cylinder(100,d=48);
    color([1,1,1,0.5]) translate([0,0,84])    tube(h=150,id=48,od=50); 
    color("black")     translate([0,0,234])   cylinder(6,d=50); 
    color("silver")    translate([0,-10,240]) cylinder(4,d=18);  
                       translate([0,10,240])  connector();
    
    color("black")     translate([0,-15,55])  rotate([0,90,0]) cylinder(22,d=10);
    color("black")     translate([22,-15,55]) rotate([0,90,0]) cylinder(6,d1=10,d2=18);
    color("black")     translate([28,-15,55]) rotate([0,90,0]) cylinder(8,d=18);
                       translate([36,-15,55]) rotate([0,90,0]) connector();
} 
    
if($preview) {      
    coolant_pump();
    //connector();    
}
 
    