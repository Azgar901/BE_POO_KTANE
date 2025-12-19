#include "Thread.h"
#include <Arduino.h>
#include "Bombe.hpp" //recup la fonction ajout d'erreur (#include)

extern Bomb b;

Thread::Thread(){

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
      if (i!=31){
        b.AddError();
      }
    }
  }
}

Thread::~Thread(){
  
}