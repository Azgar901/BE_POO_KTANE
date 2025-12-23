/*********************************************************************
 * @file  Apllication.h
 * @author <MELADE Ulrich -- LELE Bernys>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Bombe.hpp"
#include "Thread.h"
#include "Timer.hpp"

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
    Bomb bombe;
    Thread ThreadModule;
    Timer Timer_;

  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);

    void updateTimerFromISR(void);

    static Application* instance;
};
#endif