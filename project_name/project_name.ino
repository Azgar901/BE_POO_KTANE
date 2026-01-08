#include "Application.h"
#include <TM1637Display.h>
#include <Arduino.h>


#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);  // Défini ici pour garantir l'ordre d'initialisation

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
  Serial.begin(9600);
}




void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();

}
