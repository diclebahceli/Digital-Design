#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
float t,h;


int buzzer = 6;
unsigned long myTime;
unsigned long beginningTime=0;
const int rs =13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int buttonPin=7;
const int redLedPin=4;
const int greenLedPin=5;
int redLedState=LOW;
int greenLedState=LOW;
int buttonState;
int lastButtonState= LOW;
unsigned long lastDebounceTime=0;
unsigned long debounceDelay=50;

void setup() {

  
   dht.begin();
   lcd.begin(16,2);
   lcd.print("Dicle Bahceli");
   lcd.setCursor(0,1);
   lcd.print("20190808024");
   
   
   delay(2000);

   
   pinMode(buttonPin,INPUT);
   pinMode(redLedPin,OUTPUT);
   pinMode(greenLedPin,OUTPUT);

   digitalWrite(redLedPin,redLedState);
   digitalWrite(greenLedPin,greenLedState);

   myTime=millis();

}

void loop() {
  
  h=dht.readHumidity();
  t=dht.readTemperature();
  
  
   if(myTime-beginningTime>400){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity ");
    lcd.setCursor(0,1);
    lcd.print(h);
    lcd.print("%");
    myTime=0;
  }


  if(t>30){
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      }else{
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      }


  if(h<30){
    tone(buzzer, 450);
    delay(100);
    noTone(buzzer);
    delay(100);
  }

  
  int reading = digitalRead(buttonPin);



  

    if(reading != lastButtonState){

    lastDebounceTime = millis();
    
  }

  if((millis() - lastDebounceTime)> debounceDelay){
    if(reading != buttonState){
      buttonState = reading;
    
    

    if(buttonState==HIGH ){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Temperature ");
      lcd.setCursor(0,1);
      lcd.print(t);
      lcd.print(" C");
      
    }


    else{
      lcd.clear();
      lcd.setCursor(0,0);
        lcd.print("Humidity ");
        lcd.setCursor(0,1);
        lcd.print(h);
        lcd.print("%");
    }

    
  }}
  lastButtonState=reading;


}
