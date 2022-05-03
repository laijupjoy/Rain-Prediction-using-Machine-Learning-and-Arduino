#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 2 //digital pin connecte to the DHT sensor
#define DHTTYPE DHT11 //DHT11
#include <LiquidCrystal.h>
#include<Wire.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
DHT dht(DHTPIN, DHTTYPE);
int light=A0;
void setup()
{
 Serial.begin(9600);
 dht.begin();
 delay(10);
 lcd.begin(20,4);
 lcd.setCursor(0,0);
 lcd.print("Integrating");
 lcd.setCursor(0,1);
 lcd.print("Machine learning");
 lcd.setCursor(0,2);
 lcd.print("In Proteus Simulation");
 lcd.setCursor(0,3);
 lcd.print("!!!...");
 delay(2000);
 lcd.clear();
 Serial.println("REBOOT");
}

void loop()
{
 double k=analogRead(A0); //LDR Reading (reading sunlight value)
 double h=dht.readHumidity(); //Read Humidity 
 double t=dht.readTemperature(); //Read Temperature
 if (isnan(h) || isnan(t))
 {
  Serial.println(F("Failed to read from DHT sensor"));
 }
 double ProbabilityRain=0.05*h-2.22*t-0.09*k+191.79; //Probability of Rain Calculation
 lcd.setCursor(0,0);
 lcd.print("The Probability of");
 lcd.setCursor(0,1);
 lcd.print("Raining in % is");
 lcd.setCursor(0,2);
 lcd.print("ProbabilityRain");
}