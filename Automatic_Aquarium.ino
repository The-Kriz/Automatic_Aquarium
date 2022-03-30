#include <OneWire.h>
#include <DallasTemperature.h>
#include <Stepper.h>


// Temperature sensor
#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius = 0;

// Stepper motor
#define stepsPerRevolution 2048
Stepper myStepper(stepsPerRevolution, 8,9,10,11);


void setup() 
{
  myStepper.setSpeed(10);
  digitalWrite(8,LOW);  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
  sensors.begin();

}

void loop() 
{
  
  getTemperature();
  feedFish();

}

void feedFish()  // To feed fish 
{ //will feed the fish
   myStepper.step(146);
   digitalWrite(8,LOW);   //helps to keep stepper from heating up and to save energy
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);
}

void getTemperature()  // To get tempereature of the aquarium 
{
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Serial.print(" C  ");
  Serial.print(Celcius);
  return Celcius;
}
