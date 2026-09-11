#include <HardwareSerial.h>

HardwareSerial LoRa(2);

#define LORA_RX 16
#define LORA_TX 17

void setup() {
  Serial.begin(115200);
  LoRa.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

  Serial.println("LORA 1 READY");
}

void loop() {
  LoRa.println("HELLO FRM LORA 1");

  Serial.println("SENT: HELLO FRM LORA 1");

  delay(2000);
}
