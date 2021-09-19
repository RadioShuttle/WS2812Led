
#include <Arduino.h>
#include "WS2812Led.h"



#if defined(ARDUINO_ESP32S2_DEV) || defined(ARDUINO_ESP32S2_USB)
static const uint8_t WS2812LedPin = 18;
#elif defined(ARDUINO_ESP32C3_DEV)
static const uint8_t WS2812LedPin  = 8;
#elif defined(ARDUINO_ESP32_DEV)
static const uint8_t WS2812LedPin  = 4;
#else
 #error "unknown board/pin"
#endif

WS2812Led wsLED(WS2812LedPin, 18, WS2812Led::LED_RGBW);

void setup() {
  Serial.begin(115200);
  delay(100); // allow to flush boot messages

  Serial.printf("WS2812Led start: %d LED's\n", wsLED.NumberOfLeds()); 

  wsLED.Brightness(32);
  wsLED.UpdateAll(10, 10, 10);
  delay(1000);

  for (int round = 0; round <= 3; round++) {

    switch(round) {
    case 0:
      wsLED.UpdateAll(wsLED.RED);
      break;
    case 1:
      wsLED.UpdateAll(wsLED.GREEN);
      break;
    case 2:
      wsLED.UpdateAll(wsLED.BLUE);
      break;
    case 3:
       wsLED.UpdateAll(wsLED.WHITE_RGBW);
       break;
    default:
      break;
    }
    
    for (int brightness = 1; brightness <= 129; brightness += 8) {
       wsLED.Brightness(brightness-1);
       wsLED.Show();
       Serial.printf("brightness: %d\n", brightness-1);
       delay(500);
    }
  }

  
  wsLED.Clear();
  wsLED.Brightness(32);

  for (int i = 0; i < wsLED.NumberOfLeds(); i++) {
    switch(i % wsLED.NumberOfLeds()) {
    case 0:
      wsLED.Update(wsLED.RED, i, false);
      break;
    case 1:
      wsLED.Update(wsLED.GREEN, i, false);
      break;
    case 2:
      wsLED.Update(wsLED.BLUE, i, false);
      break;
    case 3:
      wsLED.Update(wsLED.WHITE, i, false);
      break;
    case 4:
      wsLED.Update(wsLED.YELLOW, i, false);
      break;
    case 5:
      wsLED.Update(wsLED.FUCHSIA, i, false);
      break;
    case 6:
      wsLED.Update(wsLED.GRAY_RGBW, i, false);
      break;
    case 7:
      wsLED.Update(wsLED.PURPLE, i, false);
      break;
    case 8:
      wsLED.Update(wsLED.NAVY, i, false);
      break;
    case 9:
      wsLED.Update(wsLED.ORANGE, i, false);
      break;
    case 10:
      wsLED.Update(wsLED.WHITE_RGBW, i, false);
      break;
    case 11:
      wsLED.Update(wsLED.PINK, i, false);
      break;
    case 12:
      wsLED.Update(wsLED.SKYBLUE, i, false);
      break;
    case 13:
      wsLED.Update(wsLED.SKYBLUE2, i, false);
      break;
    case 14:
      wsLED.Update(wsLED.TURQUOISE, i, false);
      break;
    case 15:
      wsLED.Update(wsLED.BLACK, i, false);
      break;
    case 16:
      wsLED.Update(wsLED.BLACK, i, false);
      break;   
    default:
      wsLED.Update(wsLED.BLACK, i, false);
      break;
   }
  }

  wsLED.Show();
  delay(3000);
  

  Serial.print("WS2812Led continue with rotate\n");
}

void loop() {
  wsLED.Rotate();
  delay(300);
  Serial.printf("Rotate Leds\n");
}
