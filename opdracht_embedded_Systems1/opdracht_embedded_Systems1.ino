#include <runtimer.h>                    

#define led 9                           
#define sensor A0                            

intervalTimer timer1(2000);                        

int input;
int sensorHigh = 1023;

void setup() 
{
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  input = analogRead(sensor);
  analogWrite(led,(sensorHigh-input));
  if (timer1.expired()) 
  {
    Serial.print("The input is: ");
    Serial.println(input);
  }
}
