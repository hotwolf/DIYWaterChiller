//###############################################################################
//# DIYWaterChiller - Vitamins -Water Blocks                                    #
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
//#   Generic model of an aluminum water chiller block                          #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  7, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
  
//! Generic model of an aluminum water chiller block
include <NopSCADlib/utils/core/core.scad>

function wb_name(type)     = type[0]; //! Part code without shield type suffix
function wb_Xdim(type)     = type[1]; //! X dimensions
function wb_Ydim(type)     = type[2]; //! Y dimensions
function wb_Zdim(type)     = type[3]; //! Z dimensions
function wb_C1Xoffs(type)  = type[4]; //! X offset of the first connector
function wb_C1Zoffs(type)  = type[5]; //! Z offset of the first connector
function wb_C2Xoffs(type)  = type[6]; //! X offset of the second connector
function wb_C2Zoffs(type)  = type[7]; //! Z offset of the second connector

//Connector
module wb_connector(x=0, z=0) {
    
    translate([x,0,z]) {  
    
        translate([0,0,0]) rotate([90,0,0]) cylinder(2,d=10); 
        translate([0,0,0]) rotate([270,0,0]) rotate_extrude() 
        polygon( points=[[2.2,  0  ],
                         [2.2,-15  ],
                         [3  ,-15  ],
                         [4.6, -9.5],
                         [4  , -9.5],
                         [4  ,  0  ]]);
    }
}



//Water block vitamin
module water_block(type, center=false) { //! Draw a water block
    vitamin(str("water_block(WB", wb_name(type), "): Water block ", wb_Xdim(type), "mm x ", wb_Ydim(type), "mm x ", wb_Zdim(type), "mm"));
    //Local variables
    Xdim    = wb_Xdim(type);
    Ydim    = wb_Ydim(type);
    Zdim    = wb_Zdim(type);
    C1Xoffs = wb_C1Xoffs(type);
    C1Zoffs = wb_C1Zoffs(type);
    C2Xoffs = wb_C2Xoffs(type);
    C2Zoffs = wb_C2Zoffs(type);
    
    color(silver)
    translate([(center) ? -Xdim/2 : 0,
               (center) ? -Ydim/2 : 0,
               (center) ? -Zdim/2 : 0]) {
                  
        cube([Xdim,Ydim,Zdim]);
        wb_connector(x=C1Xoffs,z=C1Zoffs);
        wb_connector(x=C2Xoffs,z=C2Zoffs);
                           
    }
} 
    
if($preview) {      
         water_block(["40x80", 40, 80, 12.5, 6, 6.25, 34, 6.25], false);     
}
 
    