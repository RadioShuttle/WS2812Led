
#include <Arduino.h>
#include "WS2812Led.h"


#if defined(ARDUINO_ESP32S2_DEV)
 #define WS2812LedPin  18
#elif defined(ARDUINO_ESP32C3_DEV)
 #define WS2812LedPin  8
#else
 #error "unknown board/pin"
#endif


void setup() {
  Serial.begin(115200);
  delay(100); // allow to flush boot messages

  Serial.print("WS2812Led start\n");
  WS2812Led wsLED(WS2812LedPin, 10);
 

  wsLED.Brightness(32);
   
  wsLED.UpdateAll(10, 0, 0);
  delay(1000);
  wsLED.Clear();
  wsLED.Brightness(32);
  delay(1000);
  wsLED.UpdateAll(wsLED.OLIVE);
  delay(1000);
  wsLED.UpdateAll(wsLED.RED);
  delay(1000);
  wsLED.UpdateAll(wsLED.YELLOW);
  delay(1000);
  wsLED.UpdateAll(wsLED.PURPLE);
  delay(1000);
  wsLED.UpdateAll(wsLED.GREEN);
  delay(1000);
  wsLED.UpdateAll(wsLED.MAROON);
  delay(1000);
  wsLED.UpdateAll(wsLED.NAVY);
  delay(1000);

  Serial.print("WS2812Led end\n");
}

void loop() {

}
