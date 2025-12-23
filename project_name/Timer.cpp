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

volatile int interrupt_counter = 0;

Timer::Timer(Bomb * b) {
    MaxTime = b->Timer;

    display.setBrightness(0x0f);
    //Programmation de l'interruption toutes les 30ms
    noInterrupts();
    TCCR1A=0; // On active TIM 1
    TCCR1B=0;
    TCCR1B |= 0b00000101; // prescaler = 1024
    TIMSK1 |= 0b00000001; // on active l'interruption en overflow
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
    interrupt_counter++;
    if (interrupt_counter > 460){
        interrupt_counter = 0;
        MaxTime--;
        if (MaxTime >=0){
            int seconde;
            int minute;
            seconde = MaxTime%60;
            minute = MaxTime/60;
            display.clear();
            display.showNumberDecEx(seconde, (0x80 >> 1), false);
            display.showNumberDecEx(minute, (0x80 >> 1), false, 2);

            }
    }
}
