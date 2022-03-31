#include <OneWire.h>
#include <DallasTemperature.h>
#include <Stepper.h>


// Temperature sensor
#define ONE_WIRE_BUS 5
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius = 0;

// Fish feeder  \ Stepper motor 
#define stepsPerRevolution 2048
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

// Air pump
#define AirRelay 1
bool airPumpIsOn;

// Water In pump
#define WaterInRelay 2
bool waterPumpInIsOn;

void setup() 
{
  myStepper.setSpeed(10);
  digitalWrite(8,LOW);  
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
  sensors.begin();
  
  // Air pump
  digitalWrite(AirRelay,LOW);
  airPumpIsOn = false ;
  
    // Water In pump
  digitalWrite(WaterInRelay,LOW);
  waterPumpInIsOn  = false; 

}

void loop() 
{
  
  getTemperature();
  feedFish();
  oxygenPump();
  waterPumpIn();

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

void oxygenPump() // To Start/Stop air pump
{
  if (!airPumpIsOn)
    {
      digitalWrite(AirRelay,HIGH);
      airPumpIsOn = true;
    }
  else 
    {
      digitalWrite(AirRelay,LOW);
      airPumpIsOn = false; 
    }
}

void waterPumpIn() // To To Start/Stop Water in pump
{
  if (!waterPumpInIsOn)
    {
       digitalWrite(WaterInRelay,HIGH);
       waterPumpInIsOn = true;
    }
  else 
    {
     digitalWrite(WaterInRelay,LOW);
     waterPumpInIsOn = false;
    }
}
