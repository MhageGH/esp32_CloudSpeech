#include "Audio.h"

Audio::Audio(MicType micType) {
  wavData = new char*[wavDataSize/dividedWavDataSize];
  for (int i = 0; i < wavDataSize/dividedWavDataSize; ++i) wavData[i] = new char[dividedWavDataSize];
  i2s = new I2S(micType);
}

Audio::~Audio() {
  for (int i = 0; i < wavDataSize/dividedWavDataSize; ++i) delete[] wavData[i];
  delete[] wavData;
  delete i2s;
}

void Audio::CreateWavHeader(byte* header, int waveDataSize){
  header[0] = 'R';
  header[1] = 'I';
  header[2] = 'F';
  header[3] = 'F';
  unsigned int fileSizeMinus8 = waveDataSize + 44 - 8;
  header[4] = (byte)(fileSizeMinus8 & 0xFF);
  header[5] = (byte)((fileSizeMinus8 >> 8) & 0xFF);
  header[6] = (byte)((fileSizeMinus8 >> 16) & 0xFF);
  header[7] = (byte)((fileSizeMinus8 >> 24) & 0xFF);
  header[8] = 'W';
  header[9] = 'A';
  header[10] = 'V';
  header[11] = 'E';
  header[12] = 'f';
  header[13] = 'm';
  header[14] = 't';
  header[15] = ' ';
  header[16] = 0x10;  // linear PCM
  header[17] = 0x00;
  header[18] = 0x00;
  header[19] = 0x00;
  header[20] = 0x01;  // linear PCM
  header[21] = 0x00;
  header[22] = 0x01;  // monoral
  header[23] = 0x00;
  header[24] = (byte)(sampleRate & 0xff);  // sampling rate
  header[25] = (byte)((sampleRate >> 8) & 0xff);
  header[26] = (byte)((sampleRate >> 16) & 0xff);
  header[27] = (byte)((sampleRate >> 24) & 0xff);
  header[28] = 0x44;  // Byte/sec = 22050x2x1 = 44100 = 0xAC44 // TODO sampleRateから導くべき
  header[29] = 0xAC;
  header[30] = 0x00;
  header[31] = 0x00;
  header[32] = 0x02;  // 16bit monoral
  header[33] = 0x00;
  header[34] = 0x10;  // 16bit
  header[35] = 0x00;
  header[36] = 'd';
  header[37] = 'a';
  header[38] = 't';
  header[39] = 'a';
  header[40] = (byte)(waveDataSize & 0xFF);
  header[41] = (byte)((waveDataSize >> 8) & 0xFF);
  header[42] = (byte)((waveDataSize >> 16) & 0xFF);
  header[43] = (byte)((waveDataSize >> 24) & 0xFF);
}

void Audio::Record() {
  CreateWavHeader(paddedHeader, wavDataSize);
  int bitBitPerSample = i2s->GetBitPerSample();
  int channelFormat = i2s->GetChannelFormat();
  if (bitBitPerSample == 16) {
    if (channelFormat == I2S_CHANNEL_FMT_RIGHT_LEFT) // 16bitステレオを16bitモノラルに変換して保存する
    {
      for (int j = 0; j < wavDataSize/dividedWavDataSize; ++j) {
        i2s->Read(i2sBuffer, i2sBufferSize / 2);  // i2sBufferの半分だけ使用する
        for (int i = 0; i < i2sBufferSize / 2 / 4; ++i) {
          wavData[j][2*i] = i2sBuffer[4*i + 2]; // iのループでwavDataはi2sBufferのサイズの2/8 = 1/4 だけ使用している。
          wavData[j][2*i + 1] = i2sBuffer[4*i + 3];
        }
      }
    }
    else if (channelFormat == I2S_CHANNEL_FMT_ONLY_RIGHT || channelFormat == I2S_CHANNEL_FMT_ONLY_LEFT)  // 16bitモノラルを16bitモノラルで保存する
    {
      for (int j = 0; j < wavDataSize/dividedWavDataSize; ++j) {
        i2s->Read(i2sBuffer, i2sBufferSize / 4); // i2sBufferの1/4だけ使用する
        for (int i = 0; i < i2sBufferSize/ 4 / 2; ++i) {
          wavData[j][2*i] = i2sBuffer[2*i]; // iのループでwavDataはi2sBufferのサイズの2/8 = 1/4 だけ使用している。
          wavData[j][2*i + 1] = i2sBuffer[2*i + 1];
        }
      }
    }
  }
  else if (bitBitPerSample == 32) {
    if (channelFormat == I2S_CHANNEL_FMT_RIGHT_LEFT) // 32bitステレオを16bitモノラルに変換して保存する
    {
      for (int j = 0; j < wavDataSize/dividedWavDataSize; ++j) {
        i2s->Read(i2sBuffer, i2sBufferSize); // i2sBufferの全部を使用する
        for (int i = 0; i < i2sBufferSize / 8; ++i) {
          wavData[j][2*i] = i2sBuffer[8*i + 2]; // iのループでwavDataはi2sBufferのサイズの2/8 = 1/4 だけ使用している。
          wavData[j][2*i + 1] = i2sBuffer[8*i + 3];
        }
      }
    }
  }
}


