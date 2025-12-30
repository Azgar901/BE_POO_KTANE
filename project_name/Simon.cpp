#include "Simon.h"
#include <Arduino.h>
#include "Bombe.hpp" //recup la fonction ajout d'erreur 

extern Bomb b;

Simon:: Simon(){

} //constructeur

void Simon::config_pin(){
  for (int i = 40; i < 49; i++) {
    if (i%2==0)
      pinMode(i, INPUT); // config LEDs
    else
      pinMode(i, OUTPUT); // config bouton boussoir
  }
}

  /*void Simon:: Led_on(int pin_Led, int pin_PushButton){
   if (digitalRead(pin_PushButton)==1){
    if (digitalRead(pin_Led)==0)
      digitalWrite(pin_Led, HIGH);
   }
   }*/

   void Simon:: Led_ON(){
    
      if (digitalRead(41)==1)
        digitalWrite(40, HIGH); // LED Rouge
      else if (digitalRead(43)==1)
        digitalWrite(42, HIGH); // LED Bleu
      else if (digitalRead(45)==1)
        digitalWrite(44, HIGH); // LED Jaune
      else if (digitalRead(47)==1)
        digitalWrite(46, HIGH); // LED Vert
   }
  void Simon:: to_flash(int flash){
      delay(1000);
      digitalWrite(flash, HIGH);
      delay(1000);
      digitalWrite(flash, LOW);
    }


  void Simon::Error1(int err){
    int pin_flash=40; // rouge
    int error=err;
    while (error==1) {
      to_flash(pin_flash);
      Led_ON();
      if ( (digitalRead(44)==HIGH) and pin_flash==40 ){ // condition si le rouge clignote 
        pin_flash=42;
        to_flash(pin_flash);
        if ( (digitalRead(46)==HIGH) and pin_flash==42 ){ // condition si le bleu clignote 
            pin_flash=46;
            to_flash(pin_flash);
    
            if ( (digitalRead(42)==HIGH) and pin_flash==46 ){ // condition si le vert clignote 
              pin_flash=44;
              to_flash(pin_flash);
          
              if ( (digitalRead(40)==HIGH) and pin_flash==44 ) // condition si le jaune clignote 
                digitalWrite(48,HIGH); //Mission réussie
              else{
                error+=1;
                b.AddError();
                digitalWrite(42,LOW);
                digitalWrite(46,LOW);
                digitalWrite(44,LOW);
              }
            }
            else{
              error+=1;
              b.AddError();
              digitalWrite(44,LOW);
              digitalWrite(46,LOW);
              digitalWrite(40,LOW);
            }
          } 
          else{
          error+=1;
          b.AddError();
          digitalWrite(42,LOW);
          digitalWrite(44,LOW);
          digitalWrite(40,LOW);
          }
        }  
        else{
          error+=1;
          b.AddError();
          digitalWrite(42,LOW);
          digitalWrite(46,LOW);
          digitalWrite(40,LOW);
        }
    } 
  }

void Simon::Error2(int err){
    int pin_flash=40; // rouge
    while (err==2) {
      to_flash(pin_flash);
      Led_ON();
      if ( (digitalRead(46)==HIGH) and pin_flash==40 ){ // condition si le rouge clignote 
        pin_flash=42;
        to_flash(pin_flash);
      
        if ( (digitalRead(40)==HIGH) and pin_flash==42 ){ // condition si le bleu clignote 
            pin_flash=46;
            to_flash(pin_flash);
    
            if ( (digitalRead(44)==HIGH) and pin_flash==46 ){ // condition si le vert clignote 
              pin_flash=44;
              to_flash(pin_flash);
          
              if ( (digitalRead(42)==HIGH) and pin_flash==44 ) // condition si le jaune clignote 
                digitalWrite(48,HIGH); //Mission réussie
              else{
                b.AddError();
        }
            }
            else
              b.AddError();
          }
          else
            b.AddError();
        }
        else
          b.AddError();     
    }
}

  void Simon::Test_error(int err){
    if (err==1)
      Error1(err);
      
    else
      if(err==2)
        Error2(err);
  }

  void Simon:: Is_OK(){
    
    int pin_flash=40; // rouge
    int error=0;
    while(error<3){
      to_flash(pin_flash);
      Led_ON();
      if ( (digitalRead(42)==HIGH) and pin_flash==40 ){ // condition si le rouge clignote 
        pin_flash=42;
        to_flash(pin_flash);
        if ( (digitalRead(40)==HIGH) and pin_flash==42 ){ // condition si le bleu clignote 
            pin_flash=46;
            to_flash(pin_flash);
    
            if ( (digitalRead(44)==HIGH) and pin_flash==46 ){ // condition si le vert clignote 
              pin_flash=44;
              to_flash(pin_flash);
          
              if ( (digitalRead(46)==HIGH) and pin_flash==44 ) // condition si le jaune clignote 
                digitalWrite(48,HIGH); //Mission réussie
              else{
                error+=1;
                Test_error(error);
              }  
            }
            else{
                error+=1;
                Test_error(error);
              }
          }
          else{
                error+=1;
                Test_error(error);
              }
        }
        else{
                error+=1;
                Test_error(error);
              }
     }
  }

 
  
    Simon:: ~Simon(){

    } // destructeur