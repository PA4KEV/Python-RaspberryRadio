#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 7
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);

  void setup() {
    pinMode(6, OUTPUT);
    strip.begin();
    strip.show();
  }
  
  void loop() {
    rainbowCycle(1);
  }

  void colorWipe(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }
  
  void rainbow(uint8_t wait) {
    uint16_t i, j;
   
    for(j=0; j<256; j++) {
      for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel((i+j) & 255));
      }
      strip.show();
      delay(wait);
    }
  }

  void rainbowCycle(uint8_t wait) {
    uint16_t i, j;
   
    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
      for(i=0; i< strip.numPixels(); i++) {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
      strip.show();
      delay(wait);
    }
  }
  
  void flash()
  {
    for(int dot = 0; dot < NUM_LEDS; dot++) { 
      strip.setPixelColor(dot, 255, 0, 110); 
      strip.show();
      delay(200);
      strip.setPixelColor(dot, 0, 0, 0); 
      strip.show();
      delay(200);
    }  
  }

  // Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
  
