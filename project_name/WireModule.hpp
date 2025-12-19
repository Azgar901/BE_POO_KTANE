//
// Created by ulric on 12/18/2025.
//

#ifndef BE_POO_KTANE_WIREMODULE_HPP
#define BE_POO_KTANE_WIREMODULE_HPP
#include "ModuleBase.hpp"

class Wire : public ModuleBase {
    public:

    Wire(Bomb*bomb);

    void Verify() {
        Made_Error();
    }

    ~Wire();
};

#endif //BE_POO_KTANE_WIREMODULE_HPP