#include "Arduino.h"

#define BLYNK_TEMPLATE_ID           "TMPL6tz_Jy2Dk"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "pLfd5QJA3eCg44k3ALm6J78x7TI-q97x"

#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  digitalWrite(2,pinValue);
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(2,OUTPUT);
}

void loop()
{
  Blynk.run();
}
