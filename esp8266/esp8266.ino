#include <SoftwareSerial.h>
SoftwareSerial esp8266_dev(2, 3);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
  }

  Serial.println("Started");

  // set the data rate for the SoftwareSerial port
  esp8266_dev.begin(9600);
  esp8266_dev.write("AT+CWLAP\r\n");
}

void loop() {
  if (esp8266_dev.available()) {
    Serial.write(esp8266_dev.read());
  }
  if (Serial.available()) {
    esp8266_dev.write(Serial.read());
  }
}
