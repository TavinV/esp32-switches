//https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control (Aplicativo)

//*****************DIRETIVAS DO PRÉ-PROCESSADOR*****************************************************
//includes (arquivos de inclusão) e define (definições)
#include "BluetoothSerial.h"  //biblioteca já intalada do esp32
BluetoothSerial SerialBT;    //criação de um objeto SerialBT

//*****************DECLARAÇÕES GLOBAIS**************************************************************
//declaração de variáveis e funções (subrotinas)

String recebido = "none";            //declaração da variavel qu irá receber o valor via serial 
String comando = "none";
//**********************SETUP***********************************************************************
//define condições de trabalhos dos pinos (input/output), velocidade de comunicação e outras funções
void setup()
{
  #if !defined(CONFIG_BT_ENABLED)  || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please  run `make menuconfig` to and enable it
  #endif

  Serial.begin(115200);        //velocidade da comunicação serial
  SerialBT.begin("ESP32_PCB_777"); //nome do Bluetooth na lista para parear
  Serial.println("O dispositivo foi inicializado! aguardando ser pareado!"); //mensagem

  // COLOCANDO OS PINOS NO MODO SAÍDA
  
  pinMode(2, OUTPUT);          
  pinMode(4, OUTPUT);          
  pinMode(5, OUTPUT);          
  pinMode(18, OUTPUT); 
           
  pinMode(19, OUTPUT);  
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);

  pinMode(32, OUTPUT); // Pino de Erro (comando não reconhecido)

  /*
   *        COMODO      |       COMANDO DE VOZ          |      LED À ACENDER

            SALA                LIGUE A LUZ DA SALA             2  
            QUARTO DO OTAVIO    LIGUE A LUZ DO QUARTO DO OTÁVIO 4  
            COZINHA             LIGUE A LUZ DA COZINHA          5
            GARAGEM             LIGUE A LUZ DA GARAGEM          18
            BANHEIRO            LIGUE A LUZ DO BANHEIRO         19
            SACADA              LIGUE A LUZ DA SACADA           21
            CORREDOR            LIGUE A LUZ DO CORREDOR         22
            QUARTO DO JOÃO      LIGUE A LUZ DO QUARTO DO JOÃO   23

   */
}

//*********************PROGRAMA PRINCIPAL**********************************************************
void loop()
{
   if (SerialBT.available() > 0)//verifica se chegou algum dado(ou caracter) via serial
     {
         recebido = SerialBT.readString(); //o dado(ou caracter) que chegar será armazenado na variavel recebido
        recebido.toLowerCase();
         Serial.println(recebido);   //*escreve no monitor serial o valor
     }

         if (recebido.equals("ligue a luz da sala")){
      digitalWrite(2,HIGH);
     }

    else if(recebido.equals("desligue a luz da sala")){
      digitalWrite(2,LOW);
    }

    else if(recebido.equals("ligue a luz do quarto do otávio")){
      digitalWrite(4,HIGH);
    }

    else if(recebido.equals("desligue a luz do quarto do otávio")){
      digitalWrite(4,LOW);
    }

    else if(recebido.equals("ligue a luz da cozinha")){
      digitalWrite(5,HIGH);
    }

    else if(recebido.equals("desligue a luz da cozinha")){
      digitalWrite(5,LOW);
    }

    else if(recebido.equals("ligue a luz da garagem")){
      digitalWrite(18,HIGH);
    }

    else if(recebido.equals("desligue a luz da garagem")){
      digitalWrite(18,LOW); 
    }

    else if(recebido.equals("ligue a luz do banheiro")){
      digitalWrite(19,HIGH); 
    }
    
    else if(recebido.equals("desligue a luz do banheiro")){
      digitalWrite(19,LOW);
    }

    else if(recebido.equals("ligue a luz da sacada")){
      digitalWrite(21,HIGH);     
    }

    else if(recebido.equals("desligue a luz da sacada")){
      digitalWrite(21,LOW);
    }

    else if(recebido.equals("ligue a luz do corredor")){
      digitalWrite(22,HIGH);
    }

    else if(recebido.equals("desligue a luz do corredor")){
      digitalWrite(22,LOW);
    }

    else if(recebido.equals("ligue a luz do quarto do joão")){
      digitalWrite(23,HIGH);
    }

    else if(recebido.equals("desligue a luz do quarto do joão")){
      digitalWrite(23,LOW);
    }

    else{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(18,LOW);
      digitalWrite(19,LOW);
      digitalWrite(21,LOW);
      digitalWrite(22,LOW);
      digitalWrite(23,LOW);

    }   

}
