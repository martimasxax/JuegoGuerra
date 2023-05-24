#include "Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje(string pName, int pPosX, int pPosY, int pAtaque, int pDefensa, int pHp)
    : name(pName), posX(pPosX), posY(pPosY), ataque(pAtaque), defensa(pDefensa), vidas(pHp) {
    // Cuerpo del constructor
}

string Personaje::getName() {
    return name;
}

int Personaje::getPosX() {
    return posX;
}

int Personaje::getPosY() {
    return posY;
}

int Personaje::getAtaque() {
    return ataque;
}
int Personaje::getDefensa() {
    return defensa;
}

int Personaje::getHp() {
    return vidas;
}

void Personaje::setPosX(int x) {
    posX = x;
}
void Personaje::setPosY(int y) {
    posY = y;
}
void Personaje::setAtaque(int ata) {
    ataque = ata;
}
void Personaje::setDefensa(int def) {
    defensa = def;
}
void Personaje::setHp(int hp) {
    vidas = hp;
}

int Personaje::enemyAttack(int daño) {
    if (rand() % 5 == 0) {
        daño = 1 + (rand() % 200);
    }
    else {
        cout << "El enemigo a fallado el ataque";
        return 0;

    }
}


bool Personaje::isAlive() {
    return vidas > 0;
}
void Personaje::printAllStats() {
    std::cout << "La vida de "<< getName()<<" es " << getHp() << std::endl;
    std::cout << "El ataque fisico  es " << getAtaque() << std::endl;
    std::cout << "La defensa es " << getDefensa() << std::endl;
}

