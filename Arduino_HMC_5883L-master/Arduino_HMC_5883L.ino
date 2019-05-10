#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
void setup(void) 
{
  Serial.begin(9600);
  if(!mag.begin())
  {
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
  }
}

void loop(void) 
{
  sensors_event_t event; 
  mag.getEvent(&event);
  Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.print("  ");Serial.println("uT");
  float heading = atan2(event.magnetic.y, event.magnetic.x);

  
  delay(500);
  float y = event.magnetic.y ;
  float x = event.magnetic.x ;
  float z = event.magnetic.z ;
  if(y>10) {
    digitalWrite(12,HIGH);
  }
  else {
    digitalWrite(12 ,LOW);
  }
  if(x>30) {
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(10,LOW);
  }
  if (y<-20) {
    digitalWrite(11 ,HIGH);
  }
  else {
    digitalWrite(11 ,LOW);
  }
}
