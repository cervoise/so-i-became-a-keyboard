# They told me I could be anything I wanted, so I became a keyboard

This repository contains my work about keyboard emulation, mostly for offensive security. There is also links to other projects.

## Why being a keyboard

Because you can!

This can be used to:

- inject payload on an unlock computer,
- cheat on video games,
- "paste" a string into a Citrix/CyberArk/etc. where you cannot paste from the host.

## Main issues

Main issues are:

- the lack of feedback (even if there is some way to have feedback).
- keyboard layout used by the target.
- the speed used. 

### About keyboard layout

When you want to inject a key you have to send its position on the keyboard. This will be different on a QWERTY and AZERTY keyboard. Keyboard for Apple is different than a "normal" keyboard.

### The speed

Your payload may work on your test computer but failed because your target is slower. For example, for creating a payload on windows:
- Windows+R
- type notepad
- Press enter
- Type you payload
- Save it
- Run it

If the computer is to slow to open Notepad between the time you press enter et the time you start to write your payload, you'll have a corrupted payload and this will not work.

## Hardware


### Arduinos
Some Arduino can emulates keyboard. Available boards are

- Arduino Leonardo - https://www.arduino.cc/en/Main/Arduino_BoardLeonardo
- Arduino ETH (retired) - https://store.arduino.cc/arduino-leonardo-eth
- Arduino Micro - https://store.arduino.cc/arduino-micro
- Arduino Yùn - https://www.arduino.cc/en/Guide/ArduinoYun

Using these libs:

- Arduino Keyboard lib: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
- Alternative Lib (allowing to change layout on the fly): https://github.com/cervoise/KeyboardWithLayout

### Teensy

Teensy are able to switch the keyboard layout, can be more thant a keyboard and a mouse (SD Storage, Internal disk, MTP device...).

- Teensy (https://www.pjrc.com/teensy/) 

Using these libs:

- C lib for Teensy 2: https://www.pjrc.com/teensy/usb_keyboard.html
- Arduino lib: https://www.pjrc.com/teensy/td_keyboard.html


### Arduino likes

Some Arduino likes are available, with the Arduino Keyboard lib or other libs.

- Digispark Kickstarter USB Development Board 
   - Project: https://www.gearbest.com/other-accessories/pp_227676.html?lkid=15666791
   - Being a keyboard: https://hackernoon.com/low-cost-usb-rubber-ducky-pen-test-tool-for-3-using-digispark-and-duck2spark-5d59afc1910).
- Adafruit Pro Trinket
   - Project: https://learn.adafruit.com/pro-trinket-keyboard/overview
   - Lib: https://learn.adafruit.com/pro-trinket-keyboard/library
- Adafruit IRKey (discontinued): https://www.adafruit.com/product/1560
- Adafruit pIRkey (coming soon): https://www.adafruit.com/product/3364
- Masterkey - USB WiFi Keylogger: https://github.com/justcallmekoko/USBKeylogger (a Wi-Fi keylogger based on Arduino with keystroke injection capabilities)

### Fruit Pi

Raspberry Pi Zero (https://www.raspberrypi.org/products/raspberry-pi-zero/ & https://www.raspberrypi.org/products/raspberry-pi-zero-w/) or equivalent (like some Orange Pi (http://www.orangepi.org/))

### Other projects

At last, some devices are available in a fake USB Stick branding like Ruber Duckey (https://shop.hak5.org/products/usb-rubber-ducky-deluxe) and WHID (https://github.com/whid-injector/WHID). As thoose are well known, alternatives to them exist as the Tinyduck (https://www.tindie.com/products/justcallmekoko/tinyduck-usb-rubber-ducky/)

There is also a way to turn your old Ubertooth into a BLE Keyboard: https://blog.ice9.us/2018/12/uberducky-ble-wireless-usb-rubber-ducky.html.

## Payloads
- Teensy: https://github.com/samratashok/Kautilya 
- USB-Rubber-Ducky: 
   - https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payloads
   - https://ducktoolkit.com/
- Linux Magic Keys: https://en.wikipedia.org/wiki/Magic_SysRq_key (default one are listed here (in French): https://doc.ubuntu-fr.org/touches_magiques)

## Converter
- Convert Rubber Ducky to Arduino: https://github.com/whid-injector/Dckuino.js 
- Convert Rubber Ducky to DigiSpark: https://github.com/toxydose/Duckyspark
## Why Arduinos and related are more efficient

Arduinos are not only keyboards. First, they can be programed. The main usage is to be able to detect when the user press on CAPS LOCK. The scenario is easy, the attacker plug the Arduino/Teensy on the lock computer, press CAPS LOCK. When the user come back in order to unlock is computer, he will CAPS unlock. The Arduino/Teensy just need to waits few seconds before to launch the payload.

Another advantage is being able to be a keyboard and another device (USB Stick for example). See https://github.com/offensive-security/hid-backdoor-peensy or https://github.com/cervoise/so-i-became-a-keyboard/tree/master/payloads/make-autorun-great-again.

## Protection

Hiding fake HID device into a normal USB device is a way to attack. Detection of compromising can be done be monitoring power consumption of your device. Indeed, adding this kind of component to an existing device will increase power consumption.

Note that if you're using a wireless device, hiding a Teensy or equivalent into you device will be pretty hard. On the other hand, you shall trust the wireless communication: http://travisgoodspeed.blogspot.com/2011/02/promiscuity-is-nrf24l01s-duty.html

It is possible to filter USB for specific ID (MISC n°50 - Juillet/Août 2010 - Créer un pare-feu pour contrôler l'accès aux clés USB (FR)), this can be bypass if one valid ID is known by the attacker (https://forum.pjrc.com/threads/23523-Change-device-name).

## How to hide

I have done presentation about this at BeeRump 2016 and PassTheSalt 2018. See links below. Other works were done:
 - https://www.davidsopas.com/make-hid-great-again/

[IDEA] You can also use device that are Arduino base and changed the code. This can be done with a GameBuino (https://gamebuino.com/).

## Talks

### Mine

- RMLL/LSM 2015 - Beauvais - Open hardware for ”physical” password attacks - https://2015.rmll.info/materiel-libre-pour-attaques-physiques-sur-des-mots-de-passe?lang=en (Slides and Video)
- (FR) GreHack 2015 Rump - Grenoble - (Open) Hardware for "physical" password attacks
- (FR) StHack 2016 - Bordeaux - (Open) Hardware for "physical" password attacks
- (FR) BeeRump 2016 - Paris - - https://www.rump.beer/2016/slides/Teensy_-_Introduire_une_porte_derobe_dans_un_peripherique_USB.pdf (Slides)
- (FR) SSTIC 2016 - Rennes - Déverrouillage d'Android en simulant un clavier/souris - https://www.sstic.org/2016/presentation/unlock_android/ (Slides, paper, video)
- RMLLSec 2016 Rump - Paris -  Arduin-no pown Android - https://sec2016.rmll.info/files/20160705-09-rump-1-Cervoise-Arduino-and-Android.pdf (slides) - https://rmll.ubicast.tv/videos/rump-session_/ (video)
- PassTheSlat 2018 - Lille - Open Hardware for (software) offensive security - https://2018.pass-the-salt.org/files/talks/27-open-hw-for-offensive-security.pdf (slides) - https://passthesalt.ubicast.tv/videos/open-hardware-for-software-offensive-security/ (video)

### Others
 - https://adsecurity.org/?p=362
 
## Projects of mine

- (FR) Cheat on Facebook game: https://github.com/cervoise/blog/blob/master/game/cheat-facebook-games.md
- Hardware-Bruteforce-Project/Hardware-Bruteforce-Framework-2 : https://github.com/cervoise/Hardware-Bruteforce-Project & https://github.com/cervoise/Hardware-Bruteforce-Framework-2
- Bypass CIRCLean (fixed on 30 Oct 2015): https://github.com/cervoise/so-i-became-a-keyboard/blob/master/payloads/CIRCLean-bypass.ino
- Make autorun great again: https://github.com/cervoise/so-i-became-a-keyboard/tree/master/payloads/make-autorun-great-again

## Other Projects

- Hardware protection against HID injection: https://www.sstic.org/2013/presentation/Attaques_applicatives_via_peripheriques_USB_modifies_infection_virale_et_fuites_d_informations/
- Add feedback to Teensy: https://github.com/offensive-security/hid-backdoor-peensy
- Raspberry Pi Zero Framework: https://dantheiotman.com/2017/09/15/p4wnp1-the-pi-zero-based-usb-attack-platform/ 

## IDEA

- Change GameBuino sketch in order to be able to inject keyboard while charging.
- Use Tempest in order to get some feedback of the injections.
