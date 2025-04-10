#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#define pinBotaoA 19
#define pinBotaoB 18
#define pinBotaoC 5

#define LedA 12
#define LedB 14
#define LedC 27
#define LedD 26

// Instancia de objeto
Bounce botaoA = Bounce();
Bounce botaoB = Bounce();
Bounce botaoC = Bounce();

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  Serial.begin(9600);

  botaoA.attach(pinBotaoA, INPUT_PULLUP);
  botaoB.attach(pinBotaoB, INPUT_PULLUP);
  botaoC.attach(pinBotaoC, INPUT_PULLUP);

  pinMode(LedA, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(LedC, OUTPUT);
  pinMode(LedD, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(">LED 1 - 0");

  lcd.setCursor(0, 1);
  lcd.print(" LED 2 - 0");

  lcd.setCursor(0, 2);
  lcd.print(" LED 3 - 0");

  lcd.setCursor(0, 3);
  lcd.print(" LED 4 - 0");
}

void loop()
{
  static bool modoSelecao = 1;
  static int contador = 0;
  static bool alteracao = 0;

  static int itnsLedA = 0;
  static int itnsLedB = 0;
  static int itnsLedC = 0;
  static int itnsLedD = 0;

  botaoA.update();
  botaoB.update();
  botaoC.update();

  // Botao C pressionado
  if (botaoC.fell())
  {
    alteracao = 1;
    modoSelecao = !modoSelecao;
  }

  // Botao B pressionado
  if (botaoB.fell())
  {

    alteracao = 1;

    if (modoSelecao) //== true
    {
      contador++; // contador += 1; ou contador = contador + 1;

      // if (contador > 3) contador = 0;
      if (contador > 3)
      {
        contador = 0;
      }
    }

    else
    {
      switch (contador)
      {
      case 0:
        if (itnsLedA > 0)
          itnsLedA -= 10;
        break;

      case 1:
        if (itnsLedB > 0)
          itnsLedB -= 10;
        break;

      case 2:
        if (itnsLedC > 0)
          itnsLedC -= 10;
        break;

      case 3:
        if (itnsLedD > 0)
          itnsLedD -= 10;
        break;

      default:
        break;
      }
    }
  }

  // Botao A pressionado
  if (botaoA.fell())
  {

    alteracao = 1;

    if (modoSelecao) //== true
    {

      contador--; // contador -= 1; ou contador = contador - 1;

      // if (contador > 3) contador = 0;
      if (contador < 0)
      {
        contador = 3;
      }
    }

    else
    {
      switch (contador)
      {
      case 0:
        if (itnsLedA <= 90)
          itnsLedA += 10;
        break;

      case 1:
        if (itnsLedB <= 90)
          itnsLedB += 10;
        break;

      case 2:
        if (itnsLedC <= 90)
          itnsLedC += 10;
        break;

      case 3:
        if (itnsLedD <= 90)
          itnsLedD += 10;
        break;

      default:
        break;
      }
    }
  }


  // LCD

  if (alteracao)//executa somente se ouve alteração, ou seja, quando um botao for pressionado
  {

    alteracao = 0;

    if (modoSelecao)//modoSelecao == true
    {
      if (contador == 0)//verifica o valor da variavel contador, utilizado para posicionar a seta
      {
        lcd.setCursor(0, 0);
        lcd.print(">");
        
        lcd.setCursor(8, 0);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(" ");
        lcd.setCursor(0, 3);
        lcd.print(" ");
      }

      else if (contador == 1)
      {
        lcd.setCursor(0, 1);
        lcd.print(">");
        
        lcd.setCursor(8, 1);
        lcd.print(" ");
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(0, 2);
        lcd.print(" ");
      }

      else if (contador == 2)
      {
        lcd.setCursor(0, 2);
        lcd.print(">");
        
        lcd.setCursor(8, 2);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print(" ");
        lcd.setCursor(0, 3);
        lcd.print(" ");
      }

      else // é 3
      {
        lcd.setCursor(0, 3);
        lcd.print(">");
        
        lcd.setCursor(8, 3);
        lcd.print(" ");
        lcd.setCursor(0, 2);
        lcd.print(" ");
        lcd.setCursor(0, 0);
        lcd.print(" ");
      }
    }

    else//modoSelecao == false
    {
      if (contador == 0)
      {
        lcd.setCursor(8, 0);
        lcd.print(">");
        
        lcd.setCursor(0, 0);
        lcd.print(" ");
        lcd.setCursor(8, 1);
        lcd.print(" ");
        lcd.setCursor(8, 3);
        lcd.print(" ");
        
        lcd.setCursor(9, 0);
        lcd.print(itnsLedA);
        lcd.print(" ");
      }

      else if (contador == 1)
      {
        lcd.setCursor(8, 1);
        lcd.print(">");
        
        lcd.setCursor(0, 1);
        lcd.print(" ");
        lcd.setCursor(8, 0);
        lcd.print(" ");
        lcd.setCursor(8, 2);
        lcd.print(" ");
    
        lcd.setCursor(9, 1);
        lcd.print(itnsLedB);
        lcd.print(" ");
      }

      else if (contador == 2)
      {
        lcd.setCursor(8, 2);
        lcd.print(">");
        
        lcd.setCursor(0, 2);
        lcd.print(" ");
        lcd.setCursor(8, 1);
        lcd.print(" ");
        lcd.setCursor(8, 3);
        lcd.print(" ");
    
        lcd.setCursor(9, 2);
        lcd.print(itnsLedC);
        lcd.print(" ");
      }
      
      else // é 3
      {
        lcd.setCursor(8, 3);
        lcd.print(">");
        
        lcd.setCursor(0, 3);
        lcd.print(" ");
        lcd.setCursor(8, 2);
        lcd.print(" ");
        lcd.setCursor(8, 0);
        lcd.print(" ");
    
        lcd.setCursor(9, 3);
        lcd.print(itnsLedD);
        lcd.print(" ");
      }
    }


    // LEDs
    analogWrite(LedA, itnsLedA * 2.55);
    analogWrite(LedB, itnsLedB * 2.55);
    analogWrite(LedC, itnsLedC * 2.55);
    analogWrite(LedD, itnsLedD * 2.55);
  }
}