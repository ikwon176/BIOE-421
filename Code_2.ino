#include "Adafruit_LC709203F.h"
#include <Adafruit_CircuitPlayground.h>
//https://learn.adafruit.com/adafruit-lc709203f-lipo-lipoly-battery-monitor/overview
//library https://github.com/adafruit/Adafruit_LC709203F
Adafruit_LC709203F lc;

void setup() {
//  Serial.begin(115200);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
//  delay(10);
//  Serial.println("\nAdafruit LC709203F demo");

//  if (!lc.begin()) {
//    Serial.println(F("Couldnt find Adafruit LC709203F?\nMake sure a battery is plugged in!"));
//    while (1) delay(10);
//  }
//  Serial.println(F("Found LC709203F"));
//  Serial.print("Version: 0x"); Serial.println(lc.getICversion(), HEX);

//  lc.setThermistorB(3950);
//  Serial.print("Thermistor B = "); Serial.println(lc.getThermistorB());

  lc.setPackSize(LC709203F_APA_3000MAH); //lithium ion battery of 2500 MAH

  lc.setAlarmVoltage(3.8);
}

void loop() {
//  Serial.print("Batt Voltage: "); Serial.println(lc.cellVoltage(), 3);
//  Serial.print("Batt Percent: "); Serial.println(lc.cellPercent(), 1);
//  Serial.print("Batt Temp: "); Serial.println(lc.getCellTemperature(), 1);
  if (lc.cellPercent() < 10) {
    CircuitPlayground.setPixelColor(0, 0xFF0000); //for 10% charge (low battery)
  }
  else if (lc.cellPercent() > 11 && lc.cellPercent() < 50) {
    CircuitPlayground.setPixelColor(1, 0xFF8000); //for between 11% and 50% charge
  }
  else if (lc.cellPercent() > 51 && lc.cellPercent() < 75) {
    CircuitPlayground.setPixelColor(2, 0xFFFF00); //for between 51% and 75% charge
  }
  else if (lc.cellPercent() > 96 && lc.cellPercent() > 100) {
    CircuitPlayground.setPixelColor(3, 0x00FF00); //for 100% charge
  }

  delay(60000);  // check every minute
}
