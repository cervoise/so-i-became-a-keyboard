void setup() {
  delay(3000);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(10);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(150);
  Keyboard.println("D:\\test");
  delay(150);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void loop() {}
