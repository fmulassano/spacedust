//oled display (remember to activate the 16bit mode)

// Q: How to activate 16 Bit mode?
// A: Search for the line
// //#define U8G2_16BIT
// in "u8g2.h". Uncomment this line:
// #define U8G2_16BIT
// The file "u8g2.h" is located in "/libraries/U8g2_Arduino/src/clib" inside your default
// sketch folder.

U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI display(U8G2_R2, /* cs=*/ 24, /* dc=*/ 29, /* reset=*/ 25);  // Enable U8G2_16BIT in u8g2.h

// functions
void helloWorld(){
  display.firstPage();
    do {
      display.setFont(u8g2_font_ncenB14_tr);
      display.drawStr(0,15,"SPACEDUST");
      display.setCursor(20, 30);
      display.print("hello");
      display.setCursor(50, 50);
        int wi = display.getDisplayWidth();
        display.print(wi);
    } while ( display.nextPage() );
}

void vline(){
  for(int i=0; i<254; i++){
        display.clearBuffer();
        display.drawVLine(i, 0, 63);
        display.sendBuffer();
  }
}

void drawWave(){

}
