//Test file for the AM2302 DHT22 Sensor for the Arduino Uno, gathers Temperature and Humidity
//inspired by P. Marian
//https://www.electroschematics.com/11291/arduino-dht22-am2302-tutorial-library/

/**
 * Hardware used for this project:
 * 1 Working Arduino Uno
 * 3 Jumper cables
 * 1 AM2302 DHT22 Sensor
 * 1 Breadboard
 * 1 USB a cable
 */

//Daniel Lay      5/14/2018

//imports the library that must be used to run this program
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define TIMEBETWEEN 2000


//initializes the part so that the program knows what to expect to run
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  //initialize serial port (allows for commuication with arduino by clicking on the magnifying glass
  //on the top right corner of the window AFTER the program is uploaded
  Serial.begin(9600);
  Serial.println("AM2302 Testing.");

  //starts the loop
  dht.begin();
}

void loop() {
  delay(TIMEBETWEEN);

//collects information of the current Humidity and Temperture
  float humidity = dht.readHumidity();
  float temperatureCelsius = dht.readTemperature();
  float temperatureFahrenheit = dht.readTemperature(true);

  //checks if any data is gathered (if part is working); exits if data not found.
  if(isnan(humidity)||isnan(temperatureCelsius)||isnan(temperatureFahrenheit)){
    Serial.println("Failed to read from Sensor");
    return;
  }

//Should display both the humidity and the temperature of the environment.
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.print(" *C  ");
  Serial.print(temperatureFahrenheit);
  Serial.println(" *F ");
}
