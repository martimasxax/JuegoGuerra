#include "EnemigoFinal.h"
#include <iostream>

EnemigoFinal::EnemigoFinal(std::string pName, int pPosX, int pPosY, int pAttack, int pDefense, int pHp, int pFireAttack, int pFrozenAttack)
    : Personaje(pName, pPosX, pPosY, pAttack, pDefense, pHp), fireAttack(pFireAttack), frozenAttack(pFrozenAttack)
{
}

bool EnemigoFinal::getFireAttack() {
    return fireAttack;
}

int EnemigoFinal::getFrozenAttack() {
    return frozenAttack;
}

void EnemigoFinal::setFireAttack(int pFireAttack) {
    fireAttack = pFireAttack;
}

void EnemigoFinal::setFrozenAttack(int pFrozenAttack) {
    frozenAttack = pFrozenAttack;
}

void EnemigoFinal::printAllStatsFinal() {
    std::cout << "El nombre del enemigo final es " << getName() << std::endl;
    std::cout << "La vida del enemigo final es " << getHp() << std::endl;
    std::cout << "El ataque fisico del enemigo final es " << getAtaque() << std::endl;
    std::cout << "La defensa del enemigo final es " << getDefensa() << std::endl;
    std::cout << "El ataque de fuego del enemigo final es " << getFireAttack() << std::endl;
    std::cout << "El ataque de hielo del enemigo final es " << getFrozenAttack() << std::endl;
}
