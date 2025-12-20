#include "Thread.h"
#include <Arduino.h>
#include "Bombe.hpp" //recup la fonction ajout d'erreur (#include)
#include "ModuleBase.hpp"

Thread::Thread(Bomb *bomb) : ModuleBase(bomb) {
  }

void Thread::initPin() {
  for (int i = 31; i < 36; i++) {
    pinMode(i, INPUT);
  }
}


void Thread:: stateThread(){

  int state;
  for (int i=31;i<36; i++){
    state=digitalRead(i); 
    
    if(state==LOW){
      if (CuttedThread==0) {
        if (i!=31){
          bombp->AddError();
          CuttedThread++;
        }
      }
    }
  }
}
