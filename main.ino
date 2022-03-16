//codigo ja para a implementacao total

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "maquinaEstados.h"

void setup() {
  estadoAtual = INITIALIZATION;
  pinMode(DROGUE, OUTPUT);
  pinMode(MAIN, OUTPUT);
}

void loop() {
  if (bmp388.alt() > 3000 && bmp280.alt() > 3000)
  {
    estadoAtual = DROGUE_DEPLOYED;
  }

  if (bmp388.alt() > 2000 && bmp280.alt() > 2000)
  {
    estadoAtual = MAIN_DEPLOYED;
  }


  // ESCRITA SERA IMPOSTA NO MAIN SOMENTE PARA O TESTE DO BAROMETRO -> SERA COLOCADA NO ESTADO RESPECTIVO APOS
  
  //escrita no SD -> estilo CSV para ser eficiente nas futuras analises
  //no seguinte formato:
  //temp bmp388 ; press bmp388 ; alt bmp388 ; temp bmp280 ; press bmp280 ; alt bmp280 

  // -> escrita do bmp388
  csd.escrever(bmp388.temp());
  csd.escrever(";");
  csd.escrever(bmp388.pres());
  csd.escrever(";");
  csd.escrever(bmp388.alt());
  csd.escrever(";");

  // -> escrita do bmp280
  csd.escrever(bmp280.temp());
  csd.escrever(";");
  csd.escrever(bmp280.pres());
  csd.escrever(";");
  csd.escrever(bmp280.alt());
  csd.escrever("\n");
  
}
