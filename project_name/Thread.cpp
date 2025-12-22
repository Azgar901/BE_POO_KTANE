#include "Thread.h"
#include <Arduino.h>
#include "Bombe.hpp" //recup la fonction ajout d'erreur (#include)
#include "ModuleBase.hpp"

Thread::Thread(Bomb *bomb) : ModuleBase(bomb) {
  }

void Thread::initPin() {
  for (int i = 31; i < 40; i++) {
    if ( i%2==1)
      pinMode(i, INPUT_PULLUP);
  }
}


void Thread:: stateThread(){

  int state;
  for (int i=31;i<40; i++){
    if (i%2==1){
      state=digitalRead(i); 
      if(state==HIGH){
        if (CuttedThread==0) {
          if (i!=31){
            bombp->AddError();
            CuttedThread=CuttedThread+1;
          }
        }
      }
    }
  }
}
