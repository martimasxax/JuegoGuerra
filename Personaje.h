#pragma once

#include <string>

class Personaje {
private:
    std::string name;
    int posX;
    int posY;
    int ataque;
    int defensa;
    int vidas;

public:
    Personaje(std::string pName, int pPosX, int pPosY, int pAtaque, int pDefensa, int pHp);

    std::string getName();
    int getPosX();
    int getPosY();
    int getAtaque();
    
    int getHp();
    int getDefensa();
   

    void setPosX(int x);
    void setPosY(int y);
    void setAtaque(int ataque);
    void setDefensa(int defensa);
    void setHp(int vidas);
    int enemyAttack(int daño);
    bool isAlive();
    void printAllStats();
};
