#include "Audio.h"
#include "CloudSpeechClient.h"

void setup() {
  Serial.begin(115200);
  Serial.println("\r\nRecord start!\r\n");
  delay(500);
  //Audio* audio = new Audio(ICS43434);
  //Audio* audio = new Audio(M5STACKFIRE);
  Audio* audio = new Audio(M5STACKCORE2);
  audio->Record();
  CloudSpeechClient* cloudSpeechClient = new CloudSpeechClient(USE_APIKEY);
  cloudSpeechClient->Transcribe(audio);
  delete cloudSpeechClient;
  delete audio;
}

void loop() {
}
