#include "Thread.h"
#include <Arduino.h>
#include "Bombe.hpp" //recupère la fonction ajout d'erreur
#include "ModuleBase.hpp"

Thread::Thread(Bomb *bomb) : ModuleBase(bomb) {
  }

void Thread::initPin() {
  for (int i = 31; i < 40; i++) {
    if ( i%2==1)
      pinMode(i, INPUT_PULLUP);   // On relie les fils à GND, si le fil est coupé il sera à l'état haut
  }
      pinMode(26, OUTPUT);        // broche de la LED de validation
}

void Thread:: stateThread(){
      int state;                    // Variables pour l'état des broches
      for (int i=31;i<40; i++){
        if (i%2==1){                // On ne regarde que les broches impaires
          state=digitalRead(i);     // On regarde l'état du pin
          if(state==HIGH){          // Si la broche est à 1 alors on entre ( fil coupé )
              if (i!=31){
                bombp->AddError();  // Si on coupe le mauvais fil, la bombe explose directement
                bombp->AddError();
                bombp->AddError();
                led=0;
                digitalWrite(26, LOW);
              }
              else{
                led=1;                            // Sinon, la led de validation s'allume
                digitalWrite(26, HIGH);
              }
            }
          }
      }
}
