#include <Adafruit_CircuitPlayground.h>

//Define variables
int dottime = 500;
int dashtime = 1500;
int breaktime = 1000;
int endtime = 7000;

char input = 0;

//Blink Pattern for Dots
void dot() {
  CircuitPlayground.clearPixels(); //neopixels off
  CircuitPlayground.setPixelColor(2, 0xFF3399); //turn on neopixels
  delay(dottime); //on for dottime milliseconds (short)
  CircuitPlayground.clearPixels(); //neopixels off
  delay(breaktime);
}

//Blink Pattern for Dashes
void dash() {
  CircuitPlayground.clearPixels(); //neopixels off
  CircuitPlayground.setPixelColor(2, 0xFF3399); //turn on neopixels
  delay(dashtime); //on for dashtime milliseconds (long)
  CircuitPlayground.clearPixels(); //neopixels off
  delay(breaktime);
}

//For numbers 0-9
void zero() {
  dash();
  dash();
  dash();
  dash();
  dash();
}

void one() {
  dot();
  dash();
  dash();
  dash();
  dash();
}

void two() {
  dot();
  dot();
  dash();
  dash();
  dash();
}

void three() {
  dot();
  dot();
  dot();
  dash();
  dash();
}

void four() {
  dot();
  dot();
  dot();
  dot();
  dash();
}

void five() {
  dot();
  dot();
  dot();
  dot();
  dot();
}

void six() {
  dash();
  dot();
  dot();
  dot();
  dot();
}

void seven() {
  dash();
  dash();
  dot();
  dot();
  dot();
}

void eight() {
  dash();
  dash();
  dash();
  dot();
  dot();
}

void nine() {
  dash();
  dash();
  dash();
  dash();
  dot();
}

//Encode inputted numbers to morse code numbers and illuminates neopixel appropriately
void encode() {
  if (input == '0') {
    zero();
  }
  else if (input == '1') {
    one();
  }
  else if (input == '2') {
    two();
  }
  else if (input == '3') {
    three();
  }
  else if (input == '4') {
    four();
  }
  else if (input == '5') {
    five();
  }
  else if (input == '6') {
    six();
  }
  else if (input == '7') {
    seven();
  }
  else if (input == '8') {
    eight();
  }
  else if (input == '9') {
    nine();
  }
  else { //if it is not an integer, returns invalid input
    Serial.print("Invalid input");
  }

}

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) //check for input in serial monitor
  {
    input = Serial.read();
    Serial.print("Number received: ");
    Serial.println(input);
    encode(); //encodes each unit separately
  }
  delay(4500); //wait between two numbers (3 second delay to be clear)
}
