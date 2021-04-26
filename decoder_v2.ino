#include <Adafruit_CircuitPlayground.h>

int threshold = 10;
char code;
unsigned long starttime;
unsigned long endtime;
char morse[6];
int morse_index = 0;
boolean prevstate;
static char *_list[10] = {".----",       // 1
                          "..---",     // 2
                          "...--",     // 3
                          "....-",      // 4 
                          ".....",        // 5
                          "-....",     // 6
                          "--...",      // 7
                          "---..",     // 8
                          "----.",       // 9
                          "-----",};     // '0'

void convert_morse()
{
  Serial.println("CONVERT: ");
  Serial.println(code);

  for (int x = 0; x < 26; x++)
  {
      if (strcmp(_list[x], code) == 0)
      {
        Serial.println("GOT: ");
        Serial.print((char)(x+'a'));
      }
  }
  
  // could not decode what was read
  return '?';
}

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  Serial.begin(9600);

  starttime = endtime = 0;

  Serial.println("Finished setup");
}

//Numbers and their corresponding dash/dot morse code

void loop() {
  boolean state;
  // Based on time that light has been on, will assign either dot or dash
  if (CircuitPlayground.lightSensor() < threshold) {
    state = LOW;
  }
  else {
    state = HIGH;
  }
  if (state != prevstate) {
    endtime = millis(); //maybe calc duration out here?
    if (prevstate == HIGH) {
      if (((endtime - starttime) < 600) && ((endtime - starttime) > 400)) {
        morse[morse_index] = '.';
      }
      else if ((endtime - starttime)> 1400 && (endtime - starttime) <1600) {
        morse[morse_index] = '-';
      }
     morse_index++;
     morse[morse_index] = '\0';
  }
  else {
    if ((endtime - starttime) > 1800) {
      Serial.print(' ');
      morse_index = 0;
    }
  }
    prevstate = state;
    starttime = endtime;
  }
}
