#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h> 
#define ONE_WIRE_BUS 8

LiquidCrystal lcd = LiquidCrystal(7,6,5,4,3,2); 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

  // Pins 
int trigger = 40;
  
int greenLed = 2;
int redLed = 4;
int fan = 10;
int buzzer = 9;
int temp=0;
int green = 9;
int red = 11;

int thresholdValue = 0;
float celsius = 0;
int fahrenheit = 0;

// Functions
void greenLightOn(){
  digitalWrite(greenLed, HIGH);
}
void greenLightOff(){
  digitalWrite(greenLed, LOW);
}
void redLightOn(){
  digitalWrite(redLed, HIGH);
}
void redLightOff(){
  digitalWrite(redLed, LOW);
}
void fanOn(){
  digitalWrite(fan, HIGH);
}
void fanOff(){
  digitalWrite(fan, LOW);
}
void buzzerOn(){
  digitalWrite(buzzer, HIGH);
}
void buzzerOff(){
  digitalWrite(buzzer, LOW);
}
void greenOn(){
  digitalWrite(green, HIGH);
}
void greenOff(){
  digitalWrite(green, LOW);
}
void redOn(){
  digitalWrite(red, HIGH);
}
void redOff(){
  digitalWrite(red, LOW);
}
void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(temp, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  lcd.begin(16, 2);
  sensors.begin();
}

void loop(){
  
  // Temperature calculation
  sensors.requestTemperatures();
  celsius=sensors.getTempCByIndex(0);
  delay(500);
  
  lcd.setCursor(5, 0);
  lcd.print(celsius);
  
  if(celsius >= trigger){
    fanOn();
    lcd.setCursor(0,1);
    lcd.print("!!Fire Detected!!");
    redOn();
    delay(20);
    redOff();
  }
  else if (celsius <40){
    fanOff();
    lcd.setCursor(0,1);
    lcd.print("Normal temperature");
      greenOn();
      delay(300);
      greenOff();
 
    
    
  }

}
