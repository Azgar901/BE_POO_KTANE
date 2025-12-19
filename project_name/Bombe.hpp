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
    Bomb();

    void AddError();

    ~Bomb();
};

#endif //BE_POO_KTANE_BOMBE_HPP