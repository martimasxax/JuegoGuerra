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
    system("cls");
    cout << "  _____      ___       ___  ___   _____" << endl;
    cout << " / ___ |    /   |     /   |/   | |  ___|" << endl;
    cout << "| |        / /| |    / /|   /| | | |__" << endl;
    cout << "| |  _    / ___ |   / / |__/ | | |  __|" << endl;
    cout << "| |_| |  / /  | |  / /       | | | |___" << endl;
    cout << "\_____/ /_/   |_| /_/        |_| |_____|" << endl;
    cout << " _____   _     _   _____   _____" << endl;
    cout << "/  _  \ | |   / / |  ___| |  _  \ " << endl;
    cout << "| | | | | |  / /  | |__   | |_| |" << endl;
    cout << "| | | | | | / /   |  __|  |  _  /" << endl;
    cout << "| |_| | | |/ /    | |___  | | \ \ " << endl;
    cout << "\_____/ |___/     |_____| |_|  \_\ " << endl;
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

void elegirDificultad() {
    cout << "1. Fácil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. Difícil" << endl << endl;
    int dificultad;
    cout << "Ingresa el número correspondiente a la dificultad: ";
    cin >> dificultad;

    // Configurar la dificultad seleccionada
    /* switch (dificultad) {
    case 1: // Fácil
        filas = 6;
        columnas = 5;
        break;
    case 2: // Medio
        filas = 8;
        columnas = 7;
        break;
    case 3: // Difícil
        filas = 10;
        columnas = 9;
        break;
    default:
        cout << "Dificultad inválida. Seleccionando dificultad media por defecto." << endl;
        break;
    }*/
}
int enemyAttack(){
    int dano;
    if (rand() % 5 == 0) {
    dano = 1 + (rand() % 200);
    return dano;
    }
    else {
        cout << "El enemigo a fallado el ataque";
        return 0;

}
}
int danoEnemigo(Personaje& enemigo) {
    int dano=enemigo.getAtaque();
    dano = dano * enemyAttack();
    return dano;

}
bool ataqueJugador(Personaje& personaje, Personaje& enemigo) {
    
    cout << "La batalla contra " << enemigo.getName() << "va comenzar";
    Sleep(1000);
    cout << "Tienes 4 opciones, que haces?" << endl;
    Sleep(1000);
    cout << "[1] Ataque Físico - Hace daño físico al rival." << endl;
    Sleep(1000);
    cout << "[2] Concentración mística - Mejora tu concentración y tu daño" << endl;
    Sleep(1000);
    cout << "[3] Armadura - Mejora tu armadura y sube tu defensa" << endl;
    Sleep(1000);
    cout << "[4] Huir - Intenta escapar de la batalla. Hay Probabilidad de que no puedas" << endl;
    Sleep(1000);
    cout << "Puedes elegir una opción ingresando el número correspondiente." << endl;
    Sleep(1000);


    int eleccion;
    int vidaE = enemigo.getHp();
    int armadura = 1;
    int ataque = personaje.getAtaque();
    cin >> eleccion;
    switch (eleccion) {

    case '1':
        //ataque
        vidaE -= (personaje.getAtaque() * enemigo.getDefensa() / 2);
        enemigo.setHp(vidaE);
        return true;
        break;
    case '2':
        //subir ataque
        ataque = ataque * 1.5;
        personaje.setAtaque(ataque);
        cout << "Tu defensa ahora es de " << ataque << " puntos";
        return true;
        break;
    case '3':
        //armadura

        if (rand() % 5 == 0) {
            armadura = 1 + (rand() % 200);
        }
        else {
            cout << "Has fallado la armadura";

        }
        armadura = personaje.getDefensa() * armadura;


        personaje.setDefensa(armadura);
        cout << "Tu defensa ahora es de " << (armadura) << " puntos";
        return true;
        break;
    case '4':
        if (rand() % 5 == 0) {
            cout << "Has fallado el intento de huida";
        }
        else {
            return false;

        }
    default:
        cout << "Opción inválida. Por favor, elige nuevamente." << endl;
        break;
    }
}

void batallaEnemigoF(Personaje& personaje, Personaje& enemigo) {
    cout<< "Pelearas contra el enemigo más temido de toda las tierras cercanas"<< endl;
    


}
void comprobarMovimiento(char tablero[FILAS][COLUMNAS], Personaje& personaje, int nuevaPosX, int nuevaPosY, Personaje* enemigos, int numEnemigos, EnemigoFinal& enemigoF) {
    int posX = personaje.getPosX();
    int posY = personaje.getPosY();
    // Verificar si la nueva posición está vacía
    if (tablero[nuevaPosY][nuevaPosX] == VACIO) {
        // Borrar la casilla anterior del jugador
        tablero[posY][posX] = VACIO;
        tablero[nuevaPosY][nuevaPosX] = JUGADOR;
        personaje.setPosX(nuevaPosX);
        personaje.setPosY(nuevaPosY);

    }else if (tablero[nuevaPosY][nuevaPosX] == ENEMIGO) {
        // Buscar el enemigo en base a su posición en el tablero
        int i;
        for (i = 0; i < NUM_ENEMIGOS; i++) {
            if (enemigos[i].getPosX() == nuevaPosX && enemigos[i].getPosY() == nuevaPosY) {
                break;
            }
        }
        // Verificar si se encontró al enemigo
        if (i < NUM_ENEMIGOS) {
            //empieza la batalla
            system("cls");
            while (enemigos[i].isAlive() == false || personaje.isAlive() == false) {
                
                ataqueJugador(personaje, enemigos[i]);
                int vidaJ=personaje.getHp();
                vidaJ-= danoEnemigo(enemigos[i]);
                personaje.setHp(vidaJ);
                enemigos[i].printAllStats();
                personaje.printAllStats();
                Sleep(1000);
                if (enemigos[i].isAlive() == false) {
                    // Borrar la casilla anterior del jugador
                    tablero[posY][posX] = VACIO;
                    tablero[nuevaPosY][nuevaPosX] = JUGADOR;
                    personaje.setPosX(nuevaPosX);
                    personaje.setPosY(nuevaPosY);
                }
                else {
                    return;
                }
            }
        }


    }
    else if (tablero[nuevaPosY][nuevaPosX] == ENEMIGOFINAL) {
        system("cls");
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
        Personaje("Enemigo 1", 0, 0, 1, 2, 10),
        Personaje("Enemigo 2", 0, 0, 2, 1, 10),
        Personaje("Enemigo 3", 0, 0, 1, 2, 10),
    };
    
    // Inicializar EnemigosFinal
    EnemigoFinal enemigoFinal("Enemigo Final", COLUMNAS - 1, FILAS - 1, 0, 0, 10,0,0);
    
    // Inicializar cada enemigo en una fila aleatoria del tablero
    for (int i = 0; i < NUM_ENEMIGOS; i++) {
        int fila = i + 1; // Generar un número aleatorio entre 0 y FILAS-1
        int columna = rand() % COLUMNAS; // Generar un número aleatorio entre 0 y COLUMNAS-1
        enemigo[i].setPosX(columna);
        enemigo[i].setPosY(fila);
    }
    //elegirDificultat();

    // Inicializar la posición del jugador + Enemigos + Enemigo final
    tablero[jugador.getPosY()][jugador.getPosX()] = JUGADOR;
    tablero[enemigoFinal.getPosY()][enemigoFinal.getPosX()] = ENEMIGOFINAL;
    for (int i = 0; i < NUM_ENEMIGOS; i++) {
        tablero[enemigo[i].getPosY()][enemigo[i].getPosX()] = ENEMIGO;
    }

    
    while (jugador.isAlive() || enemigoFinal.isAlive()) {
        imprimirTablero(tablero, jugador);
        moverJugador(tablero, jugador,enemigo,NUM_ENEMIGOS,enemigoFinal);
        //comprobarPosicion(tablero, jugador, enemigo, NUM_ENEMIGOS, enemigoFinal);
    }
    if (jugador.isAlive() == false) {
        gameOver();
    }else if(enemigoFinal.isAlive() == false) {
        winner(jugador);
    }
    }

int main() {
    // Configurar la semilla para generar números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));
    //inicio();
    //inicializar JUgador
    //string NombreJugador = elegirNombre();
    string NombreJugador = " ";
    Personaje jugador(NombreJugador, 2, 0, 3, 2, 10);
    cout << endl;
    cout << "Comienza la aventura. ¡Buena suerte!" << endl;
    system("cls"); // Limpiar la consola
    jugarTablero(jugador);
}
