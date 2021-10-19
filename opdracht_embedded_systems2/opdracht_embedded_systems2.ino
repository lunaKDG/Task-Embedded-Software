#include <runtimer.h>                              //Library for the timer

#define led 9                                      //Pin 9 is the led
#define sensor A0                                  //Pin A0 is the sensor

intervalTimer timer1(2000);                        //Timer with an interval of 2000ms

int input;
int sensorHigh = 255;

void setup() 
{
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.flush();
}

void loop() 
{
  input = map(analogRead(sensor), 0, 1023, 0, 255); //Convert the input of the sensor of 0 - 1023 to 0 - 255
  analogWrite(led,(sensorHigh-input));
  if (timer1.expired()) 
  {
    Serial.print("The input is: ");
    Serial.println(input);
  }
}
