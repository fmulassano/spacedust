#include <Arduino.h>
#include <ht16k33.h> //0x77
#include <U8g2lib.h> //oled display
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Audio.h>
#include <SerialFlash.h>


#include <Leds.h>
#include <Buttons.h>
#include <Encoders.h>
#include <Display.h>
#include <User_functions.h> //user functions 

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=188,240
AudioEffectEnvelope      envelope1;      //xy=371,237
AudioOutputI2S           i2s1;           //xy=565,241
AudioConnection          patchCord1(waveform1, envelope1);
AudioConnection          patchCord2(envelope1, 0, i2s1, 0);
AudioConnection          patchCord3(envelope1, 0, i2s1, 1);
AudioControlSGTL5000     audioShield;     //xy=586,175
// GUItool: end automatically generated code

//timer
elapsedMillis updateUI;
elapsedMillis otto;
elapsedMillis sei;


void setup() {
    //led and buttons
    lb.begin(0x77); //ht16k33 i2c address
    lb.setBrightness(0); //0-15

    //SPI and display
    SPI.setMOSI(28);
    SPI.setSCK(27);
    pinMode(29, OUTPUT);
    pinMode(30, OUTPUT);
    SPI.begin();
    display.begin();

    //Encoder
    enc.begin(5);

    //serial monitor
    Serial.begin(57600);
    Serial.println("via");

    //audio
    AudioMemory(8);
    audioShield.enable();
    audioShield.volume(0.45);
    //
    waveform1.pulseWidth(0.5);
    waveform1.begin(0.4, 220, WAVEFORM_PULSE);

    envelope1.attack(50);
    envelope1.decay(50);
    envelope1.release(250);
}

void loop() {
    if (updateUI > 250) {      // poll every 250ms
      updateUI = 0;
      pollAll();
    }

    // float w;
    // for (uint32_t i =1; i<20; i++) {
    //   w = i / 20.0;
    //   waveform1.pulseWidth(w);
    //   envelope1.noteOn();

      //delay(800);
      //envelope1.noteOff();
      //delay(600);
    //}
  }
