#ifndef _AUDIO_H
#define _AUDIO_H

#include <Arduino.h>
#include "I2S.h"

// 16bit, monoral, linear PCM
class Audio {
  I2S* i2s;
  static const int headerSize = 44;
  static const int i2sBufferSize = 6000;
  static const int sampleRate = SAMPLE_RATE;
  char i2sBuffer[i2sBufferSize];
  void CreateWavHeader(byte* header, int waveDataSize);

public:
  static const int wavDataSize = 60000;                   // It must be multiple of dividedWavDataSize.
  static const int dividedWavDataSize = i2sBufferSize/4;
  char** wavData;                                         // It's divided. Because large continuous memory area can't be allocated in esp32.
  byte paddedHeader[headerSize + 4] = {0};                // The size must be multiple of 3 for Base64 encoding. Additional byte size must be even because wave data is 16bit.

  Audio(MicType micType);
  ~Audio();
  void Record();
};

#endif // _AUDIO_H
