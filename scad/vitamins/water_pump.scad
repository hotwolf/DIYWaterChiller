//###############################################################################
//# DIYWaterChiller - Vitamins - Water Pump                                     #
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
//#   Model of a water pump                                                     #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  7, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
  
//! Model of a water pump wirh tank
include <NopSCADlib/utils/core/core.scad>

//Water pump vitamin
module water_pump() { //! Draw a water pump
    vitamin(str("water_pump(): Water pump"));

    //Mounting rail
    module mounting_rail() {
        railPoints = [[ 0,  1,    0],  //0
                      [ 0, -1,    0],  //1
                      [ 0, -1.35, 2],  //2
                      [ 0,  1.35, 2],  //3
                      [30,  0.75, 0],  //4
                      [30, -0.75, 0],  //5
                      [30, -1.1,  2],  //6
                      [30,  1.1,  2]]; //7
                
        railFaces  = [[0,1,2,3],  //-X
                      [5,4,7,6],  // X
                      [1,5,6,2],  //-Y
                      [0,3,7,4],  // Y
                      [1,0,4,5],  //-Z
                      [3,2,6,7]]; // Z
         
        hull() {
            polyhedron(railPoints, railFaces);              
            translate([29,-0.75,0]) cube([4,1.5,2]);
        }
    }

    //Mounting rails
    module mounting_rails(z=0) {
        
        translate([-19,-6.5,z]) mounting_rail();
        translate([-19,6.5,z])  mounting_rail();
    }

    //Mounting plate
    module mounting_plate() {
        
        module screw_slot(pos=[0,0,0],rot=0) {
            translate(pos) rotate(rot) {                
                translate([2.5,0,-1]) cylinder(4,d=5);
                translate([7.5,0,1])  cube([10,5,4],center=true);
            }
        }
               
        difference() {
            hull() {
                translate([20,20,0])   cylinder(2,d=10);
                translate([20,-20,0])  cylinder(2,d=10);
                translate([-20,20,0])  cylinder(2,d=10);
                translate([-20,-20,0]) cylinder(2,d=10);
            }
            union() {
                screw_slot([19,16,0],0);
                screw_slot([19,-16,0],0);
                
                screw_slot([10.5,19,0],90);
                screw_slot([-10.5,19,0],90);
                          
                screw_slot([-19,16,0],180);
                screw_slot([-19,-16,0],180);

                screw_slot([10.5,-19,0],270);
                screw_slot([-10.5,-19,0],270);
            }       
        }
        
        mounting_rails(2);       
    }
    color("gray") mounting_plate();

    //Pump body
    module pump_body() { 
        translate([-21.2,0,24.6]) rotate([0,90,0]) cylinder(52.6,d=42);
        translate([-19,3,2]) cube([40,7,5]);
        translate([-19,-10,2]) cube([40,7,5]);
        
        translate([31.4,0,24.6]) rotate([0,90,0]) cylinder(8.6,d=30.2);
        translate([40,0,24.6]) rotate([0,90,0]) cylinder(16.4,d=20.4);
        
        translate([31.4,9.6,24.6]) rotate([0,0,0]) cylinder(28,d=11);
        translate([31.4,9.6,52.6]) rotate([0,0,0]) cylinder(4,d1=11,d2=20.4);
        translate([31.4,9.6,56.6]) rotate([0,0,0]) cylinder(10.4,d=20.4);
        
        
    }
    color("gray") pump_body();

    //Connector
    module connector() {
        union() {
            translate([0,0,-14]) cylinder(14,d=27,$fn=6);       
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
    color("silver") translate([58.4,0,24.6]) rotate([0,90,0]) connector();
    color("silver") translate([31.4,9.6,70]) rotate([0,0,0]) connector();
} 
    
if($preview) {
    
    //Water pump
    water_pump();   
}
 
    