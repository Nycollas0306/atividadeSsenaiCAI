#include <Arduino.h>

char palavra[10] = "OLA MUNDO";
char palavra2[10] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};

String palavra3 = "HOJE EH QUINTA";

void setup()
{
  Serial.begin(9600);
  Serial.println();

  Serial.println(palavra);
  Serial.println(palavra2);

  strcpy(palavra, "SENAI");

  if (strcmp(palavra, "SENAI") == 0)
    ;
  {
    Serial.println("SAO IGUAIS");
  }

  if (strncmp(palavra2, "OLA", 3) == 0)
  {
    Serial.println("As primeiras letras da palavra é OLA");
  }

  if (strstr(palavra2, "MUNDO"))
  {
    Serial.print("Palavra MUNDO detectada");
  }

  //* -----------------------------------------------------------------------------

  Serial.println(palavra3.length()); // retorna o numero de letras do objeto da classe String

  Serial.println(palavra3.charAt(10)); // retorna a oitava posicao da palavra

  Serial.println(palavra3.substring(8, 14)); // retorna a 8° até a 14° posição

  Serial.println(palavra3.indexOf('U')); // retorna a posição da primeira ocorrência da letra procurada

  Serial.println(palavra3.lastIndexOf('E'));  // retorna a posição da ultima ocorrência da letra procurada
  if (palavra3.equals("HOJE EH QUINTA") == 1) // retorna verdadeiro se forem iguais
    Serial.println("São igauis");

  if (palavra3.equalsIgnoreCase("hoje eh quinta") == 1) // retorna verdadeiro se forem iguais ignorando letras maiusculas/minusculas
    Serial.println("São iguais");

  if (palavra3.startsWith("HOJE") == 1) // retorna verdadeiro se a palavra comecar com determinado texto
    Serial.println("Começa com HOJE");

  if (palavra3.endsWith("INTA") == 1) // retorna verdadeiro se a palavra terminar com determinado texto
    Serial.println("Termina com INTA");

  String valor = "123";
  int valorNumerico = valor.toInt(); // converte o valor do texto em valor numerico de "123" para 123 (numero)

  String valor2 = "10.5";
  float valorNumerico2 = valor2.toFloat();


  //*EXEMPLO: transforma o numero do texto em valor numerico tipo inteiro

  String mensagem = "Valor = 50";

  int tamanho = mensagem.length(); //medir o tamanho do texto

  String extracao = mensagem.substring(8, tamanho); //extrair o numero iniciando em uma posicao conhecida até o fim do texto

  Serial.println(tamanho);
  Serial.println(extracao);

  int numero = extracao.toInt(); //transforme o conteudo extraido em um numero inteiro
  
  Serial.println(numero * 2); //utilize o numero sem moderação... HAhaHAhaHAhaHA

  //! CONTINUANDO

  palavra3.toLowerCase();
  Serial.println(palavra3);
  palavra3.toUpperCase();
  Serial.println(palavra3);


  String textoLed = "Led = ON";
  Serial.println(textoLed);
  textoLed.replace("ON" , "OFF"); //substitui uma palavra no texto por outra
  Serial.println(textoLed); //"Led = OFF";

  String novaFase = "Texto      ";
  novaFase.trim(); //remove os espaços do fim do texto

  novaFase.concat(" adicionado"); //adiciona um texto a String
  Serial.println(novaFase);
}

void loop()
{

}