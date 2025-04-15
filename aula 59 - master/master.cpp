#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

uint8_t endSlave[] = {0x08, 0x3A, 0xF2, 0x8F, 0x8F, 0x7E};

void setup()
{
  Serial.begin(9600);

  //!                          ↓ indica que é master
  if (BT.begin("EspTueeeee", true)) //inicia a comunicação com o bluetooth no master 
  {
    Serial.println("Bluetooth iniciado com sucesso");
  }

  else
  {
    Serial.println("Não foi possivel conectar o Bluetooth");
  }

  if( BT.connect(endSlave) ) //endereço do dispositivo para conectar
  {
    Serial.println("Conectado com sucesso");
  }

  else
  {
    Serial.println("Não foi possivel conectar ao dispositivo");
  }

  // Serial.println(BT.getBtAddressString());

}

void loop()
{
  if(Serial.available())
  {
    String msgEnviar = Serial.readStringUntil('\n'); //ler a serial até encontrar um enter.
    msgEnviar.trim(); //tiras espaços nos finais, \n, \r etc.

    BT.println(msgEnviar); //enviar para o bluetooth de outra pessoa 
  }

  if(Serial.available())
  {
    String msgRecebida = BT.readStringUntil('\n');
    msgRecebida.trim();

    BT.printf("Mensagem recebida: %s", msgRecebida);

    if(msgRecebida.equals("liga"))
    {

    }

    else if(msgRecebida.equals("desliga"))
    {  
      
    }

  }


  


}
