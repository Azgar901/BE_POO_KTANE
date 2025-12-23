//
// Created by ulric on 12/21/2025.
//

#ifndef BE_POO_KTANE_TIMER_HPP
#define BE_POO_KTANE_TIMER_HPP
#include "Bombe.hpp"

class Timer {
    int MaxTime;

    public:
    Timer(Bomb * b);

    void begin();
    void update();
};

#endif //BE_POO_KTANE_TIMER_HPP