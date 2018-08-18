//leds and buttons expander
HT16K33 lb;

// red

int LRA = 0;
int LRB = 1;
int LRC = 2;
int LRD = 3;
int LRE = 4;
int LRF = 48;
int LRG = 49;
int LRH = 50;
int LRI = 51;

// green

int LGA = 16;
int LGB = 17;
int LGC = 18;
int LGD = 19;
int LGE = 20;
int LGF = 64;
int LGG = 65;
int LGH = 66;
int LGI = 67;

// blue

int LBA = 32;
int LBB = 33;
int LBC = 34;
int LBD = 35;
int LBE = 36;
int LBF = 80;
int LBG = 81;
int LBH = 82;
int LBI = 83;

int LED[9][3] = {
  {0,16,32},
  {1,17,33},
  {2,18,34},
  {3,19,35},
  {4,20,36},
  {48,64,80},
  {49,65,81},
  {50,66,82},
  {51,67,83}
};

//possible colors, 7: Red, Green, Blue, Yellow (red+green), Purple (red+blue), Ligh Blue (green + blue), White (red + green + blue)
void litLed(int led, String color){
  if(color == "R"){
    lb.setLedNow(LED[led][0]);
  }else if(color == "G"){
    lb.setLedNow(LED[led][1]);
  }else if(color == "B"){
    lb.setLedNow(LED[led][2]);
  }else if(color == "Y"){
    lb.setLedNow(LED[led][0]);
    lb.setLedNow(LED[led][1]);
  }else if(color == "P"){
    lb.setLedNow(LED[led][0]);
    lb.setLedNow(LED[led][2]);
  }else if(color == "LB"){
    lb.setLedNow(LED[led][1]);
    lb.setLedNow(LED[led][2]);
  }else if(color == "W"){
    lb.setLedNow(LED[led][0]);
    lb.setLedNow(LED[led][1]);
    lb.setLedNow(LED[led][2]);
  }else{
    lb.clearAll();
  }
}

void clearLed(int led){
  lb.clearLedNow(LED[led][0]);
  lb.clearLedNow(LED[led][1]);
  lb.clearLedNow(LED[led][2]);
}
