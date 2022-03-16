// -> CHAMADA DAS CLASSES E DEFINICAO DE PINAGENS
#include "bmp280.h"
#include "bmp388.h"
#include "sd.h"

BMP280 bmp280;
BMP388 bmp388;
CARTAOSD csd;

#define DROGUE 33 //pino DROGUE_AVIONICS
#define MAIN 34 //pino MAIN_AVIONICS

// -> DEFINICAO DOS ESTADOS
#define INITIALIZATION          0 
#define ARMED_AND_TRANSPORTING  1 
#define LIFTOFF                 2 
#define COASTING                3 
#define APOGEE                  4 
#define DROGUE_DEPLOYED         5 
#define GROUND_APRX             6
#define MAIN_DEPLOYED           7 
#define TOUCHDOWN               8 

volatile char estadoAtual;

void maquinaEstados ()
{
  switch(estadoAtual)
  {
    case INITIALIZATION:
    {
      //implementacao do estado INITIALIZATION
      break; 
    }
    case ARMED_AND_TRANSPORTING:
    {
      //implementacao do estado ARMED_AND_TRANSPORTING
      break; 
    }
    case LIFTOFF:
    {
      //implementacao do estado LIFTOFF
      break; 
    }
    case COASTING:
    {
      //implementacao do estado COASTING
      break; 
    }
    case APOGEE:
    {
      //implementacao do estado APOGEE
      break; 
    }
    case DROGUE_DEPLOYED:
    {
      //implementacao do estado DROGUE_DEPLOYED
      digitalWrite(DROGUE, HIGH); //acionar drogue
      break; 
    }
    case GROUND_APRX:
    {
      //implementacao do estado GROUND_APRX
      break; 
    }
    case MAIN_DEPLOYED:
    {
      //implementacao do estado MAIN_DEPLOYED
      digitalWrite(MAIN, HIGH); //acionar main
      break; 
    }
    case TOUCHDOWN:
    {
      //implementacao do estado TOUCHDOWN
      break; 
    }
  }
}
