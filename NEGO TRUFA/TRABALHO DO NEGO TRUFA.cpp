#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define pinLed 2
#define pinBotao 19
#define valorBotao 0

LiquidCrystal_I2C lcd(0x27, 20, 4);

//bonecos 

byte negoTrufa[] = {
    B01110,
    B01110,
    B01110,
    B00100,
    B11111,
    B00100,
    B00100,
    B01010};
byte negoTrufa2[] = {
    B01110,
    B01110,
    B01110,
    B00101,
    B00110,
    B01100,
    B10100,
    B01010};

byte negoTrufa3[] = {
    B01110,
    B01110,
    B01110,
    B10100,
    B01100,
    B00110,
    B00101,
    B01010};

void setup()
{
  lcd.init();
  lcd.createChar(0, negoTrufa);   //definir numero do boneco 
  lcd.createChar(1, negoTrufa2);  //definir numero do boneco
  lcd.createChar(2, negoTrufa3);  //definir numero do boneco
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("NEGO TRUFA");       //fixar mensagens iniciais 
  lcd.setCursor(0, 2);
  lcd.print("OHH NOVINHA");     //fixar mensagens iniciais
  lcd.setCursor(0, 1);
  lcd.write(0);                 //fixar boneco inicial 
  pinMode(pinLed, OUTPUT);
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop()
{
  //variaveis 
  static bool estadoAnteriorBotao = 1; 

  static bool estadoBotao = 0;

  static bool estadoLed = 0;

  static bool fase = 0;

  bool estadoAtual = digitalRead(19);     //ler botao 

  if (estadoAtual != estadoAnteriorBotao) 
  {
    estadoLed = !estadoLed;                //fazer com que o led ligue 
    digitalWrite(pinLed, estadoLed);
    lcd.setCursor(12, 2);                 //colocar no display a ultima frase 
    lcd.print("BROTA");
    lcd.setCursor(0, 3);
    lcd.print("NO BAILE DO PANTA");      //colocar no display a ultima frase 

    if (!fase) //definir a fase do boneco
    {
      fase = 1;
    }
    
    else
    {
      fase = 0;
    }
  }

  if (fase)  //fases para o boneco dancar 
  {
    lcd.setCursor(0, 1);
    lcd.write(0);
    delay(500);

    lcd.setCursor(0, 1);
    lcd.write(1);
    delay(500);

    lcd.setCursor(0, 1);
    lcd.write(2);
    delay(500);
  }

  estadoAnteriorBotao = estadoAtual;     //igualar os estados do botao 

}