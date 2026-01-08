#ifndef Simon_h
#define Simon_h
#include "Bombe.hpp"
#include <Arduino.h>

class Simon: public ModuleBase {

  public:
    int ButtonB=LOW; //Bouton Bleu allumé ou pas
    int ButtonR=LOW; //Bouton Bleu allumé ou pas
    int ButtonJ=LOW; //Bouton Bleu allumé ou pas
    int ButtonV=LOW; //Bouton Bleu allumé ou pas
    int BB_OK=LOW; // Bouton Bleu appuyé
    int BR_OK=LOW; // Bouton Bleu appuyé
    int BJ_OK=LOW; // Bouton Bleu appuyé
    int BV_OK=LOW; // Bouton Bleu appuyé
    char Prev_Led;
    char Next_Led;
    int BB_temp=LOW; // Bouton Bleu appuyé
    int BR_temp=LOW; // Bouton Bleu appuyé
    int BJ_temp=LOW; // Bouton Bleu appuyé
    int BV_temp=LOW; // Bouton Bleu appuyé
    int stage=0;
    int nb_Leds=1;
    unsigned long previousMillis_R=millis();
    unsigned long previousMillis_B=millis();
    unsigned long previousMillis_J=millis();
    unsigned long previousMillis_V=millis();
    unsigned long previousMillis=millis();

    unsigned long currentMillis_R=millis();
    unsigned long currentMillis_B=millis();
    unsigned long currentMillis_J=millis();
    unsigned long currentMillis_V=millis();
    unsigned long currentMillis=millis();

    unsigned long interval=4000;

    char Tab_Stage[5][6] = {
        {'R',' ',' ',' ',' ',' '},
        {'R', 'B', ' ', ' ', ' '}, // Stage 1
        {'R', 'B', 'V', ' ', ' '}, // Stage 2
        {'R', 'B', 'V', 'J', ' '}, // Stage 3
        {'R', 'B', 'V', 'J', 'R'}  // Stage 4
    };
    int pin_button[4]={41,43,45,47}; // pins des bouttons poussoir

    Simon(Bomb *b);
    void Simon_config_pin();
    void LED_ON(char led);
    void LED_OFF(char led);
    void Reset(); //reset toute la classe et ajoute l'erreur à la classe Bombe et
    void FlashLed0();
    void FlashLed1();
    void FlashLed2();
    void Error0(Bomb *b); // verifie qu'on a bien suivi la bonne séquence
    void Error1(int err, Bomb *b);
    void Error2(int err, Bomb *b);
    void Test_error(int err, Bomb *b);

    ~Simon();
  };

#endif