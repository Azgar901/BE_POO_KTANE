#ifndef Thread_h
#define Thread_h

#include <Arduino.h>


class Thread {

  public: 
    Thread(); 
    void initPin();
    void stateThread(); // si le fil coupé est le bon
    ~Thread();
  };

#endif