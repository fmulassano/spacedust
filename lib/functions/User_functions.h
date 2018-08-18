
void intro(){
  for(int i=0; i<9; i++){
    litLed(i, "R");
    delay(100);
    clearLed(i);
  }
  for(int i=8; i>=0; i--){
    litLed(i, "R");
    delay(100);
    clearLed(i);
  }
  lb.clearAll();

  for(int i=0; i<9; i++){
    litLed(i, "R");
    delay(100);
    clearLed(i);
  }
  for(int i=8; i>=0; i--){
    litLed(i, "R");
    delay(100);
    clearLed(i);
  }
  lb.clearAll();

  for(int i=0; i<9; i++){
    litLed(i, "R");
    delay(100);
    clearLed(i);
  }
  lb.clearAll();

  for(int i=8; i>=0; i--){
    litLed(i, "W");
    delay(100);
    clearLed(i);
  }
  lb.clearAll();
}

int readEncoder(){

}
