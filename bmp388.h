#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"

#define SEALEVELPRESSURE_HPA (1013.25)

class BMP388
{
  Adafruit_BMP3XX bmp;
  public:
    BMP388();
    int temp();
    int pres();
    int alt();

};

BMP388::BMP388()
{
  bmp.begin_I2C();
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);

  bmp.performReading();
}

int BMP388::temp()
{
  return bmp.temperature;
}

int BMP388::pres()
{
  return bmp.pressure / 100.0;
}
int BMP388::alt()
{
  return bmp.readAltitude(SEALEVELPRESSURE_HPA);
}