//
// Created by ulric on 12/21/2025.
//

#include "Timer.hpp"
#include "Bombe.hpp"
#include "TM1637Display.h"
#include "Arduino.h"

/////// Port Timer ////
#define CLK 2 // Port PWM 2
#define DIO 3 // Port PWM 3
//////////////////////////

extern TM1637Display display;

// Mode CTC: interruption déclenchée exactement toutes les 1 seconde

Timer::Timer(Bomb * b) {
    MaxTime = b->Timer;

    display.setBrightness(0x0f);
    //Programmation de l'interruption toutes les 1s en mode CTC
    noInterrupts();
    TCCR1A = 0;           // Reset registre A
    TCCR1B = 0;           // Reset registre B
    TCNT1 = 0;            // Reset compteur
    OCR1A = 15624; // OCR1A = (16MHz / (prescaler * frequence)) - 1
    
    TCCR1B |= (1 << WGM12);   // Mode CTC (Clear Timer on Compare Match)
    TCCR1B |= (1 << CS12) | (1 << CS10);  // Prescaler = 1024
    TIMSK1 |= (1 << OCIE1A);  // Active l'interruption sur Compare Match A
    interrupts();
}

void Timer::begin() {
    int seconde;
    int minute;
    seconde = MaxTime%60;
    minute = MaxTime/60;
    display.clear();
    display.showNumberDecEx(seconde, (0x80 >> 1), false);
    display.showNumberDecEx(minute, (0x80 >> 1), false, 2);
    MaxTime--;
}

void Timer::update() {
    MaxTime--;
    if (MaxTime >= 0) {
        int seconde = MaxTime % 60;
        int minute = MaxTime / 60;
        display.clear();
        display.showNumberDecEx(seconde, (0x80 >> 1), false);
        display.showNumberDecEx(minute, (0x80 >> 1), false, 2);
    }
}
