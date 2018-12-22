# WPro58 for Eachine PRO58 and Quanum HB5808 modules.
Source code and more information can be found at [piodabro's WPro58](https://github.com/piodabro/WPro58).

### User Guide for v0.9 

### Starts up in search mode utilizing the last channel used before prior power down.

### integrated Fatshark buttons will allow up down actions within the current band.

### Normal functionality of integrated module buttons:
module short duration center button press will stop scanning
module medium duration center button press enables option to allow short press to switch A/m M/a button modes. (auto and manual)
-M/a allows quick module up or down press to change one channel and hold module up or down press to scroll through channels
-A/m allows quick module up or down press to begin scanning for next used channel

### long duration center button press opens main menu system
Available items in main menu are:
search, favourites, band scan, settings

### Search mode is the default at power-up and allows searching and stepping.

### Favourites allows you to flip though eight channels defined within "favorites" section of settings.

### Band scan quickly scans over the entire band creating an RSSI graph.

### Settings available are:
-rssi calibration ( short module center press - read and follow on screen prompts to calibrate the RSSI for diversity switching )
-favorite channels ( short module center press - opens 8 favorites for edit )
-callsign ( short module center press - allows setting callsign which shows in screensaver cylce )
-diversity mode ( short module center press - allows switching AUTO, A, B )
-buzzer( short module center press - allows switching ON, OFF )
-Screensaver ( short module center press - allows switching ON, OFF )
-Flip screen ( short module center press - allows switching NORM, FLIP )
-FS pins mode ( short module center press - allows switching FS, Button ) Warning if you change this setting on FatShark googles you will need to remove the module and externally power it in order to re-enter the settings and revert FS pins mode back to FS.
-reset settings
-exit

#### Warning!
If you use module with FatShark goggles make sure that FS pins mode setting is set to FS (not BUTTON).
This settings changes pullup settings on FS channel pins.

To use BUTTON mode simply add buttons that connect pin to ground when pressed.

___

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
