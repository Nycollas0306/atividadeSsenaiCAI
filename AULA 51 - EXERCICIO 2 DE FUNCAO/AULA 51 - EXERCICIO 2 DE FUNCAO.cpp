#include <Arduino.h>

float fahrenheit(float);
float polegadas(float);

void setup()
{
  Serial.begin(9600);
  Serial.println(fahrenheit(30));
  Serial.println(polegadas(1));
}

void loop()
{
 
}

float fahrenheit(float c)
{
  return c * 9/5 + 32;
}

float polegadas(float milimetros)
{
  return milimetros / 25.4;
}