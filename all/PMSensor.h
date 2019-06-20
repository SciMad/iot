#include <SdsDustSensor.h>

SdsDustSensor sds(PM_RX_PIN, PM_TX_PIN);

void initPMSensor(){
  //Nova
  sds.begin();
  // Serial.println(sds.queryFirmwareVersion().toString()); // prints firmware version
  // Serial.println(sds.setActiveReportingMode().toString()); // ensures sensor is in 'active' reporting mode
  // Serial.println(sds.setContinuousWorkingPeriod().toString()); // ensures sensor has continuous working period - default but not recommended

}

String getPMReading(){
    String result;
    float pm2_5, pm10;
    PmResult pm = sds.readPm();
      if (pm.isOk()) {
        pm2_5 = pm.pm25;
        pm10 = pm.pm10;
        //result = "{\"sensor\":\"PM\",\"time\":\"" + String(millis()) + "\",\"data\":{\"PM2.5\":\"" + String(pm2_5) + "\",\"PM10\":\"" +String(pm10) + "\"}}";
        result = "{\"PM2.5\":\"" + String(pm2_5) + "\",\"PM10\":\"" +String(pm10) + "\"}";
      } else {
        result = result = "{\"error\":\"-1\"}";
      }

    return result;
}
