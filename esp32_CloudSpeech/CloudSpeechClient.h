#ifndef _CLOUDSPEECHCLIENT_H
#define _CLOUDSPEECHCLIENT_H
#include <WiFiClientSecure.h>
#include "Audio.h"

class CloudSpeechClient {
  WiFiClientSecure client;
  void PrintHttpBody2(Audio* audio);
  bool useApiKey;

public:
  CloudSpeechClient(bool useApiKey = false);
  ~CloudSpeechClient();
  void Transcribe(Audio* audio);
};

#endif // _CLOUDSPEECHCLIENT_H

