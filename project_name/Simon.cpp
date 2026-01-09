#include "Simon.h"
#include <Arduino.h>
#include "Bombe.hpp" //recup la fonction ajout d'erreur 
#include"ModuleBase.hpp"



Simon:: Simon(Bomb *b) : ModuleBase(b){
} //constructeur

// broche a verifier
#define ButtonRstate digitalRead(41)
#define ButtonBstate digitalRead(43)
#define ButtonJstate digitalRead(45)
#define ButtonVstate digitalRead(47)

void Simon::Simon_pin_config(){
  previousMillis = millis();
  for (int i = 40; i < 49; i++) {
    if (i%2==0)
      pinMode(i, OUTPUT); // config LEDs
    else
      pinMode(i, INPUT_PULLUP); // config bouton boussoir
  }
}

void Simon:: LED_ON(char led){
  if(led=='R'){
    digitalWrite(40,HIGH);
  }
  else if(led=='B'){
    digitalWrite(42,HIGH);
  }
  else if(led=='J'){
    digitalWrite(44,HIGH);
  }
  else if(led=='V'){
    digitalWrite(46,HIGH);
  }
}

void Simon:: LED_OFF(char led){
  if(led=='R'){
    digitalWrite(40,LOW);
  }
  else if(led=='B'){
    digitalWrite(42,LOW);
  }
  else if(led=='J'){
    digitalWrite(44,LOW);
  }
  else if(led=='V'){
    digitalWrite(46,LOW);
  }
}

void Simon::Reset(){
  bombp->AddError();

  previousMillis_R=millis();
  previousMillis_B=millis();
  previousMillis_J=millis();
  previousMillis_V=millis();
  currentMillis_R=millis();
  currentMillis_B=millis();
  currentMillis_J=millis();
  currentMillis_V=millis();
  currentMillis=millis();
  interval=4000;

  BB_temp=0;
  BR_temp=0;
  BJ_temp=0;
  BV_temp=0;

  nb_Leds=stage+1;
  Nb_Button=0;
  Prev_Led=NULL;
  Next_Led=NULL;
}

void Simon::Error0() {

}


void Simon::FlashLed0() {
  // ici on flash une fois un boutton appuyé
  if(BB_temp){
    currentMillis_B=millis();
    if((currentMillis_B - previousMillis_B)>=100) {
      LED_OFF('B');
      if (BB_temp == 1) {
        if (Tab_Stage[stage][Nb_Button] =='B') {
          if (Tab_Stage[stage][Nb_Button+1] ==' ') {
            stage++;
            nb_Leds=stage+1;
            Nb_Button=0;
          }
          else {
            Nb_Button++;
          }
        }
        else {
          Reset();
        }
        BB_temp = 2;
      }
    }
      else{
        LED_ON('B');
      }
      if ( ButtonBstate == HIGH and BB_temp == 2)
        BB_temp=0;
  }
    if(BR_temp) {
      currentMillis_R=millis();
      if((currentMillis_R - previousMillis_R)>=100) {
        LED_OFF('R');
        if (BR_temp == 1) {
          if (Tab_Stage[stage][Nb_Button] =='R'){
            if (Tab_Stage[stage][Nb_Button+1] ==' ') {
              stage++;
              nb_Leds=stage+1;
              Nb_Button=0;
            }
            else {
              Nb_Button++;
            }
          }
          else {
            Reset();
          }
          BR_temp = 2;
        }
      }
        else{
          LED_ON('R');
        }
        if ( ButtonRstate == HIGH and BR_temp == 2)
          BR_temp=0;
    }
    if(BJ_temp) {
      currentMillis_J=millis();
      if((currentMillis_J - previousMillis_J)>=100) {
        LED_OFF('J');
        if (BJ_temp == 1) {
          if (Tab_Stage[stage][Nb_Button] =='J'){
            if (Tab_Stage[stage][Nb_Button+1] ==' ') {
              stage++;
              nb_Leds=stage+1;
              Nb_Button=0;
            }
            else {
              Nb_Button++;
            }
          }
          else {
            Reset();
          }
          BJ_temp = 2;
        }
      }
        else{
          LED_ON('J');
        }
        if ( ButtonJstate == HIGH and BJ_temp == 2)
          BJ_temp=0;
    }
    if(BV_temp) {
      currentMillis_V=millis();
      if((currentMillis_V - previousMillis_V)>=100) {
        LED_OFF('V');
        if (BV_temp == 1) {
          if (Tab_Stage[stage][Nb_Button] =='V'){
            if (Tab_Stage[stage][Nb_Button+1] ==' ') {
              stage++;
              nb_Leds=stage+1;
              Nb_Button=0;
            }
            else {
              Nb_Button++;
            }
          }
          else {
            Reset();
          }
          BV_temp = 2;
        }
      }
        else{
          LED_ON('V');
        }
        if ( ButtonVstate == HIGH and BV_temp == 2)
          BV_temp=0;
    }
    // Si aucun boutton n'est appuyé
    if(BB_temp==0 and BR_temp==0 and BV_temp==0 and BJ_temp==0){
      currentMillis=millis();
      if ( currentMillis-previousMillis>=interval){
        previousMillis=currentMillis;
        if (interval==4000){
          LED_ON(Tab_Stage[stage][stage-(nb_Leds-1)]);
          interval=100;
          Prev_Led=Tab_Stage[stage][stage-(nb_Leds-1)];
          if((stage-(nb_Leds-1))>0){
            Next_Led=Tab_Stage[stage][stage-(nb_Leds-1)+1];
          }
        }
        else if(interval==100){
          LED_OFF(Prev_Led);
          nb_Leds--;
          if(nb_Leds>0)
            interval=500;
          else
            interval=4000;
        }
        else if(interval==500){
          LED_ON(Next_Led);
          interval=100;
          Prev_Led=Next_Led;
          if((stage-(nb_Leds-1))>0){
            Next_Led=Tab_Stage[stage][stage-(nb_Leds-1)+1];
          }
        }
      }
    }
  }



  void Simon::Simon_Check() {
    if ( ButtonRstate==LOW and BR_temp==LOW) {
      if ( BR_temp==LOW) {
        previousMillis_R=millis();
      }
      previousMillis=millis();
      interval=3000;
      BR_temp=HIGH;
    }
    else if ( ButtonBstate==LOW and BB_temp==LOW) {
      if ( BB_temp==LOW) {
        previousMillis_B=millis();
      }
      previousMillis=millis();
      interval=3000;
      BB_temp=HIGH;
    }
    else if ( ButtonJstate==LOW and BJ_temp==LOW) {
      if ( BJ_temp==LOW) {
        previousMillis_J=millis();
      }
      previousMillis=millis();
      interval=3000;
      BJ_temp=HIGH;
    }
    else if ( ButtonVstate==LOW and BV_temp==LOW) {
      if ( BV_temp==LOW) {
        previousMillis_V=millis();
      }
      previousMillis=millis();
      interval=3000;
      BV_temp=HIGH;
    }
    int err = bombp->getError();
    if (err==0)
      FlashLed0();
    else if (err==1)
      FlashLed1();
    else if (err==2)
      FlashLed2();
  }