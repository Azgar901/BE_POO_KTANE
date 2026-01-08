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
#include "Simon.h"

Application::Application() : bombe(), ThreadModule(&bombe), Timer_(&bombe), Simon_V1(&bombe)
{
}
  
Application::~Application()
{
}  

void Application::init(void)
{
  ThreadModule.initPin();
  Timer_.begin();  // Affiche le temps de départ
  Simon_V1.Simon_config_pin();
}

void Application::run(void)
{
  Timer_.update(&bombe);  // S'occupe du temps du timer avec la fonction milis()
  bombe.Verify();
  ThreadModule.stateThread(&bombe);
  Simon_V1.Error0(&bombe);
}
