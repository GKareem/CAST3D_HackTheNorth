#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "qDfsW71_hzRHGnkp3wvb4TWLf2Xq_8GI";

// Your WiFi credentials.
char ssid[] = "YAM";
char pass[] = "bodymidojesi";

#define SwitchZero D0
#define SwitchOne D1

BLYNK_WRITE(V0)
{
  int pinValueZero = param.asInt();
  digitalWrite(SwitchZero,pinValueZero);
}

BLYNK_WRITE(V1)
{
  int pinValueOne = param.asInt();
  digitalWrite(SwitchOne,pinValueOne);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(SwitchZero, OUTPUT);
  digitalWrite(SwitchZero,LOW);

  pinMode(SwitchOne, OUTPUT);
  digitalWrite(SwitchOne,LOW);
  
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
