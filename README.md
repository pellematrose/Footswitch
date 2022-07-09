# Page Turner

Playing on stage an instrument where you need both hands, bass guitar in my case, it is uncomfortable to find a break to touch on the tablet to get to the next song. There are already Page Turn devices on the market but they start at 85€. That is not worth for me so I decided to build my own.
The ESP is acting as a HID exposed over BLE. With pushing a button the ESP will send a command to turn over to the next page or going one page back with the other button.
The electronics is feed by a small Li-Ion battery. It is charged over micro USB.

Works with Android (Songbook Pro, Adobe Reader), iPad (Onsong, Adobe Reader), many more

Components you need:
- ESP32 Lolin Lite (comes with Li-Ion charger and LDO)
- Li-Ion Battery
- 2 Momentary (foot-)switches
- ON / OFF switch
- 3D Printer
- 4 Screws

![Page_Turner](https://github.com/pellematrose/PageTurner/blob/main/Page_Turner.jpg)
