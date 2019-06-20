#define CO2_TX_PIN 7
#define CO2_RX_PIN 6
#include "CO2Sensor.h"

#define PM_RX_PIN 10
#define PM_TX_PIN 11
#include "PMSensor.h"

#include "TempHumidSensor.h"

//TODO: The following sensors are creating some sort of error when all of those are kept together
//Use EEPROM and reset functionality of Arduino to only initate one sensor at one instance and send it to the NodeMCU
//and then alternatively switch the sensors with every soft-reset

//#include "EEPROMAnything.h"

//SensorRecord rec;
//int readSuccess = EEPROM_readAnything (0, rec);
//int writeSuccess = EEPROM_writeAnything (0, rec);
//int sensorID = rec.sensorID;
int sensorID = 0;
int sendJSONToHTTP(){
  
}


void setup() {

  Serial.begin(9600);
  while(!Serial);
//  Serial.println("Reading EEPROM");
//  Serial.println(sensorID);
  delay(1000);
  switch (sensorID){
    case 0:
      Serial.println("Trying to initiate TempHumid sensor");
      initTempHumidSensor();
      break;

    case 1:
      Serial.println("Trying to initiate PM sensor");
      initPMSensor();
      break;
      
    case 2:
      Serial.println("Trying to initiate CO2 sensor");
      initCO2Sensor();
      break;

    default:
      break;
  }
 
  

}


void loop() {
  String jsonString = "No data available";
    switch (sensorID){
      case 0:
        Serial.println("Reading TempHumid sensor:");
        Serial.println("I am here");
        jsonString = getTempHumidReading();
        break;
  
  
      case 1:
        Serial.println("Reading PM sensor:");
        jsonString = getPMReading();
        break;
  
      case 2:
        Serial.println("Reading CO2 sensor:");
        jsonString = getCO2Reading();
        break;
  
      default:
        break;
  }
  
  Serial.println(jsonString.c_str());
  Serial.println("Sending over wifi");
  
  //rec.updateSensor();
  //int writeSuccess = EEPROM_writeAnything (0, rec);
  delay(2000);
  
}
