---
layout: post
title:  Bad 3D Printing
---

I'm now trying to build a Peltier cooling system with two water circuits. The primary circuit on the cold side of the Peltier elements cools the larer tube. The secondary circuit on the hot side of the Peltier elements dissipates the heat through radiators. I want to monitor the temperature of both circuits before and after the Peltier element with [DS18B20 temperature sensors](https://www.maximintegrated.com/en/products/sensors/healthcare-sensor-ics/electrochemical-sensor-afe-ics/DS18B20.html).
I coud not find any fitting that would allow me to insert the sensors into the water flow. So I designed this [part](https://github.com/hotwolf/DIYWaterChiller/blob/master/stls/quad_sensor.stl):

![aluminium coated tank](images/quad_sensor.png)

My first two attempts at printing this part in PETG turned out like this:

![aluminium coated tank](images/bad_printing_1.jpg)

The bottom part turnd out ok, but the fine hose connectors became stringy and fragile.

I tried to resolve this problem by cooling down the print as soon as the bottom part got done. My printer doesn't have a build-in cooling fan, so placed a big fan next to it.
During my first attempt, the battery of my laptop died mid-print. But you can see how the temperature sensors fit.

![aluminium coated tank](images/bad_printing_2.jpg)

In my next attempt the fan apparently cooled the extruder so far down, that it blocked the filament flow.

![aluminium coated tank](images/bad_printing_3.jpg)

Thes part is too hard to print. It needs a redesign.