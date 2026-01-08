/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Bombe.hpp"
#include <Arduino.h>
#include <TM1637Display.h>
#include "Thread.h"
#include "Timer.hpp"
#include "Speaker.hpp"
Application::Application() : ThreadModule(&bombe), Timer_(&bombe)
{
}
  
Application::~Application()
{
}  

void Application::init(void)
{
  //ThreadModule.initPin();
  Timer_.begin();  // Affiche le temps de départ
  init_Speaker();
  delay(2000);
  Serial.println("OK");
  Play_Music("boom");
  delay(2000);
  Play_Music("cri");
}

void Application::run(void)
{
  Timer_.update(&bombe);  // S'occupe du temps du timer avec la fonction milis()
  bombe.Verify();
  //ThreadModule.stateThread();
}
