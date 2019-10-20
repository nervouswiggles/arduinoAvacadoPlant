// All the additional libraries
#include <TestLED.h>
#include <WaterMoisture.h>
#include <WeatherDisplay.h>

#include <string.h>
//The additional files not subjected to ordering
#include "Constants.h"

WaterMoisture waterMoisture = WaterMoisture(moistureSensorPin);   
WeatherDisplay weatherDisplay = WeatherDisplay(30);
TestLED tes1tLED = TestLED(ledPin);


// -------
// setup()
// -------
void setup() {
  Serial.begin(38400);  
  weatherDisplay.displaySetup(); 
  
  for(int i = 0; i < sensors; i++) //Sets up water levels
    pinMode(waterSensorPin[i], INPUT); 
}


// ------
// loop()
// ------
void loop() {

    //Serial.println("timeSinceSprinkler:"+timeSinceSprinkler);
    // -----------------------
    // Time since the last run
    // -----------------------
    timeCheckMillis = millis() - lastWaterMillis;
    //Serial.println("Start of Lap :"+String(timeCheckMillis));
    //Serial.println("Been running since: "+String(millis()));
    //Serial.println("lastWaterMillis:"+String(lastWaterMillis));
    //Serial.println("Finish Lap:"+String(timeCheckMillis) +" out of "+String(timeBetweenWatering));
    

    if(timeCheckMillis>timeBetweenWatering){
      weatherDisplay.displayValue(88, 8, 88, 8, 50, 8, "OK"); //The waterDrop Logo
    }else{
      //int timeToPresent = timeCheckMillis/1000/60;
      int timeToPresent = (timeBetweenWatering/1000/60) - (timeCheckMillis/1000/60);
      //Serial.println("timeBetweenWatering --->"+String(timeBetweenWatering));
      //Serial.println("--->"+timeBetweenWatering/1000/60);
      //timeCheckMillis/1000/60;
      
      weatherDisplay.displayValue(88, 8, 88, 8, 50, 8, timeToPresent); //The waterDrop Logo
      
    }
    

    // -----------------------------------
    // Calculate Whether it's day or night
    // -----------------------------------
    calcualteDateNight();


    // ------------------------------------
    // Calcuate the number of water sensors
    // ------------------------------------
    int waterLevel = numberOfSensors();
    switch(waterLevel){
      case 0:
      if(previousWaterLevel!=waterLevel)
        weatherDisplay.displayValue(16, 18, 16, 18, 30, 18, "Empty"); //The waterDrop Logo   
        previousWaterLevel=waterLevel;
      break;

      case 1:
      if(previousWaterLevel!=waterLevel)
        weatherDisplay.displayValue(16, 18, 16, 18, 30, 18, "Low"); //The waterDrop Logo
        previousWaterLevel=waterLevel;
      break;

      case 2:
      if(previousWaterLevel!=waterLevel)
        weatherDisplay.displayValue(16, 18, 16, 18, 30, 18, "OK"); //The waterDrop Logo
        previousWaterLevel=waterLevel;
      break;

      case 3:
      if(previousWaterLevel!=waterLevel)
      weatherDisplay.displayValue(16, 18, 16, 18, 30, 18, "Good"); //The waterDrop Logo
      previousWaterLevel=waterLevel;
      break;
    }
    
    
    // -----------------------------------------
    // If the water level is good
    // and if the moistureThreshold is low
    // And it's been a while since the last time
    // -----------------------------------------
    if(waterLevel>0 && timeOfDay ==1 && moistureThreshold<waterMoisture.getMoistureValue() && timeCheckMillis>timeBetweenWatering){
      turnOnWater();
    }

    // -----------------------
    // Get the moisture sensor
    // -----------------------
    //Serial.println("M --> "+String(waterMoisture.getMoistureValue()));
    weatherDisplay.displayValue(16, 8, 16, 8, 18, 8, waterMoisture.getMoistureValue()); //The waterDrop Logo
    delay(250);
    tes1tLED.turnOnOffLED();
}


  // -------------------------------------
  // numberOfSensors()
  // Determine the number of water Sensors
  // -------------------------------------
  int numberOfSensors(){
    int waterLevel = 0;
    for(int i = 0; i < sensors; i++) {
        //Serial.println("Light Sensor: "+digitalRead(waterSensorPin[i]));
        if(digitalRead(waterSensorPin[i])==HIGH){
          waterLevel++;  
        }
    }
    return waterLevel;  
  }


  // --------------------
  // calcualteDateNight()
  // --------------------
  void calcualteDateNight(){    
    Serial.println("Light Sensor 1 -->"+String(analogRead(lightSensorPin)));
    Serial.println("-->"+String(lightSensorThreshold));
    // Night to Day
    //if(analogRead(lightSensorPin)>50 && timeOfDay==0){
    if(analogRead(lightSensorPin)>lightSensorThreshold){
      //weatherDisplay.displayValue(58, 18, 58, 18, 58, 18, "DayTime"); //The waterDrop Logo
      weatherDisplay.displayValue(88, 18, 88, 18, 88, 18, "Day"); //The waterDrop Logo
      timeOfDay=1;

    //Day turns to night
    //}else if(analogRead(lightSensorPin)<lightSensorThreshold && timeOfDay==1){
    }else if(analogRead(lightSensorPin)<lightSensorThreshold){
    //}else if(analogRead(lightSensorPin)<50 && timeOfDay==1){  
      //weatherDisplay.displayValue(58, 18, 58, 18, 58, 18, "Zzz Zzz"); //The waterDrop Logo
      weatherDisplay.displayValue(88, 18, 88, 18, 88, 18, "Zzz"); //The waterDrop Logo
      timeOfDay=0;
    }
}

  // -------------
  // turnOnWater()
  // -------------
  void turnOnWater(){
      //const int RELAY_PIN = 7; //Relay to start the water flow
      
      weatherDisplay.displayValue(88, 8, 88, 8, 50, 8, "Wait..."); //The waterDrop Logo
      lastWaterMillis=millis();
      pinMode(RELAY_PIN,HIGH);    
      //delay(500);
      delay(waterPumpDuration);
      pinMode(RELAY_PIN,LOW);
          
  }
