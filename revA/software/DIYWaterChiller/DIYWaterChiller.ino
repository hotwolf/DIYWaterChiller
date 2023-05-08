//###############################################################################
//# DIYWaterChiller - Firmware                                                  #
//###############################################################################
//#    Copyright 2023 Dirk Heisswolf                                            #
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
//#   Firmware for the DIYWaterChiller                                          #
//#                                                                             #
//#   !!! Set the Sketchbook location to               !!!                      #
//#   !!!  <DIYWaterChiller repository>/revA/software/ !!!                      #   
//#                                                                             #
//###############################################################################
//# Version History:                                                            #
//#   May 4, 2023                                                               #
//#      - Initial release                                                      #
//#                                                                             #
//###############################################################################

// Common definitions
#define VERSION_STR "DIYWaterChiller FW00.00"

//Display definitions
#define TFT_DC  12
#define TFT_CS  -1
#define TFT_RST -1
#define TFT_SDI 11
#define TFT_SCK 13

//Timer interrupt definitions
#define USE_TIMER_1           true
#define USE_TIMER_2           false
#define TIMER_INTERVAL_100MS  100L
#define TIMER_INTERVAL_1S     1000L

//Flow meter definitions
#define FLOW_IN   2
#define FLOW_OUT  3

//DS18B20 definitions
#define ONEWIRE_SEARCH  0
#define ONEWIRE_PIN     4

//Libraries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <TimerInterrupt.h>
#include <ISR_Timer.h>
#include <OneWire.h>
#include <DS18B20.h>

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);
ISR_Timer        ISR_timer;
DS18B20          ds(ONEWIRE_PIN);

int flow_in_cnt, flow_out_cnt;   //Flow meter counters
int flow_in_freq, flow_out_freq; //Flow meter frequency
int flow_in_disp, flow_out_disp; //Flow meter display value

//Code running every 100ms
//inline void execute_every_100ms() __attribute__((always_inline));
void execute_every_100ms ()
{

}

//Code running every 1s
//inline void execute_every_1s() __attribute__((always_inline));
void execute_every_1s ()
{
  flow_in_freq = flow_in_cnt;
  flow_in_cnt  = 0;
  flow_out_freq = flow_in_cnt;
  flow_out_cnt  = 0;
}

//Timer handler
void TimerHandler()
{
  execute_every_100ms ();

  ISR_timer.run();
}

//Flow meter inlet event
void flow_in_isr()
{
   flow_in_cnt++;
}

//Flow meter inlet event
void flow_out_isr ()
{
    flow_out_cnt++;
}

//Setup
void setup() {

  //Setup SCI
  Serial.begin(9600);
  Serial.println(VERSION_STR); 
 
  Serial.print("Devices: ");
  Serial.println(ds.getNumberOfDevices());
  Serial.println();

  // //Setup TFT display
  // tft.begin();
  // tft.fillScreen(ILI9341_BLUE);  
  // tft.setTextSize(1);
  // tft.setCursor(0, 0);
  // tft.setTextColor(ILI9341_WHITE);
  // tft.println(VERSION_STR);

  //  //Setup flow meters
  // pinMode(FLOW_IN, INPUT_PULLUP);  
  // pinMode(FLOW_OUT, INPUT_PULLUP);
  // // attachInterrupt(digitalPinToInterrupt(FLOW_IN), flow_in_isr, CHANGE);
  // // attachInterrupt(digitalPinToInterrupt(FLOW_OUT), flow_out_isr, CHANGE);
  // flow_in_cnt   =  0;
  // flow_out_cnt  =  0;
  // flow_in_freq  =  0; 
  // flow_out_freq =  0;
  // flow_in_disp  = -1;
  // flow_out_disp = -1;
  // tft.setCursor(0, 10);
  // tft.println("IN [Hz]:");
  // tft.setCursor(0, 30);
  // tft.println("OUT [Hz]:");

  //Setup timer
  // ITimer1.init();
  // // Interval in unsigned long millisecs
  // ITimer1.attachInterruptInterval(TIMER_INTERVAL_100MS, TimerHandler);
  // ISR_timer.setInterval(TIMER_INTERVAL_1S, execute_every_1s);


}

//Loop
void loop() {

  // //Display IN flow
  // if (flow_in_disp != flow_in_freq) {
  //   flow_in_disp = flow_in_freq;
  //     tft.setCursor(0, 20);
  //     tft.println(flow_in_disp);
  // }

  // //Display OUT flow
  // if (flow_out_disp != flow_out_freq) {
  //   flow_out_disp = flow_out_freq;
  //     tft.setCursor(0, 40);
  //     tft.println(flow_in_disp);
  // }
  Serial.println("scan...");
  while (ds.selectNext()) {
    switch (ds.getFamilyCode()) {
      case MODEL_DS18S20:
        Serial.println("Model: DS18S20/DS1820");
        break;
      case MODEL_DS1822:
        Serial.println("Model: DS1822");
        break;
      case MODEL_DS18B20:
        Serial.println("Model: DS18B20");
        break;
      default:
        Serial.println("Unrecognized Device");
        break;
    }

    uint8_t address[8];
    ds.getAddress(address);

    Serial.print("Address:");
    for (uint8_t i = 0; i < 8; i++) {
      Serial.print(" ");
      Serial.print(address[i]);
    }
    Serial.println();

    Serial.print("Resolution: ");
    Serial.println(ds.getResolution());

    Serial.print("Power Mode: ");
    if (ds.getPowerMode()) {
      Serial.println("External");
    } else {
      Serial.println("Parasite");
    }

    Serial.print("Temperature: ");
    Serial.print(ds.getTempC());
    Serial.print(" C / ");
    Serial.print(ds.getTempF());
    Serial.println(" F");
    Serial.println();
  }

  delay(10000);
}
