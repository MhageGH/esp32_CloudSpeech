#ifndef _I2S_H
#define _I2S_H

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"
#include "esp_system.h"

#define PIN_I2S_BCLK 26
#define PIN_I2S_LRC 22
#define PIN_I2S_DIN 34
#define PIN_I2S_DOUT 25
#define SAMPLE_RATE 22050

// M5Stack Core2
#define CONFIG_I2S_LRCK_PIN 0 // I2Sクロック
#define CONFIG_I2S_DATA_IN_PIN 34 // I2Sデータ
#define CHUNK 1024 // I2Sバッファサイズ

enum MicType {
  ADMP441,
  ICS43434,
  M5GO,
  M5STACKFIRE,
  M5STACKCORE2,
};

class I2S {
  i2s_bits_per_sample_t BITS_PER_SAMPLE;
  i2s_channel_fmt_t CHANNEL_FORMAT;
public:
  I2S(MicType micType);
  int Read(char* data, int numData);
  int GetBitPerSample();
  int GetChannelFormat();
};

#endif // _I2S_H
