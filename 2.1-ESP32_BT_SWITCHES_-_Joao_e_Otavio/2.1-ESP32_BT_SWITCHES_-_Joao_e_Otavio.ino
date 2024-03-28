//https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control (Aplicativo)

//*****************DIRETIVAS DO PRÉ-PROCESSADOR*****************************************************
//includes (arquivos de inclusão) e define (definições)
#include "BluetoothSerial.h"  //biblioteca já intalada do esp32
BluetoothSerial SerialBT;    //criação de um objeto SerialBT

//*****************DECLARAÇÕES GLOBAIS**************************************************************
//declaração de variáveis e funções (subrotinas)
char recebido = 0;            //declaração da variavel qu irá receber o valor via serial 

//**********************SETUP***********************************************************************
//define condições de trabalhos dos pinos (input/output), velocidade de comunicação e outras funções
void setup()
{
  #if !defined(CONFIG_BT_ENABLED)  || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please  run `make menuconfig` to and enable it
  #endif

  Serial.begin(115200);        //velocidade da comunicação serial
  SerialBT.begin("ESP32_PCB2");//nome do Bluetooth na lista para parear
  Serial.println("O dispositivo foi inicializado! aguardando ser pareado!");//mensagem
  pinMode(2, OUTPUT);          // define o pino 2, led da placa esp32, como saida
  pinMode(4, OUTPUT);          // define o pino 2, led da placa esp32, como saida
  pinMode(5, OUTPUT);          // define o pino 2, led da placa esp32, como saida
  pinMode(18, OUTPUT);          // define o pino 2, led da placa esp32, como saida

}

//*********************PROGRAMA PRINCIPAL**********************************************************
void loop()
{
   if (SerialBT.available() > 0)//verifica se chegou algum dado(ou caracter) via serial
     {
         recebido = SerialBT.read();//o dado(ou caracter) que chegar será armazenado na variavel recebido
         Serial.write(recebido);   //*escreve no monitor serial o valor
     }
  
  switch (recebido){

    case 'F':
      digitalWrite(2,HIGH);
      break;

    case 'f':
      digitalWrite(2,LOW);
      break;

    case 'B':
      digitalWrite(4,HIGH);
      break;

    case 'b':
      digitalWrite(4,LOW);
      break;

    case 'L':
      digitalWrite(5,HIGH);
      break;

    case 'l':
      digitalWrite(5,LOW);
      break;

    case 'R':
      digitalWrite(18,HIGH);
      break;

    case 'r':
      digitalWrite(18,LOW);
      break;

    default:
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(18,LOW);
  }
   
  
}

//**********************DEFINIÇÕES DAS FUNÇÕES*******************************************************
//subrotinas da programação
