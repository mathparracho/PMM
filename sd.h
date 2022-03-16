#include <SD.h>

class CARTAOSD
{
  File myFile;
  public:
    CARTAOSD();
    int escrever(const char*);
    int escrever(int);

};

CARTAOSD::CARTAOSD()
{
  SD.begin(27);
  myFile = SD.open("data.txt", FILE_WRITE);
}

int CARTAOSD::escrever(const char *texto)
{
if (myFile)
    {
  	while (*texto) myFile.print(*(texto++));
    }
    else
    {
        while(1);
    }

    myFile.close();

return 0;
}


int CARTAOSD::escrever(int valor)
{
if (myFile)
    {
  	myFile.print(valor);
    }
    else
    {
        while(1);
    }

    myFile.close();

return 0;
}