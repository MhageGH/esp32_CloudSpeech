#include "Audio.h"
#include "CloudSpeechClient.h"

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\r\nRecord start!\r\n");
  Audio* audio = new Audio(ICS43434);
//  Audio* audio = new Audio(M5STACKFIRE);
  audio->Record();
  CloudSpeechClient* cloudSpeechClient = new CloudSpeechClient(USE_ACCESSTOKEN);
  cloudSpeechClient->Transcribe(audio);
  delete cloudSpeechClient;
  delete audio;
}

void loop() {
}
