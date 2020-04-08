#include <SevSeg.h>
#include <Keypad.h>
SevSeg sevseg;

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
    {'F','E','D','C'},
    {'B','3','6','9'},
    {'A','2','5','8'},
    {'0','1','4','7'}
    };
byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {8,9,10,11};
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
void setup() {
    byte numDigits=1;
    byte digitPins[]={7};
    byte segmentPins[]={6,12,13,14,15,16,17};
    sevseg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
    Serial.begin(9600);
    
}

void loop() {
  char key=keypad.getKey();
  if(key!=NO_KEY)
  {
    Serial.println(key);  
  }
  if(key>='0'&&key<='9')
  {
    sevseg.setNumber(key-'0',0);
  }

  sevseg.refreshDisplay();
}
