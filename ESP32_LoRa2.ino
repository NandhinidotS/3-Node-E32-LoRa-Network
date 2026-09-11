#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HardwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
HardwareSerial LoRa(2);

#define LORA_RX 16
#define LORA_TX 17

void setup() {
  Serial.begin(115200);
  LoRa.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LORA 2 READY");
  lcd.setCursor(0, 1);
  lcd.print("WAITING DATA");

  delay(2000);
}

void loop() {
  if (LoRa.available()) {
    String data = LoRa.readStringUntil('\n');
    data.trim();

    Serial.print("RECEIVED: ");
    Serial.println(data);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RECEIVED:");
    lcd.setCursor(0, 1);

    if (data.length() > 16) {
      data = data.substring(0, 16);
    }

    lcd.print(data);
  }
}
