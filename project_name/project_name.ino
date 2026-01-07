#include "Application.h"
#include <TM1637Display.h>

/////// Port Timer ///////
#define CLK 2 // Port PWM 2
#define DIO 3 // Port PWM 3
//////////////////////////

TM1637Display display(CLK, DIO);  // Défini ici pour garantir l'ordre d'initialisation

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
}



void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();

}
