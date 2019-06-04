
#include <SoftwareSerial.h>
#include "MHZ19.h"

#define CO2_TX_PIN 7
#define CO2_RX_PIN 6

MHZ19_RESULT response;
SoftwareSerial* CO2Serial;//(CO2_TXPIN, CO2_RXPIN);
MHZ19* mhz;

void setup() {
Serial.begin(9600);
delay(1000);
Serial.println("Serial Begin Started");
}

void loop() {
  CO2Serial = new SoftwareSerial(CO2_TX_PIN, CO2_RX_PIN);
  CO2Serial->begin(9600);
  mhz = new MHZ19(CO2Serial);  
  while (1){
    delay(2000);
      response = mhz->retrieveData();
      if (response == MHZ19_RESULT_OK){
        Serial.println("CO2 sensor working");
        Serial.println(mhz->getCO2());
        Serial.println("Reading Tempr. From MHZ19");
        Serial.println(mhz->getTemperature());
      }
      else{
        Serial.println("Error Code -1");
      }
  }

}
