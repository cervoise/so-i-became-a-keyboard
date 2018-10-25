# They told me I could be anything I wanted, so I became a keyboard

This repository contains my work about keyboard emulation, mostly for offensive security. There is also links to other projects.

## Why being a keyboard

Because you can!

This can be used to inject payload on an unlock computer or to cheat on some video game.

## Hardware

Some Arduino can emulates keyboard:
- Arduino Leonardo - https://www.arduino.cc/en/Main/Arduino_BoardLeonardo
- Arduino Micro - https://store.arduino.cc/arduino-micro
- Arduino Yùn - https://www.arduino.cc/en/Guide/ArduinoYun

Note that a version of the Arduino Leonardo exists with a Ethernet plug but the product is retired: https://store.arduino.cc/arduino-leonardo-eth.

Alternatives to Arduino are able to switch the keyboard layout exists: Teensy () or Raspberry Pi Zero (https://www.raspberrypi.org/products/raspberry-pi-zero/ & https://www.raspberrypi.org/products/raspberry-pi-zero-w/) or equivalent (like some Orange Pi (http://www.orangepi.org/)).

At last, some devices are available in a fake USB Stick branding like Ruber Duckey (https://shop.hak5.org/products/usb-rubber-ducky-deluxe) and WHID (https://github.com/whid-injector/WHID).

## Why Arduinos and related are more efficient

Arduinos are not only keyboards. First, they can be programed. The main usage is to be able to detect when the user press on CAPS LOCK. The scenario is easy, the attacker plug the Arduino/Teensy on the lock computer, press CAPS LOCK. When the user come back in order to unlock is computer, he will CAPS unlock. The Arduino/Teensy just need to waits few seconds before to launch the payload.

Another advantage is being able to be a keyboard and another device (USB Stick for example). See https://github.com/offensive-security/hid-backdoor-peensy or https://github.com/cervoise/so-i-became-a-keyboard/tree/master/payloads/make-autorun-great-again.

## Protection

Hiding fake HID device into a normal USB device is a way to attack. Detection of compromising can be done be monitoring power consumption of your device. Indeed, adding this kind of component to an existing device will increase power consumption.

Note that if you're using a wireless device, hiding a Teensy or equivalent into you device will be pretty hard. On the other hand, you shall trust the wireless communication: http://travisgoodspeed.blogspot.com/2011/02/promiscuity-is-nrf24l01s-duty.html

## How to hide

I have done presentation about this at BeeRump 2016 and PassTheSalt 2018. See links below.

You can also use device that are Arduino base and changed the code. This can be done with a GameBuino (https://gamebuino.com/).

## Presentations

RMLL/LSM 2015 - Beauvais - Open hardware for ”physical” password attacks - https://2015.rmll.info/materiel-libre-pour-attaques-physiques-sur-des-mots-de-passe?lang=en (Slides and Video)
(FR) GreHack 2015 Rump - Grenoble - (Open) Hardware for "physical" password attacks
(FR) StHack 2016 - Bordeaux - (Open) Hardware for "physical" password attacks
(FR) BeeRump 2016 - Paris - - https://www.rump.beer/2016/slides/Teensy_-_Introduire_une_porte_derobe_dans_un_peripherique_USB.pdf (Slides)
(FR) SSTIC 2016 - Rennes - Déverrouillage d'Android en simulant un clavier/souris - https://www.sstic.org/2016/presentation/unlock_android/ (Slides, paper, video)
RMLLSec 2016 Rump - Paris -  Arduin-no pown Android - https://sec2016.rmll.info/files/20160705-09-rump-1-Cervoise-Arduino-and-Android.pdf (slides) - https://rmll.ubicast.tv/videos/rump-session_/ (video)

## Projects of mine

(FR) Cheat on Facebook game: https://github.com/cervoise/blog/blob/master/game/cheat-facebook-games.md
Bypass CIRCLean (fixed on 30 Oct 2015): https://github.com/cervoise/so-i-became-a-keyboard/blob/master/payloads/CIRCLean-bypass.ino
Make autorun great again: https://github.com/cervoise/so-i-became-a-keyboard/tree/master/payloads/make-autorun-great-again

## Other Projects

Teensy scripts: https://github.com/samratashok/Kautilya 
Add feedback to Teensy: https://github.com/offensive-security/hid-backdoor-peensy
Convert Rubber Ducky to Arduino: https://github.com/whid-injector/Dckuino.js 
Raspberry Pi Zero Framework: https://dantheiotman.com/2017/09/15/p4wnp1-the-pi-zero-based-usb-attack-platform/ 
