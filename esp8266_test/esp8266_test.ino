#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
  }

  Serial.println("Started");

  // set the data rate for the SoftwareSerial port
  esp8266.begin(9600);
  esp8266.write("AT+CWLAP\r\n");
}

void loop() {
  if (esp8266.available()) {
    Serial.write(esp8266.read());
  }
  if (Serial.available()) {
    esp8266.write(Serial.read());
  }
}
