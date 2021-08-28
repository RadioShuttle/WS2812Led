
#include <Arduino.h>
#include "WS2812Led.h"


#if defined(ARDUINO_ESP32S2_DEV)
static const uint8_t WS2812LedPin = 18;
#elif defined(ARDUINO_ESP32C3_DEV)
static const uint8_t WS2812LedPin  = 8;
#else
 #error "unknown board/pin"
#endif

WS2812Led wsLED(WS2812LedPin, 10);

void setup() {
  Serial.begin(115200);
  delay(100); // allow to flush boot messages

  Serial.printf("WS2812Led start: %%d LED's\n", wsLED.NumberOfLeds()); 

  wsLED.Brightness(32);
   
  wsLED.UpdateAll(10, 0, 0);
  delay(1000);
  wsLED.Clear();
  wsLED.Brightness(32);

  for (int i = 0; i < wsLED.NumberOfLeds(); i++) {
    switch(i % 10) {
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
      wsLED.Update(wsLED.GRAY, i, false);
      break;
    case 7:
      wsLED.Update(wsLED.PURPLE, i, false);
      break;
    case 8:
      wsLED.Update(wsLED.NAVY, i, false);
      break;
    case 9:
      wsLED.Update(wsLED.OLIVE, i, false);
      break;
    default:
      wsLED.Update(wsLED.WHITE, i, false);
      break;
   }
  }

  wsLED.Show();
  delay(3000);
  

  Serial.print("WS2812Led continue\n");
}

void loop() {
  wsLED.Rotate();
  delay(400);
  printf("loop\n");
}
