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

void a() {
  dot();
  dash();
}

void b() {
  dash();
  dot();
  dot();
  dot();
}

void c() {
  dash();
  dot();
  dash();
  dot();
}

void d() {
  dash();
  dot();
  dot();
}

void e() {
  dot();
}

void f() {
  dot();
  dot();
  dash();
  dot();
}

void g() {
  dash();
  dash();
  dot();
}

void h() {
  dot();
  dot();
  dot();
  dot();
}

void i() {
  dot();
  dot();
}

void j() {
  dot();
  dash();
  dash();
  dash();
}

void k() {
  dash();
  dot();
  dash();
}

void l() {
  dot();
  dash();
  dot();
  dot();
}

void m() {
  dash();
  dash();
}

void n() {
  dash();
  dot();
}

void o() {
  dash();
  dash();
  dash();
}

void p() {
  dot();
  dash();
  dash();
  dot();
}

void q() {
  dash();
  dash();
  dot();
  dash();
}

void r() {
  dot();
  dash();
  dot();
}

void s() {
  dot();
  dot();
  dot();
}

void t() {
  dash();
}

void u() {
  dot();
  dot();
  dash();
}

void v() {
  dot();
  dot();
  dot();
  dash();
}

void w() {
  dot();
  dash();
  dash();
}

void x() {
  dash();
  dot();
  dot();
  dash();
}

void y() {
  dash();
  dot();
  dash();
  dash();
}

void z() {
  dash();
  dash();
  dot();
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
  else if (input == 'a') {
    a();
  }
  else if (input == 'b') {
    b();
  }
  else if (input == 'c') {
    c();
  }
  else if (input == 'd') {
    d();
  }
  else if (input == 'e') {
    e();
  }
  else if (input == 'f') {
    f();
  }
  else if (input == 'g') {
    g();
  }
  else if (input == 'h') {
    h();
  }
  else if (input == 'i') {
    i();
  }
  else if (input == 'j') {
    j();
  }
  else if (input == 'k') {
    k();
  }
  else if (input == 'l') {
    l();
  }
  else if (input == 'm') {
    m();
  }
  else if (input == 'n') {
    n();
  }
  else if (input == 'o') {
    o();
  }
  else if (input == 'p') {
    p();
  }
  else if (input == 'q') {
    q();
  }
  else if (input == 'r') {
    r();
  }
  else if (input == 's') {
    s();
  }
  else if (input == 't') {
    t();
  }
  else if (input == 'u') {
    u();
  }
  else if (input == 'v') {
    v();
  }
  else if (input == 'w') {
    w();
  }
  else if (input == 'x') {
    x();
  }
  else if (input == 'y') {
    y();
  }
  else if (input == 'z') {
    z();
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
    Serial.print("Character received: ");
    Serial.println(input);
    encode(); //encodes each unit separately
    delay(3000); //wait between two numbers (3 second delay to be clear) 
  }
//  input = '6'; //to test without two serial monitors
//  encode();

}
