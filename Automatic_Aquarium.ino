#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5
float Celcius = 0;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);




void setup() 
{
   
  Serial.begin(9600);
  sensors.begin();

}

void loop() 
{
  
  getTemperature();

}

void getTemperature()
{
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Serial.print(" C  ");
  Serial.print(Celcius);
  return Celcius;
}
