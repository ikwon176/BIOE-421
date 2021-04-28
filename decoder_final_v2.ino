#include <Adafruit_CircuitPlayground.h>

boolean prevstate;

int threshold = 5; //for intensity

int dotmax = 700;
int dotmin = 100;
int dashmax = 1500;
int dashmin = 800;

int samemax = 800;
int samemin = 300;

unsigned long starttime;
unsigned long endtime;

const byte codelen = 15;
char code[codelen];
int code_idx = 0;

String output;

void decoder() {
  if (strcmp(code,".----") == 0) {
    output = "1";
  }
  else if (strcmp(code,"..---") == 0) {
    output = "2";
  }
  else if (strcmp(code,"...--") == 0) {
    output = "3";
  }
  else if (strcmp(code,"....-") == 0) {
    output = "4";
  }
  else if (strcmp(code,".....") == 0) {
    output = "5";
  }  
  else if (strcmp(code,"-....") == 0) {
    output = "6";
  }  
  else if (strcmp(code,"--...") == 0) {
    output = "7";
  } 
  else if (strcmp(code,"---..") == 0) {
    output = "8";
  } 
  else if (strcmp(code,"----.") == 0) {
    output = "9";
  } 
  else if (strcmp(code,"-----") == 0) {
    output = "0";
  } 
  else {
    output = "Invalid";
  }
  Serial.println(output);
}

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.begin(9600);
  prevstate = LOW;
  starttime = 0;
  endtime = 0;
}

void loop() {
  boolean state;

  //Assign state depending on intensity measured by light sensor
  if (CircuitPlayground.lightSensor() < threshold) {
    state = LOW;
  }
  else {
    state = HIGH;
  }

  //If light went either from off --> on or on --> off then:
  if (state != prevstate) {
    endtime = millis(); //current time reading is taken as end time
    
    //If on --> off: 
    if (prevstate == HIGH) { 
      if (endtime - starttime > dotmin && endtime - starttime < dotmax) { //start time is t=0 intially iteration bc initially in LOW
        Serial.println('.');
        code[code_idx] = '.'; //put into char array
      }
      else if (endtime - starttime > dashmin && endtime - starttime < dashmax) {
        Serial.println('-'); 
        code[code_idx] = '-'; //put into char array
      }
      else {
        code_idx--; //if invalid input then replace this index with following iteration
      }
      code_idx++; //next index in array
    }
    
  //If there is no change between previous state and current state
  else {

    if (endtime - starttime > samemin && endtime - starttime < samemax) {
      //it's okay that the state isn't changing for this amount of time
    }
    else if (endtime - starttime > 2500 && endtime - starttime < 5000) {
      Serial.println("Finished Receiving");

      //Initialize index (restart code)
      code_idx = 0;

      //To print/interpret the code
      for (int i = 0; i < codelen; i++) {
        char codeChar = code[i]; //because code[i] is an integer; ASCII

        Serial.print(codeChar);
      }
      Serial.print(" = ");
      decoder();

      //If it exceeds 7 seconds, assumes that the signal is completely finished
      if (endtime - starttime > 7000) {
        Serial.print(' ');
      }
    }
  }

  prevstate = state;
  starttime = endtime;
  }
}
