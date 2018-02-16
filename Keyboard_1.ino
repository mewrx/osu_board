#include "DigiKeyboard.h"

typedef struct {
  byte Pin;
  byte Key;
  boolean Press;
} BUTTON;

void ButtonRead(BUTTON* Btn){
  int State = digitalRead(Btn->Pin);
  if(State==HIGH&&State!=Btn->Press){
    Btn->Press = State;
    DigiKeyboard.sendKeyPress(0);
  }
  else if(State==LOW&&State!=Btn->Press){
    Btn->Press = State;
    DigiKeyboard.sendKeyPress(Btn->Key);
  }
}

BUTTON Btn1 = {2,KEY_Z,false};
BUTTON Btn2 = {0,KEY_X,false};

void setup() {
  pinMode(0,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  DigiKeyboard.sendKeyStroke(0);
}

void loop() {
  ButtonRead(&Btn1);
  ButtonRead(&Btn2);
  DigiKeyboard.delay(10);
}
