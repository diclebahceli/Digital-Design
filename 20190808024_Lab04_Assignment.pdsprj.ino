 const int AnalogIn=A0;
 const int AnalogOut=9;

 int LDRValue=0;
 int LEDStatus=0;
 
 
 void setup() {
 
 Serial.begin(9600);
 
}

void loop() {
  LDRValue=analogRead(AnalogIn);
  LEDStatus=analogRead(AnalogOut);

  if(LDRValue<823){
    LEDStatus=1;
  }else if(LDRValue>823){
    LEDStatus=0;
  }

  Serial.print("LDRValue: ");
  Serial.print(LDRValue);
  Serial.print(" ,LEDStatus: ");
  Serial.print(LEDStatus);
  Serial.println();
  delay(1000);
  
}
