#include "Simon.h"
#include <Arduino.h>
#include "Bombe.hpp" //recup la fonction ajout d'erreur 
#include"ModuleBase.hpp"



Simon:: Simon(Bomb *b) : ModuleBase(b){

} //constructeur

void Simon::Simon_config_pin(){
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
   int ButtonB=LOW; 
    int ButtonR=LOW; 
    int ButtonJ=LOW; 
    int ButtonV=LOW; 
    int BB_OK=LOW; 
    int BR_OK=LOW; 
    int BJ_OK=LOW; 
    int BV_OK=LOW; 
    unsigned long previousMillis_R=millis();
    unsigned long previousMillis_B=millis();
    unsigned long previousMillis_J=millis();
    unsigned long previousMillis_V=millis();
    unsigned long currentMillis_R=millis();
    unsigned long currentMillis_B=millis();
    unsigned long currentMillis_J=millis();
    unsigned long currentMillis_V=millis();
    unsigned long currentMillis=millis();
}

void Simon::FlashLed0(){

  // ici on flash une fois un boutton appuyé
  if(BB_temp){ // On appuie d'abord le Bleu
    currentMillis_B=millis();
    if((currentMillis_B - previousMillis_B)>=100){
      previousMillis_B=currentMillis_B;
      LED_OFF('R');
      if(stage==0){
        stage++;
        nb_Leds+=1;
        BB_temp=0;
        Reset();
      }
    }
    else{
      LED_ON('R');
    }
  }
  else if(BR_temp){ //on appuie sur le bleu
    currentMillis_R=millis();
    if((currentMillis_R - previousMillis_R)>=100){
      previousMillis_R=currentMillis_R;
      LED_OFF('B');
      if(stage==1){
        stage++;
        nb_Leds=stage+1;
        BR_temp=0;
      }
    }
    else{
      LED_ON('B');
    }
  }
  else if(BJ_temp){ //on appuie sur le rouge
    currentMillis_J=millis();
    if((currentMillis_J - previousMillis_J)>=100){
      previousMillis_J=currentMillis_J;
      LED_OFF('V');
      if(stage==2){
        stage++;
        nb_Leds=stage+1;
        BJ_temp=0;
      }
    }
    else{
      LED_ON('V');
    }
  }

  else if(BV_temp){ //on appuie sur le rouge
    currentMillis_R=millis();
    if((currentMillis_V - previousMillis_V)>=100){
      previousMillis_V=currentMillis_V;
      LED_OFF('J');
      if(stage==3){
        stage++;
        nb_Leds=stage1;
        BV_temp=0;
      }
    }
    else{
      LED_ON('J');
    }
  }
  // Si aucun boutton n'est appuyé
  else{
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