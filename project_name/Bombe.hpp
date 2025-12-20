//
// Created by ulric on 12/18/2025.
//

#ifndef BE_POO_KTANE_BOMBE_HPP
#define BE_POO_KTANE_BOMBE_HPP
#include "ModuleBase.hpp"


class Bomb {
    protected:
    int SerialNumber;
    int NumberOfBatteries;
    char Port;
    int Timer;
    int Error=0;

    public:
    int Update=0;

    Bomb();

    void AddError();

    void Verify();

    void Allume_LED_Error();

    void Print_Error(int err);

};

#endif //BE_POO_KTANE_BOMBE_HPP