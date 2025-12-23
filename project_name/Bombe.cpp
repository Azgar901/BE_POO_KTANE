//
// Created by ulric on 12/18/2025.
//

#include "Bombe.hpp"
#include <Arduino.h>
#include <TM1637Display.h>

/////// Port Timer ////
#define CLK 2 // Port PWM 2
#define DIO 3 // Port PWM 3
//////////////////////////

/////// Port Diode ////
#define LED_err_1 22 // Port Digit 22
#define LED_err_2 24 // Port Digit 24
//////////////////////////

Bomb::Bomb(){
    SerialNumber=1234;
    Port = 'a';
    NumberOfBatteries = 4;
    Timer=300;

    // initialize the LED pin as an output:
    
    pinMode(LED_err_1, OUTPUT);
    pinMode(LED_err_2, OUTPUT);
}

extern TM1637Display display(CLK, DIO);

void Bomb::AddError(){
    Error++;
    Update=1;
}

void Bomb::AddTimer() {
    display.clear();
}

void Bomb::Verify() {
    if ( Update == 1) {
        Update = 0;
        Print_Error( Error); // On affiche Err 1 ou Err 2
        Allume_LED_Error();
    }
}


void Bomb::Print_Error(int e) {
    display.clear();

    if (e==1){
        const uint8_t SEG_Err[] = {
            SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,           // E
            SEG_E | SEG_G,                                   // r
            SEG_E | SEG_G,                                   // r
            SEG_C | SEG_B                                    // 1
        };
        display.setBrightness(0x0f);
        display.setSegments(SEG_Err);
    }
    if (e==2){
        const uint8_t SEG_Err[] = {
             SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,           // E
             SEG_E | SEG_G,                                   // r
             SEG_E | SEG_G,                                   // r
             SEG_A | SEG_B | SEG_D | SEG_E | SEG_G            // 2
	    };
        display.setBrightness(0x0f);
        display.setSegments(SEG_Err);
    }
    
}

void Bomb::Allume_LED_Error(){
    if (digitalRead(LED_err_1)==HIGH)    // Si la LED 1 est allume on allume la deuxieme
        digitalWrite(LED_err_2, HIGH);
    if(digitalRead(LED_err_1)==LOW)      // Si la LED 1 est eteinte on l'allume
        digitalWrite(LED_err_1, HIGH);
}
