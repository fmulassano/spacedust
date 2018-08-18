#include <RotaryEncOverMCP.h>
//encoder port expander
Adafruit_MCP23017 enc;

/* function prototypes */
void RotaryEncoderChanged(bool clockwise, int id);
Adafruit_MCP23017* allMCPs[] = { &enc };

/* Array of all rotary encoders and their pins */
RotaryEncOverMCP rotaryEncoders[] = {
  RotaryEncOverMCP(&enc, 9, 8, &RotaryEncoderChanged, 1),
  RotaryEncOverMCP(&enc, 11, 10, &RotaryEncoderChanged, 2),
  RotaryEncOverMCP(&enc, 13, 12, &RotaryEncoderChanged, 3),
  RotaryEncOverMCP(&enc, 15, 14, &RotaryEncoderChanged, 4),
  RotaryEncOverMCP(&enc, 1, 0, &RotaryEncoderChanged, 5)
};

void RotaryEncoderChanged(bool clockwise, int id) {
  Serial.println("Encoder " + String(id) + ": "
    + (clockwise ? String("clockwise") : String("counter-clock-wise")));
}

void pollAll() {
  uint16_t gpioAB = allMCPs[0]->readGPIOAB();
    for (int i=0; i < 5; i++) {
      if(rotaryEncoders[i].getMCP() == allMCPs[0])
        rotaryEncoders[i].feedInput(gpioAB);
    }
}
