#include <Adafruit_BMP280.h>

class BMP280
{
  Adafruit_BMP280 bmp; // I2C
  public:
    BMP280();
    int temp();
    int pres();
    int alt();

};

BMP280::BMP280()
{
  bmp.begin();
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

int BMP280::temp()
{
  return bmp.readTemperature();
}

int BMP280::pres()
{
  return bmp.readPressure();
}
int BMP280::alt()
{
  return bmp.readAltitude(1013.25); /* Adjusted to local forecast! */
}