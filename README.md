# WS2812Led – an WS2812B library for the ESP32

As more boards are coming with the WS2812 based LEDs there is a need for a simple and good performing library to drive these on board LED or multiple LED stripes. The idea is provide a lightweight and great performing library.

WS2812Led performs well and is clean C++ implementation. It allows to be initialised with multiple instances to drive several LED stripes in parallel. Transferring the data to the LEDs is done in background via the ESP32 built-in RMT controller which supports up to 8 channels (instances).

There is a base implementation with common code and an interface for the MCU specific code. At present ESP32 series is implemented, support for STM32L4 under Mbed-OS is planned.

Example code:
<pre>
{
WS2812Led wsLED(WS2812LedPin, 1); // here a single LED only, or any number of LEDs  specified
 wsLED.Update(10, 0, 0); // light red, RGB values 0-255, 
 delay(1000);
 wsLED.Clear();
 wsLED.Brightness(32);
 wsLED.UpdateAll(wsLED.RED); // add an index parameter at end for a specifiy LED
 delay(1000);
 while(true) {
	 wsLED.Rotate(); // rotate all LEDs on right
	delay(300);
 }
</pre>

Helmut Tschemernjak
www.radioshuttle.de

## Supported ESP MCU's
- ESP32
- ESP32-S2
- ESP32-C3

## Technical background
For each WS2812B LED stripe (or just a single LED) an RGB (24-bit) or RGBW (32-bit) led-buffer array is used to store the data for LEDs. Clear(), Update(), will fill this led-buffer. Show() will convert the led-buffer into signals-buffer and programs the RMT unit which generates timed bit patterns from the signal instructions and outputs these on the specified GPIO pin. During this transfers the MCU is idle and can handle other tasks.
The WS2812B timeing has been implemented, verified and optimized to work precise and fast.

## TODOs
- more testing, test the RGBW LEDs
- test with different MCU frequencies

## License and contributions

The software is provided under the Apache 2.0 license. Contributions to this project are accepted under the same license.
