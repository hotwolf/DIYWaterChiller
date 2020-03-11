//###############################################################################
//#                                                #
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
$l_sensor    = 50;                  //length of the temperature sensor
$d_sensor    =  6;                  //diameter of the temperature sensor
$d_channel   = 10;                  //diameter of inner channel
$l_insert    =  4;                  //Length of the sensor insert
$t_wall      =  2;                  //thickness of the channel walls
$d_primary   =  7;                //inner hose diameter of the primary water circulation
$d_secondary =  9;                //inner hose diameter of the secondary water circulation
$d_chiller   =  9;                //inner hose diameter of the chiller connection
$fn          = 18;

//Water channel
module channel() {
        
    //Water flow
    color("Aqua") union() {
        //Straight tube
        l_tube = $l_sensor-$d_channel-(2*$t_wall)-$l_insert;  //length of the tube
        x_tube = l_tube/2;                                    //X-offset
        z_tube = ($d_channel/2)+$t_wall;                      //Z-offset
        translate([x_tube,0,z_tube]) rotate([0,270,0]) cylinder(l_tube,d=$d_channel);
        //Curves  
        r_curve = ($d_channel/2)+$t_wall;                     //curve radius
        x_curve = l_tube/2;                                   //X-offset
        z_curve = $d_channel+2*$t_wall;                       //Z-offset
        translate([x_curve,0,z_curve]) rotate([270,0,0]) 
        rotate_extrude(angle=90) translate([r_curve,0,0]) circle(d=$d_channel);
        translate([-x_curve,0,z_curve]) rotate([270,0,180]) 
        rotate_extrude(angle=90) translate([r_curve,0,0]) circle(d=$d_channel);
    }
}

//Sensor
module sensor() {
    color("Silver") union() {
        x_sensor = -($l_sensor+$d_channel+$l_insert)/2;    //X-offset
        z_sensor = ($d_channel/2)+$t_wall;                 //Z-offset
        translate([x_sensor,0,z_sensor]) rotate([0,90,0]) {
            cylinder($l_sensor,d=$d_sensor);
            translate([0,0,-2])  cylinder(3,d1=$d_sensor+3,d2=$d_sensor);
        }
    }
}

//Hose connector
module connector(d_inner=$d_chiller,side=1) {
    x_channel = (1-2*side)*($l_sensor-$l_insert)/2; //X-offset
    z_channel = $d_channel+2*$t_wall;                       //Z-offset;   
    //Cone
    translate([x_channel,0,z_channel]) {
        difference() {
            color("Green") cylinder(5,d1=$d_channel+2*$t_wall,d2=d_inner+2*$t_wall);
            color("AQUA")  cylinder(5,d1=$d_channel,d2=d_inner);
        }       
    }
    //cylinder
    translate([x_channel,0,0]) {
        color("Green") cylinder(z_channel,d=$d_channel+2*$t_wall);    
    }
    //Connector  
    translate([x_channel,0,5+z_channel]) color("Green") rotate_extrude()
        polygon([[(d_inner/2)+$t_wall,0],[(d_inner/2),0],[(d_inner/2)-1,20],[(d_inner/2),20],
                 [(d_inner/2)+0.05,19],[(d_inner/2)+1,18],  [(d_inner/2)+0.15,17],
                 [(d_inner/2)+0.25,15],[(d_inner/2)+1.1,14],[(d_inner/2)+0.35,13],
                 [(d_inner/2)+0.35,11],[(d_inner/2)+1.2,10],[(d_inner/2)+0.45,9],
                 [(d_inner/2)+0.45,7], [(d_inner/2)+1.3,6], [(d_inner/2)+0.55,5],
               [(d_inner/2)+0.55,3], //[(d_inner/2)+1.4,2], [(d_inner)/2+0.6,1]
                ]);
}

//Pair of connectors
module connector_pair(d0=$d_primary,d1=$d_chiller) {
   connector(d_inner=d0,side=0); 
   connector(d_inner=d1,side=1); 
}

//Mounting hole
module mounting_hole() {
    translate([0,0,-2]) cylinder(18,d=4.5);
    translate([0,0,6]) cylinder(10,d=10);
}

//Full quad-sensor adapter
module quad_sensor() {
    y_block1 = 5+$t_wall+($d_channel/2);         //Y-offset
    y_block0 = y_block1+10+$d_channel+2*$t_wall; //Y-offset
    y_block2 = -y_block1;                        //Y-offset
    y_block3 = -y_block0;                        //Y-offset
    h_block  = $d_channel+2*$t_wall;             //height of a block
    w_block  = h_block;                          //width of a block
    l_block  = $l_sensor;
    
    difference() {
        //Positive
        color("Green") union() {
           //Block 0
           translate([0,y_block0,0]) {
                connector_pair(d0=$d_secondary);
                translate([-$l_insert/2,0,h_block/2])   cube([l_block,w_block,h_block],true);
                translate([-(l_block+$l_insert)/2,0,0]) cylinder(h_block,d=w_block);
                translate([0,0,h_block]) {
                   rotate([0,0,90]) linear_extrude(2) 
                    text("S",12,valign="center", halign="center");
                    linear_extrude(2) polygon([[14,0],[10,4],[10,-4]]);
                }
           }
           //Block 1
           translate([0,y_block1,0]) {
                connector_pair();
                translate([-$l_insert/2,0,h_block/2])   cube([l_block,w_block,h_block],true);
                translate([-(l_block+$l_insert)/2,0,0]) cylinder(h_block,d=w_block);
                translate([0,0,h_block]) {
                    rotate([0,0,90]) linear_extrude(2) 
                    text("P",12,valign="center", halign="center");
                    linear_extrude(2) polygon([[-14,0],[-10,4],[-10,-4]]);
                }
           }
           //Block 2
           translate([0,y_block2,0]) {
                connector_pair();
                translate([-$l_insert/2,0,h_block/2]) cube([l_block,w_block,h_block],true);
                translate([-(l_block+$l_insert)/2,0,0]) cylinder(h_block,d=w_block);
                translate([0,0,h_block]) {
                    rotate([0,0,90]) linear_extrude(2) 
                    text("P",12,valign="center", halign="center");
                    linear_extrude(2) polygon([[14,0],[10,4],[10,-4]]);
                }
          }
           //Block 3
           translate([0,y_block3,0]) {
                connector_pair(d0=$d_secondary);
                translate([-$l_insert/2,0,h_block/2]) cube([l_block,w_block,h_block],true);
                translate([-(l_block+$l_insert)/2,0,0]) cylinder(h_block,d=w_block);
                translate([0,0,h_block]) {
                    rotate([0,0,90]) linear_extrude(2) 
                    text("S",12,valign="center", halign="center");
                    linear_extrude(2) polygon([[-14,0],[-10,4],[-10,-4]]);
                }
           }
           //Mounting holes 
           translate([0,0,h_block/2]) {
               cube([14,30+3*w_block,h_block], true);
           }
        }
        //Negative
        union() {
            //Block 0
            translate([0,y_block0,0]) {
                channel();
                sensor();
            }
            //Block 1
            translate([0,y_block1,0]) {
                channel();
                sensor();
            }
            //Block 2
            translate([0,y_block2,0]) {
                channel();
                sensor();
            }
            //Block 3
            translate([0,y_block3,0]) {
                channel();
                sensor();
            }
            //Mounting holes
            translate([0,(y_block0+y_block1)/2,0]) mounting_hole();   
            translate([0,(y_block1+y_block2)/2,0]) mounting_hole();   
            translate([0,(y_block2+y_block3)/2,0]) mounting_hole();               
        }
    }
}

//if ($preview) {

    quad_sensor();
//}