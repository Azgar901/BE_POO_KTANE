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

Application* Application::instance = nullptr;

Application::Application() : bombe(), ThreadModule(&bombe), Timer_(&bombe)
{
      instance = this;
}
  
Application::~Application()
{
  instance=nullptr;
}  

void Application::init(void)
{
  ThreadModule.initPin()
    ;
}

void Application::updateTimerFromISR() {
  Timer_.update();
}

ISR(TIMER1_OVF_vect) {
  if (Application::instance != nullptr) {
    Application::instance->updateTimerFromISR();
  }
}

void Application::run(void)
{
  bombe.Verify();
  //ThreadModule.stateThread();
    ;
}
