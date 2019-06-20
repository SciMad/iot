#include <SoftwareSerial.h>
#include "src/lib/MHZ19.h"

MHZ19_RESULT mhz19_response;
SoftwareSerial* CO2Serial;//(CO2_TXPIN, CO2_RXPIN);
MHZ19* mhz;

void initCO2Sensor(){
  CO2Serial = new SoftwareSerial(CO2_TX_PIN, CO2_RX_PIN);
  CO2Serial->begin(9600);
  mhz = new MHZ19(CO2Serial);
}

String getCO2Reading(){
    String result;
    float co2, temp;
    double time;
    mhz19_response = mhz->retrieveData();
    if (mhz19_response == MHZ19_RESULT_OK){
        co2 = Serial.println(mhz->getCO2());    
        temp = mhz->getTemperature();
        time = millis();
        result = "{\"CO2\":\"" + String(co2) + "\",\"Temp\":\"" +String(temp) + "\"}";
        //result = "{\"sensor\":\"CO2\",\"time\":\"" + String(millis()) + "\",\"data\":{\"CO2\":\"" + String(co2) + "\",\"Temp\":\"" +String(temp) + "\"}}";
    }
    else{
        result = "{\"error\":\"-1\"}";
    }

    return result;
}
