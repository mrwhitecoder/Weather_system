#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2                // Sesnor Pin!
#define DHTTYPE DHT11          // define the type of sensor used!

DHT dht(DHTPIN, DHTTYPE);     // Initialize DHT sensor.
                                     
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti




byte degreec[] =
 { 
  B11000,
  B11000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00011,
  B00000
 };

void setup() 
{
 pinMode(3,OUTPUT);
 digitalWrite(3,HIGH); 
 lcd.init();
 lcd.backlight();
 lcd.createChar(0, degreec);
 lcd.home();
 dht.begin();
 lcd.setCursor(0,0);
 lcd.print("Mission Critical");
 lcd.setCursor(0,1);
 lcd.print("Weather Station! ");
 delay(600);
 lcd.setCursor(0,0);
 lcd.print("                 ");
  lcd.setCursor(0,1);
 lcd.print("                 ");
 delay(100);
 
}

void loop()
{
 float h = dht.readHumidity();      // Read Humidity 
 float t = dht.readTemperature();   // Read temperature as Celsius
 lcd.setCursor(1,0);
 lcd.print("Temp:");
 lcd.setCursor(6,0);
 lcd.print(t);
 lcd.setCursor(11,0);
 lcd.write(degreec);
 lcd.setCursor(1,1);
 lcd.print("Humd:");
 lcd.setCursor(6,1);
 lcd.print(h);
 lcd.setCursor(11,1);
 lcd.print("%");
 
}
 
