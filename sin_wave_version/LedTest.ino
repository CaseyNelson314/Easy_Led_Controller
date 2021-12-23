#define LEDSUM 20
#include <Adafruit_NeoPixel.h>
#include "LedControl.h"
Adafruit_NeoPixel serialLed(LEDSUM, 13, NEO_RGB + NEO_KHZ800);
LedControl ledCtrl(4000, LEDSUM, 40);

void setup() {
  ledCtrl.SetBrightness(50);
  serialLed.begin();
  Serial.begin(115200);
}

void loop() {
  ledCtrl.Update();
  for (int i = 0; i < LEDSUM; i++)
    serialLed.setPixelColor(i, ledCtrl.GetR(i), ledCtrl.GetG(i), ledCtrl.GetB(i));
  Serial.print(ledCtrl.GetR()); Serial.print("\t");
  Serial.print(ledCtrl.GetG()); Serial.print("\t");
  Serial.print(ledCtrl.GetB()); Serial.print("\n");
  serialLed.show();
}
