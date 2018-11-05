//Original code from: https://gamebuino.com/creations/hello-world

#include <Gamebuino-Meta.h>
#include "Keyboard.h"

void setup() {
  gb.begin();
  Keyboard.begin();
}

void loop() {
  while(!gb.update());
  gb.display.clear();
  Keyboard.print("You can send a payload!");

  // This is where most of the program takes place
  gb.display.print("hello, world");
}
