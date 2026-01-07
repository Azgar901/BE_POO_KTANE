#ifndef Thread_h
#define Thread_h

#include <Arduino.h>

#include "ModuleBase.hpp"


class Thread : public ModuleBase {
  public: 
    Thread(Bomb *bomb);
    void initPin();
    void stateThread(); // regarde si on a coupé un fil et vérifie, allume la LED et fais exploser la bombe
  };

#endif