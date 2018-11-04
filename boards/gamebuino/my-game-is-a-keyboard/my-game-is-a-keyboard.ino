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
  //Affichage du message à l'écran
  gb.display.print("'hello, world'\nest une tradition\ninstauree en\n\n");
  //Texte à l'échelle 2
  gb.display.setFontSize(2);
  gb.display.print("1978");
  //Retour à l'échelle 1 et changement de couleur
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.print("\n\n\n       - GAMEBUINO");
}
