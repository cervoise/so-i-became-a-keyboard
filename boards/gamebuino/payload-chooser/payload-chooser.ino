#include <Gamebuino-Meta.h>
//From: https://github.com/cervoise/KeyboardWithLayout
#include "KeyboardWithLayout.h"

const char* layouts[] = {
  "EN_ENGLISH keyboard",
  "FR_FRENCH keyboard",
};

const char* payloads[] = {
  "ASCII Table",
  "The quick brown fo...",
  "Open Calc - Windows",
};

int get_layout(uint8_t layout) {
  if (layouts[layout] == layouts[0])
    return EN_ENGLISH;
  if (layouts[layout] == layouts[1])
    return FR_FRENCH;
}

void send_payload(uint8_t payload, int layout) {
  if (payloads[payload] == payloads[0]) {
    KeyboardWithLayout.sendPayload(" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", layout);  
  }
  if (payloads[payload] == payloads[1]) {
    KeyboardWithLayout.sendPayload("The quick brown fox jumps over the lazy dog", layout);  
  }
  if (payloads[payload] == payloads[2]) {
    KeyboardWithLayout.press(KEY_LEFT_GUI, layout);
    KeyboardWithLayout.press('r', layout);
    delay(200);
    KeyboardWithLayout.releaseAll();
    delay(350);
    KeyboardWithLayout.sendPayload("calc", layout);
    delay(200);
    KeyboardWithLayout.press(KEY_RETURN, layout);
    KeyboardWithLayout.releaseAll();
  }
}

void setup() {
  gb.begin();
  KeyboardWithLayout.begin();
}

void loop() {

  uint8_t user_input = gb.gui.menu("Choose your layout", layouts);
  int layout = get_layout(user_input);
  gb.display.clear();

  user_input = gb.gui.menu("Choose your payload", payloads);
  send_payload(user_input, layout);
  
  gb.gui.popup("Payload sent!", 120);

}
