#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // Para getch()
#include <windows.h> // Para clear()
#include <mmsystem.h> // Para sleep()
#include <string>
#include "EnemigoFinal.h"
#include "Personaje.h"

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 5;
const char VACIO = '_';
const char JUGADOR = 'J';
const char ENEMIGO = 'E';
const char ENEMIGOFINAL = 'F';
const int NUM_ENEMIGOS = 3;
const int BONIFICACION = 50;

void imprimirTablero(char tablero[FILAS][COLUMNAS], Personaje& personaje) {
    system("cls"); // Limpiar la consola antes de imprimir el tablero
    tablero[personaje.getPosY()][personaje.getPosX()] = JUGADOR;
    for (int fila = 0; fila < FILAS; fila++) {
        for (int columna = 0; columna < COLUMNAS; columna++) {
            cout << tablero[fila][columna] << "\t";
        }
        cout << endl;
    }
}
void inicio() {
    cout << "¡Bienvenido al juego de Guerra!" << endl << endl;
    cout << "En este emocionante juego, te convertirás en un valiente jugador que se aventura en un campo de batalla lleno de desafíos." << endl;
    cout << "Tu objetivo es llegar a la guarida del enemigo final y enfrentarte a él en una batalla épica." << endl << endl;
    cout << "Antes de comenzar, elige tu nombre joven Aventurero:" << endl;
}
string elegirNombre() {
    string nombre;
    cin >> nombre;
    Sleep(500);
    return nombre;
}
void gameOver() {
    cout << "el enemigo te ha derrotado\n";
    Sleep(1000);
    system("cls");
    cout << "  _____      ___       ___  ___   _____" << endl;
    Sleep(100);
    cout << " / ___ |    /   |     /   |/   | |  ___|" << endl;
    Sleep(100);
    cout << "| |        / /| |    / /|   /| | | |__" << endl;
    Sleep(100);
    cout << "| |  _    / ___ |   / / |__/ | | |  __|" << endl;
    Sleep(100);
    cout << "| |_| |  / /  | |  / /       | | | |___" << endl;
    Sleep(100);
    cout << "\_____/ /_/   |_| /_/        |_| |_____|" << endl;
    Sleep(100);
    cout << " _____   _     _   _____   _____" << endl;
    Sleep(100);
    cout << "/  _  \ | |   / / |  ___| |  _  \ " << endl;
    Sleep(100);
    cout << "| | | | | |  / /  | |__   | |_| |" << endl;
    Sleep(100);
    cout << "| | | | | | / /   |  __|  |  _  /" << endl;
    Sleep(100);
    cout << "| |_| | | |/ /    | |___  | | \ \ " << endl;
    Sleep(100);
    cout << "\_____/ |___/     |_____| |_|  \_\ " << endl;
    Sleep(100);
    cout << endl << endl;
    Sleep(10000);
    system("pause");
}
void winner(Personaje jugador) {
    system("cls");
    cout << jugador.getName()  + " has derrotado a los enemigos\n";
    Sleep(1000);
    /*Intro*/
    Beep(330, 100); Sleep(100);
    Beep(330, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(330, 100); Sleep(300);
    Beep(392, 100); Sleep(700);
    Beep(196, 100); Sleep(700);
    Beep(196, 100); Sleep(125);
    Beep(262, 100); Sleep(125);
    Beep(330, 100); Sleep(125);
    Beep(392, 100); Sleep(125);
    Beep(523, 100); Sleep(125);
    Beep(660, 100); Sleep(125);
    Beep(784, 100); Sleep(575);
    Beep(660, 100); Sleep(575);
    Beep(207, 100); Sleep(125);
    Beep(262, 100); Sleep(125);
    Beep(311, 100); Sleep(125);
    Beep(415, 100); Sleep(125);
    Beep(523, 100); Sleep(125);
    Beep(622, 100); Sleep(125);
    Beep(830, 100); Sleep(575);
    Beep(622, 100); Sleep(575);
    Beep(233, 100); Sleep(125);
    Beep(294, 100); Sleep(125);
    Beep(349, 100); Sleep(125);
    Beep(466, 100); Sleep(125);
    Beep(587, 100); Sleep(125);
    Beep(698, 100); Sleep(125);
    Beep(932, 100); Sleep(575);
    Beep(932, 100); Sleep(125);
    Beep(932, 100); Sleep(125);
    Beep(932, 100); Sleep(125);
    Beep(1046, 675);
    cout << "G"; Sleep(500);
    cout << "R"; Sleep(500);
    cout << "A"; Sleep(500);
    cout << "C"; Sleep(500);
    cout << "I"; Sleep(500);
    cout << "A"; Sleep(500);
    cout << "S"; Sleep(500);
    cout << " "; Sleep(500);
    cout << "P"; Sleep(500);
    cout << "O"; Sleep(500);
    cout << "R"; Sleep(500);
    cout << " "; Sleep(500);
    cout << "J"; Sleep(500);
    cout << "U"; Sleep(500);
    cout << "G"; Sleep(500);
    cout << "A"; Sleep(500);
    cout << "R"; Sleep(500);

    
    Sleep(10000);
    system("pause");

}
void elegirDificultad(Personaje& jugador) {
    cout << "1. Fácil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. Difícil" << endl << endl;
    int dificultad;
    cout << "Ingresa el número correspondiente a la dificultad: ";
    cin >> dificultad;

    // Configurar la dificultad seleccionada
    switch (dificultad) {
    case 1: // Fácil
        jugador.setAtaque(jugador.getAtaque() * 5);
        jugador.setDefensa(jugador.getDefensa() * 5);
        jugador.setHp(jugador.getHp() * 5);
        break;
    case 2: // Medio
        jugador.setAtaque(jugador.getAtaque() * 2);
        jugador.setDefensa(jugador.getDefensa() * 2);
        jugador.setHp(jugador.getHp() * 2);
        break;
    case 3: // Difícil
        break;
    default:
        cout << "Dificultad inválida. Seleccionando dificultad media por defecto." << endl;
        break;
    }
}
int enemyAttack(){
    int dano;
    if (rand() % 2 == 0) {
    dano = 1;
    return dano;
    }
    else {
        cout << "El enemigo a fallado el ataque" << endl;
    return 0;

}
}
int danoEnemigo(Personaje& enemigo) {
    int dano=enemigo.getAtaque();
    dano = dano * enemyAttack();
    return dano;

}
int elegirAtaque() {
    cout << "Tienes 4 opciones, que haces?" << endl;
    Sleep(1000);
    cout << "[1] Ataque Físico - Hace daño físico al rival." << endl;
    Sleep(1000);
    cout << "[2] Concentración mística - Mejora tu concentración y augmenta tu daño" << endl;
    Sleep(1000);
    cout << "[3] Armadura - Mejora tu armadura y baja tu ratio defensa (eso hara que los ataques rivales te afecten menos)" << endl;
    Sleep(1000);
    cout << "[4] Huir - Intenta escapar de la batalla. Hay Probabilidad de que no puedas" << endl;
    Sleep(1000);
    cout << "Puedes elegir una opción ingresando el número correspondiente." << endl;
    Sleep(1000);


    int eleccion;
    cin >> eleccion;
    return eleccion;
}
bool ataqueJugador(Personaje& personaje, Personaje& enemigo) {
    int eleccion = elegirAtaque();
    int vidaE = enemigo.getHp();
    int armadura = 1;
    int ataque = personaje.getAtaque();
    switch (eleccion) {

    case 1:
        //ataque
        vidaE -= (personaje.getAtaque() * enemigo.getDefensa() / 2);
        enemigo.setHp(vidaE);
        return true;
        break;
    case 2:
        //subir ataque
        ataque = ataque * 1.5;
        personaje.setAtaque(ataque);
        cout << "Tu ataque ahora es de " << ataque << " puntos" << endl;
        return true;
        break;
    case 3:
        //armadura

        if (rand() % 5 == 0) {
            armadura = armadura * 0.5;
        }
        else {
            cout << "Has fallado la armadura" << endl;

        }
        armadura = personaje.getDefensa() * armadura;


        personaje.setDefensa(armadura);
        cout << "Tu defensa ahora es de " << (armadura) << " puntos" << endl;
        return true;
        break;
    case 4:
        if (rand() % 5 == 0) {
            cout << "Has fallado el intento de huida" << endl;
            return true;
            break;
        }
        else {
            return false;
            cout << "Huyes sin problemas" << endl;
            break;
        }
    default:
        cout << "Opción inválida. Por favor, elige nuevamente." << endl;
        break;
    }
    
    
}
int ataqueAleatorio() {
    int num = rand() % 3;
    if (num == 0) {
        return 3;
    }
    else if (num == 1/3) {
        return 2;
    }
    else {
        return 1;

    }
}
void batallaEnemigoF(Personaje& personaje, EnemigoFinal& enemigo) {
    system("cls");
    cout<< "Pelearas contra el enemigo más temido de toda las tierras cercanas"<< endl;
    while (personaje.isAlive() && enemigo.isAlive()) {
        cout << "Tienes 4 opciones, que haces?" << endl;
        Sleep(1000);
        cout << "[1] Ataque Físico - Hace daño físico al rival." << endl;
        Sleep(1000);
        cout << "[2] Concentración mística - Mejora tu concentración y tu daño" << endl;
        Sleep(1000);
        cout << "[3] Armadura - Mejora tu armadura y baja tu ratio defensa (eso hara que los ataques rivales te afecten menos)" << endl;
        Sleep(1000);
        cout << "[4] Poción de Vida" << endl;
        Sleep(1000);
        cout << "Puedes elegir una opción ingresando el número correspondiente." << endl;
        Sleep(1000);


        int eleccion;
        cin >> eleccion;
        int vidaE = enemigo.getHp();
        int armadura = 1;
        int vida = personaje.getHp();
        int ataque = personaje.getAtaque();
        switch (eleccion) {

        case 1:
            //ataque
            vidaE -= (personaje.getAtaque() * enemigo.getDefensa() / 2);
            enemigo.setHp(vidaE);
            break;
        case 2:
            //subir ataque
            ataque = ataque * 1.5;
            personaje.setAtaque(ataque);
            cout << "Tu ataque ahora es de " << ataque << " puntos" << endl;
            break;
        case 3:
            //armadura

            if (rand() % 5 == 0) {
                armadura = armadura*0.75;
            }
            else {
                cout << "Has fallado la armadura";

            }
            armadura = personaje.getDefensa() * armadura;


            personaje.setDefensa(armadura);
            cout << "Tu defensa ahora es de " << (armadura) << " puntos" << endl;

            break;
        case 4:
            vida += BONIFICACION;
            cout << "Tu vida ahora es de " << (vida) << " puntos" << endl;
        default:
            cout << "Opción inválida. Por favor, elige nuevamente." << endl;
            break;
        }
        enemigo.printAllStats();
        Sleep(500);
        int vidaJ = personaje.getHp();
        int dano = enemigo.getAtaque();
        switch (ataqueAleatorio()) {
        case 1:
            
            dano = dano * enemyAttack();
            cout << "El " << enemigo.getName() << " te hace "<<dano<< " puntos de daño";
            vidaJ -= dano;
            personaje.setHp(vidaJ);
            break;
        case 2:
            vidaJ -= (enemigo.getFireAttack() * personaje.getDefensa() / 2);
            cout << "El " << enemigo.getName() << " te hace " << (enemigo.getFireAttack() * personaje.getDefensa() / 2) << " puntos de daño";
            cout << "El "<< enemigo.getName()<<" aumenta su daño de Fuego cada vez que lo usa ";
                enemigo.setFireAttack(enemigo.getFireAttack() * 1.5);
            break;
        case 3:
            vidaJ -= (enemigo.getFrozenAttack() * personaje.getDefensa() / 2);
            cout << "El " << enemigo.getName() << " te hace " << (enemigo.getFrozenAttack() * personaje.getDefensa() / 2) << " puntos de daño";
            cout << "El " << enemigo.getName() << " augmenta su defensa gracias al hielo cada vez que lo usa ";
                enemigo.setDefensa(enemigo.getDefensa() * 0.75);
            break;
        }
        personaje.printAllStats();
        Sleep(500);
    }
    return;
}
void comprobarMovimiento(char tablero[FILAS][COLUMNAS], Personaje& personaje, int nuevaPosX, int nuevaPosY, Personaje* enemigos, int numEnemigos, EnemigoFinal& enemigoF) {
    int posX = personaje.getPosX();
    int posY = personaje.getPosY();

    if (tablero[nuevaPosY][nuevaPosX] == VACIO) {
        // Borrar la casilla anterior del jugador
        tablero[posY][posX] = VACIO;
        tablero[nuevaPosY][nuevaPosX] = JUGADOR;
        personaje.setPosX(nuevaPosX);
        personaje.setPosY(nuevaPosY);
    }
    else if (tablero[nuevaPosY][nuevaPosX] == ENEMIGO) {
        // Buscar el enemigo en base a su posición en el tablero
        int i;
        for (i = 0; i < numEnemigos; i++) {
            if (enemigos[i].getPosX() == nuevaPosX && enemigos[i].getPosY() == nuevaPosY) {
                break;
            }
        }
        // Verificar si se encontró al enemigo
        if (i < numEnemigos) {
            Sleep(1000);
            system("cls");
            // Realizar la batalla con el enemigo
            while (personaje.isAlive() && enemigos[i].isAlive()) {
                
                cout << "La batalla contra " << enemigos[i].getName() << " va comenzar" << endl;
                Sleep(1000);
                if (ataqueJugador(personaje, enemigos[i]) == true) {
                    enemigos[i].printAllStats();
                    Sleep(500);
                    int vidaJ = personaje.getHp();
                    vidaJ -= danoEnemigo(enemigos[i]);
                    cout << "El " << enemigos[i].getName() << " te hace " << danoEnemigo(enemigos[i]) << " puntos de daño";
                    personaje.setHp(vidaJ);
                    personaje.printAllStats();
                    Sleep(500);
                }
                else {
                    return;
                }
            }

            if (!enemigos[i].isAlive()) {
                // El enemigo ha sido derrotado
                cout << "Has derrotado a " << enemigos[i].getName() << " enhorabuena joven guerrero" << endl;
                cout << "Gracias a tu valentia te otorgo "<<BONIFICACION<< "puuntos de vida de bonificación" << endl;
                tablero[posY][posX] = VACIO;
                tablero[nuevaPosY][nuevaPosX] = JUGADOR;
                personaje.setPosX(nuevaPosX);
                personaje.setPosY(nuevaPosY);
                personaje.setHp(personaje.getHp() + BONIFICACION);

            }
        }
    }


    else if (tablero[nuevaPosY][nuevaPosX] == ENEMIGOFINAL) {
        // Realizar la batalla con el enemigo final
        batallaEnemigoF(personaje, enemigoF);

    }
}
void moverJugador(char tablero[FILAS][COLUMNAS], Personaje& personaje, Personaje* enemigos, int numEnemigos, EnemigoFinal& enemigoF) {
    // Obtener la posición actual del jugador
    
    char movimiento;
   
    cout << "Ingresa una dirección de movimiento (w/a/s/d): ";
    //cin >> movimiento;
    movimiento = _getch();
    int posX = personaje.getPosX();
    int posY = personaje.getPosY();
    int nuevaPosX = posX;  // Inicializar con la posición actual del jugador
    int nuevaPosY = posY;  // Inicializar con la posición actual del jugador

    switch (movimiento) {
    case 'w': // Arriba
        if (posY > 0) {
            nuevaPosY = posY - 1;
        }
        else {
            cout << "No puedes salirte del mapa en esa dirección. Inténtalo de nuevo." << endl;
            Sleep(3000);
        }
        break;
    case 'a': // Izquierda
        if (posX > 0) {
            nuevaPosX = posX - 1;
        }
        else {
            cout << "No puedes salirte del mapa en esa dirección. Inténtalo de nuevo." << endl;
            Sleep(3000);
        }
        break;
    case 's': // Abajo
        if (posY < FILAS - 1) {
            nuevaPosY = posY + 1;
        }
        else {
            cout << "No puedes salirte del mapa en esa dirección. Inténtalo de nuevo." << endl;
            Sleep(3000);
        }
        break;
    case 'd': // Derecha
        if (posX < COLUMNAS - 1) {
            nuevaPosX = posX + 1;
        }
        else {
            cout << "No puedes salirte del mapa en esa dirección. Inténtalo de nuevo." << endl;
            Sleep(3000);
        }
        break;
    default:
        cout << "Movimiento inválido. Inténtalo de nuevo." << endl;
        Sleep(3000);
        break;
    }
    comprobarMovimiento(tablero, personaje, nuevaPosX, nuevaPosY,enemigos,NUM_ENEMIGOS,enemigoF);
}
void jugarTablero(Personaje& jugador) {
    char tablero[FILAS][COLUMNAS];
    // Inicializar el tablero vacío
    for (int fila = 0; fila < FILAS; fila++) {
        for (int columna = 0; columna < COLUMNAS; columna++) {
            tablero[fila][columna] = VACIO;
        }
    }

    // Inicializar Enemigos
    Personaje enemigo[NUM_ENEMIGOS] = {
        Personaje("Fantasma del Bosque", 0, 0, 10, 2, 50),
        Personaje("Ogro Negro", 0, 0, 5, 1, 100),
        Personaje("Mago Oscuro", 0, 0, 30, 4, 30),
    };

    // Inicializar EnemigosFinal
    EnemigoFinal enemigoFinal("Rey del Bosque Oscuro", COLUMNAS - 1, FILAS - 1, 50, 2, 1000, 100, 100);

    // Inicializar cada enemigo en una fila aleatoria del tablero
    for (int i = 0; i < NUM_ENEMIGOS; i++) {
        int fila = i + 1; // Generar un número aleatorio entre 0 y FILAS-1
        int columna = rand() % COLUMNAS; // Generar un número aleatorio entre 0 y COLUMNAS-1
        enemigo[i].setPosX(columna);
        enemigo[i].setPosY(fila);
    }

    // Inicializar la posición del jugador + Enemigos + Enemigo final
    tablero[jugador.getPosY()][jugador.getPosX()] = JUGADOR;
    tablero[enemigoFinal.getPosY()][enemigoFinal.getPosX()] = ENEMIGOFINAL;
    for (int i = 0; i < NUM_ENEMIGOS; i++) {
        tablero[enemigo[i].getPosY()][enemigo[i].getPosX()] = ENEMIGO;
    }


    while (jugador.isAlive() || enemigoFinal.isAlive()) {
        imprimirTablero(tablero, jugador);
        moverJugador(tablero, jugador, enemigo, NUM_ENEMIGOS, enemigoFinal);
        if (jugador.isAlive() == false) {
            gameOver();
        }
        else if (enemigoFinal.isAlive() == false) {
            winner(jugador);
        }
    }
}
int main() {
    // Configurar la semilla para generar números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));
    inicio();
    //inicializar JUgador
    string NombreJugador = elegirNombre();
    //string NombreJugador = " ";
    Personaje jugador(NombreJugador, 2, 0, 20, 2, 100);
    elegirDificultad(jugador);
    cout << endl;
    cout << "Comienza la aventura. ¡Buena suerte!" << endl;
    system("cls"); // Limpiar la consola
    jugarTablero(jugador);
}
