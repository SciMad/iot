#include "src/lib/SHT3x.h"


SHT3x SHTSensor; //A4 and A5

void initTempHumidSensor(){
    SHTSensor.Begin();
}


String getTempHumidReading(){
    String result;
    float temp, humidity;
    SHTSensor.UpdateData();
    temp = SHTSensor.GetTemperature();
    humidity = SHTSensor.GetRelHumidity();
    result = "{\"Temp\":\"" + String(temp) + "\",\"Humidity\":\"" +String(humidity) + "\"}";
    //result = "{\"sensor\":\"Temp_Humid\",\"time\":\"" + String(millis()) + "\",\"data\":{\"Temp\":\"" + String(temp) + "\",\"Humidity\":\"" +String(humidity) + "\"}}";
    return result;
    
}
