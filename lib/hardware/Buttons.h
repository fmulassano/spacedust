// buttons

int BTN_A = 1;
int BTN_B = 14;
int BTN_C = 27;
int BTN_D = 2;
int BTN_SHIFT = 3;
int BTN_UP = 15;
int BTN_DOWN = 28;

//encoder buttons

int BTN_E_A = 4;
int BTN_E_B = 17;
int BTN_E_C = 30;
int BTN_E_D = 5;
int BTN_E_E = 18;

int readButton(){
  static uint8_t lastKey=0;
  int8_t key;
  //Serial.println("loop");

  key=lb.readKey();
    //if (key != 0) { // key is pressed
     if (key != lastKey){
        Serial.print(F("Key pressed: "));
        Serial.println(key);
        lastKey=key;
      }
    //}

    return key;
}
