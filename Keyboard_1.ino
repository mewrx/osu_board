#include "DigiKeyboard.h"

typedef struct
{
  byte Pin;
  byte Key;
  boolean Press;
} BUTTON;
BUTTON Btn1 = {1,KEY_Z,false};
BUTTON Btn2 = {0,KEY_X,false};

void ButtonRead(BUTTON* Btn)
{
  int State = digitalRead(Btn->Pin);
  if(State==HIGH&&State!=Btn->Press){
    Btn->Press = State;
    DigiKeyboard.sendKeyPress(Btn->Key);
  }
  else if(State==LOW&&State!=Btn->Press){
    Btn->Press = State;
    DigiKeyboard.sendKeyPress(0);
  }
}

void setup()
{
  pinMode(0,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);
  DigiKeyboard.sendKeyStroke(0);
}

void loop()
{
  DigiKeyboard.delay(20);
  ButtonRead(&Btn1);
  ButtonRead(&Btn2);
}
