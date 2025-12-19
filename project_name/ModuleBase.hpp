//
// Created by ulric on 12/12/2025.
//

#ifndef BE_POO_KTANE_MODULEBASE_HPP
#define BE_POO_KTANE_MODULEBASE_HPP

class Bomb;

class ModuleBase {
    int led;
    Bomb * bombp; // Pointeur vers la bombe
    public:

     ModuleBase(Bomb* bomb);

    void Made_Error();


    ~ModuleBase(); // Destructeur de base
};
#endif //BE_POO_KTANE_MODULEBASE_HPP