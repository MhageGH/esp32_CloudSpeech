# esp32_CloudSpeech
Let's try voice recognition by machine learning!<br>
Transcribe your voice by Google's Cloud Speech-to-Text API with esp32<br>
 ![photo1](doc/photo1.jpg)
 ![Transcribe](doc/Transcribe.png)
 
## Prepare
- [ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview)  : espressif
- Microphone [ICS43434](https://www.tindie.com/products/onehorse/ics43434-i2s-digital-microphone/) : tindie, 
or [AE-ADMP441_K](http://akizukidenshi.com/catalog/g/gK-06864/) : Akizuki Denshi, or similar product

## Wiring
 ![Wiring](doc/Wiring.png)

## Development Environment
- [Arduino IDE](https://www.arduino.cc/en/main/software)
- [arduino-esp32](https://github.com/espressif/arduino-esp32)

## How to use
See https://cloud.google.com/speech-to-text/docs/reference/rest/?hl=ja<br>
Set network parameter in network_param.h.<br>
Say to the microphone and see serial monitor.
