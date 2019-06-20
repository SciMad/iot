#include <EEPROM.h>
#include <Arduino.h>  // for type definitions

void clearEEPROM(){
  for (int i=0; i<EEPROM.length(); ++i){
    EEPROM.write(i,0);
  }
}

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}

class SensorRecord{
  public:
  int sensorID;
  SensorRecord(){
  };
  ~SensorRecord(){
  };
  int updateSensor(){
  this->sensorID += 1;
  if (this->sensorID >= 3)
    this->sensorID = 0;
  };
  String getSensorName(int id){
  
  }
  
};
