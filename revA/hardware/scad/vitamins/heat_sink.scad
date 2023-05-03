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
//#   Generic model of a heat sink                                              #
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   June  8, 2020                                                             #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################
  
//! Generic model of a heat sink
include <NopSCADlib/utils/core/core.scad>

function hs_name(type)     = type[0];  //! Part code without shield type suffix
function hs_Xbase(type)    = type[1];  //! X dimensions of the base
function hs_Ybase(type)    = type[2];  //! Y dimensions of the base
function hs_Zbase(type)    = type[3];  //! Z dimensions of the base
function hs_Xfins(type)    = type[4];  //! X dimensions of the fins
function hs_Yfins(type)    = type[5];  //! Y dimensions of the fins
function hs_Zfins(type)    = type[6];  //! Z dimensions of the fins
function hs_Cfins(type)    = type[7];  //! Fins count
function hs_holes(type)    = type[8];  //! Drill holes
function hs_Xhole(htype)   = htype[0]; //! X position of the hole
function hs_Yhole(htype)   = htype[1]; //! Y position of the hole
function hs_Dhole(htype)   = htype[2]; //! Diameter of the hole

//Heat sink vitamin
module heat_sink(type, center=false) { //! Draw a heat sink
    vitamin(str("heat_sink(HS_", hs_name(type), "): Heat sink ", hs_Xbase(type), "mm x ", hs_Ybase(type), "mm x ", hs_Zfins(type), "mm"));
    //Local variables
    Xbase = hs_Xbase(type);
    Ybase = hs_Ybase(type);
    Zbase = hs_Zbase(type);
    Xfins = hs_Xfins(type);
    Yfins = hs_Yfins(type);
    Zfins = hs_Zfins(type);
    Cfins = hs_Cfins(type);
    holes = hs_holes(type);
    
    //Fins
    Wfins     = 1;                       // Width of a fin
    Sfins     = (Xfins-Wfins)/(Cfins-1); // Distance between fins
    Xfirstfin = (Xbase-Xfins)/2;         // X position of the first fin
    Xlastfin  = Xbase-(Xfirstfin+Wfins); // X position of the last fin
    
    //Holes
    Choles = len(holes);
    
    color(silver)
    translate([(center) ? -Xbase/2 : 0,
               (center) ? -Ybase/2 : 0,
                                     0]) {
        difference() {
            union() {                                         
                cube([Xbase,Ybase,Zbase]);
                for (x=[Xfirstfin:Sfins:Xlastfin]) {
                    translate([x,(Ybase-Yfins)/2,0]) cube([Wfins,Yfins,Zfins]);
                }
            }
            union() {
                for (idx=[0:1:Choles-1]) {
                    hole  = holes[idx]; 
                    Xhole = hs_Xhole(hole);
                    Yhole = hs_Yhole(hole);
                    Dhole = hs_Dhole(hole);
                    translate([Xhole,Yhole,-1]) cylinder(Zfins+2, d=Dhole);
                }        
            }
        }
    }
} 
    
if($preview) {      
         heat_sink(["WB40x40", 58, 40, 2, 40, 40, 17.5, 9, [[4,20,4],[54,20,4]]], false);     
}
 
    