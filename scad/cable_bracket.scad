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
//#   A fitting to place a thermometer in water flow of a 6mm hose.             #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   February 27, 2020                                                         #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
//Parameters
$d_cable     =  6;                  //diameter of the cable
$fn          = 48;

module cable_bracket() {
    //Body
    difference() {
        union() {
            translate([($d_cable/2)+5,0,0])  cylinder($d_cable+2,d=10);
            translate([-($d_cable/2)-5,0,0]) cylinder($d_cable+2,d=10);
            translate([0,0,($d_cable/2)+1]) cube([$d_cable+10,10,$d_cable+2],true);            
        }
        union() {
            translate([($d_cable/2)+5,0,-1])  cylinder($d_cable+4,d=5);
            translate([-($d_cable/2)-5,0,-1]) cylinder($d_cable+4,d=5);
            translate([0,0,$d_cable+2]) cube([$d_cable,12,$d_cable],true);          
            translate([0,6,$d_cable-1]) rotate([90,0,0]) cylinder(12,d=$d_cable);
        }
    }
    //Grip
      translate([0,0,2+$d_cable/2]) rotate([0,0,0])    linear_extrude($d_cable/2) grip_profile();
      translate([0,0,2+$d_cable/2]) rotate([0,0,180])  linear_extrude($d_cable/2) grip_profile();
      translate([0,0,2+$d_cable/2]) rotate([90,180,0]) rotate_extrude(angle=180) grip_profile();

        

}

module grip_profile() {
    polygon([[$d_cable/2+1,-5],
             [$d_cable/2,-5],
             [-0.5+$d_cable/2,-4.5],
             [$d_cable/2,-4],
             [-0.5+$d_cable/2,-3.5],
             [$d_cable/2,-3],
             [-0.5+$d_cable/2,-2.5],
             [$d_cable/2,-2],
             [-0.5+$d_cable/2,-1.5],
             [$d_cable/2,-1],
             [-0.5+$d_cable/2,-0.5],
             [$d_cable/2,-0],
             [-0.5+$d_cable/2,0.5],
             [$d_cable/2,1],
             [-0.5+$d_cable/2,1.5],
             [$d_cable/2,2],
             [-0.5+$d_cable/2,2.5],
             [$d_cable/2,3],
             [-0.5+$d_cable/2,3.5],
             [$d_cable/2,4],
             [-0.5+$d_cable/2,4.5],
             [$d_cable/2,5],    
             [$d_cable/2+1,5],    
    ]);
    
    
}

//if ($preview) {

    cable_bracket();
//}