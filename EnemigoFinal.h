#pragma once
#include "Personaje.h"

class EnemigoFinal : public Personaje {
private:
    bool fireAttack;
    int frozenAttack;

public:
    EnemigoFinal(std::string pName, int pPosX, int pPosY, int pAttack, int pDefense, int pHp, int pFireAttack, int pFrozenAttack);

    bool getFireAttack();
    int getFrozenAttack();
    void setFireAttack(int pFireAttack);
    void setFrozenAttack(int pFrozenAttack);

    void printAllStatsFinal();
};

