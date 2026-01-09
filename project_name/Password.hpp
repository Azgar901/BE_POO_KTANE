//
// Created by ulric on 1/9/2026.
//

#ifndef BE_POO_KTANE_PASSWORD_HPP
#define BE_POO_KTANE_PASSWORD_HPP
#include "ModuleBase.hpp"
#include <Arduino.h>
#include <IRremote.h>


class Password : public ModuleBase {
    char PSWD [6]= { 'A','R','B','R','E'};
    int cursor=0;
    int Cursor0 = 0;
    int Cursor1 = 0;
    int Cursor2 = 0;
    int Cursor3 = 0;
    int Cursor4 = 0;

    const int TelePin = 11;
    IRrecv irrecv;

    unsigned long prev = millis();
    unsigned long now = millis();

    char UserCode[5][6] = {
        {'E','A','P','L','D','K'}, // Lettre 0
        {'R', 'A', 'I', 'M', 'O'}, // Lettre 1
        {'M', 'T', 'A', 'B', 'P'}, // Lettre 2
        {'V', 'E', 'L', 'T', 'R'}, // Lettre 3
        {'A', 'O', 'J', 'E', 'R'}  // Lettre 4
    };

    public:
    Password(Bomb *bomb);

    void init_Password();

    void Navigate(unsigned long code);

    void Put_letter(int cursor);
    void Check_Password();

    void Telecommand_check();

    ~Password();
};

#endif //BE_POO_KTANE_PASSWORD_HPP