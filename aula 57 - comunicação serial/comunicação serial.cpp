#include <Arduino.h>

#define led 2

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop()
{
  static bool estadoLed = 0;
  static bool pisca = false;
  static int tempo = 500;

  static char vel = 0;

  if (Serial.available())
  {
    String msg = Serial.readStringUntil('\n');
    msg.trim();
    msg.toLowerCase();

    if (msg.equals("liga"))
    {
      estadoLed = true;
      pisca = false;
    }

    else if (msg.equals("desliga"))
    {
      estadoLed = false;
      pisca = false;
    }

    else if (msg.equals("pisca"))
    {
      pisca = true;
    }

    if (msg.equals("rapido"))
    {
      tempo -= 50;
      if (tempo < 50)
      {
        tempo = 50;
        Serial.println("velocidade maxima atingida!");
      }
    }

    if (msg.equals("lento"))
    {
      tempo += 50;
      if (tempo > 1000)
      {
        tempo = 1000;
        Serial.println("velocidade minima atingida!");
      }
    }

    if (msg.startsWith("vel = "))
    {
      int tamanho = msg.length();

      String extracao = msg.substring(6, tamanho);

      int numero = extracao.toInt();

      tempo = map(numero, 0, 100, 1000, 100);
    }

    else
    {
      Serial.println("comando não indentificado");
    }
  }

  if (pisca == true)
  {
    unsigned long tempoAtual = millis();
    static unsigned long tempoAnterior = 0;

    if (tempoAtual - tempoAnterior > tempo)
    {
      estadoLed = !estadoLed;
      tempoAnterior = tempoAtual;
    }
  }
  digitalWrite(led, estadoLed);
}

//* LER APENAS UM CARACTER

// void loop()
// {
//   if(Serial.available())
//   {
//     char caracter = Serial.read();
//     Serial.printf("Recebido letra: %c\n\r", caracter);

//     if(caracter == 'a')
//     {
//       digitalWrite(led, HIGH);
//     }

//     else if(caracter == 'b')
//     {
//       digitalWrite(led, LOW);
//     }
//   }
// }