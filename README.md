# esp32_CloudSpeech
Let's try voice recognition by machine learning!<br>
Transcribe your voice by Google's Cloud Speech-to-Text API with esp32<br><br> 
In the case of esp32 + microphone<br>
 ![photo1](doc/photo1.jpg)<br><br>
In the case of M5Stack FIRE<br>
 ![M5StackFIRE](doc/M5StackFIRE.jpg)<br><br>
Serial monitor<br>
 ![Transcribe](doc/Transcribe.png)
 
## Prepare
- [ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview)  (espressif)
- Microphone : <br>
 [ICS43434](https://www.tindie.com/products/onehorse/ics43434-i2s-digital-microphone/) (tindie), <br>
 or [AE-ADMP441_K](http://akizukidenshi.com/catalog/g/gK-06864/) (Akizuki Denshi), <br>
 or similar product <br><br>
 Or <br>
- [M5Stack FIRE](https://www.switch-science.com/catalog/3953/) (Switch Science) - This product includes esp32 and microphone.

## Wiring
 ![Wiring](doc/Wiring.png)<br>
 <br>
 *No need wiring if you use M5Stack FIRE.

## Development Environment
- [Arduino IDE](https://www.arduino.cc/en/main/software)
- [arduino-esp32](https://github.com/espressif/arduino-esp32)

## How to use
Get your account in https://cloud.google.com/speech-to-text/ <br>
Set network parameter and your account information in network_param.h.<br>
Say to the microphone and see serial monitor.
