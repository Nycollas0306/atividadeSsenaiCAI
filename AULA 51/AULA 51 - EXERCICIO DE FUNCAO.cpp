#include <Arduino.h>

int hipotenusa(int, int);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int resultado = hipotenusa(3, 4);
  Serial.println(resultado);
}

int hipotenusa(int cateto1, int cateto2)
{
  int resultadoDosCatetos = sq(cateto1) + sq(cateto2);

  return sqrt(resultadoDosCatetos);
}