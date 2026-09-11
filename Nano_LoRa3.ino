#include <SoftwareSerial.h>

SoftwareSerial LoRa(2, 3);   // D2 = RX, D3 = TX

void setup() {
  Serial.begin(9600);
  LoRa.begin(9600);

  Serial.println("LORA 3 - TRANSMITTER READY");
}

void loop() {
  LoRa.println("HI FRM LORA 3");

  Serial.println("SENT: HI FRM LORA 3");

  delay(2000);
}
