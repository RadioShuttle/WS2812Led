# WS2812Led – a WS2812B library for the ESP32
![Title image](/docs/WS2812Led-Sample.jpg)

As more boards are fitted with WS2812 based LEDs, there is a need for a simple and good performing library to drive these on-board LED or multiple LED stripes. The idea is to provide a lightweight and great performing library.

WS2812Led performs well and is a clean C++ implementation. It allows being initialized with multiple instances to drive several LED stripes in parallel. Transferring the data to the LEDs is done in the background via the ESP32 built-in RMT controller, which supports up to 8 channels (instances).

There is a base implementation with common code and an interface for the MCU specific code. At present, the ESP32 series is implemented, support for STM32L4 under Mbed OS is planned.

![WS2812B Stripe](/docs/WS2012B-Stripe.jpg)

Example code:
<pre>
{
    WS2812Led wsLED(WS2812LedPin, 10); // 10 LEDs on GPIO 8
	
    wsLED.Update(10, 0, 0); // light red, RGB values 0-255, 
    delay(1000);
    wsLED.Clear();
    wsLED.Brightness(32);
    wsLED.UpdateAll(wsLED.RED);
    ... // set each LED as required via Update(..., LEDIndex);
    delay(1000);
    while(true) {
        wsLED.Rotate(); // rotate all LEDs one right
        delay(300);
 }
</pre>

Helmut Tschemernjak
www.radioshuttle.de

## Supported ESP MCUs
- ESP32
- ESP32-S2
- ESP32-C3

## Technical background
For each WS2812B LED stripe (or just a single LED) an RGB (24-bit) or RGBW (32-bit) LED buffer array is used to store the data for LEDs. Clear(), Update(), Rotate() will fill this LED buffer. Show() converts the LED buffer into signals buffer and programs the RMT unit which generates timed bit patterns from the signal instructions and outputs these on the specified GPIO pin. During these transfers the MCU is idle and can handle other tasks.
The WS2812B timing has been implemented, verified and optimized to work precisely and fast.

## TODOs
- more testing, test the RGBW LEDs
- test with different MCU frequencies
- testing with the WS2812B 2020 LEDs, have not seen such versions, or they just work. The 2020 timings are different!

## License and contributions

The software is provided under the Apache 2.0 license. Contributions to this project are accepted under the same license.

## Links
- ESP32 RMT (Remote Control Peripherals)  https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/rmt.html
- Datahseet WS2812B: see documentation [WS2812B](/docs/WS2812B.pdf)
- Datahseet WS2812B-2020: see documentation [WS2812B-2020](/docs/WS2812B-2020_V10_EN.pdf)
- LED Strips, what's the difference? WS2811, WS2812B, 2812Eco, WS2813, WS2815, SK6812, SK9822. [LED Strips] (/https://www.youtube.com/watch?v=QnvircC22hU)
