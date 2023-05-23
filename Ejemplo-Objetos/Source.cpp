#include <iostream>
#include <windows.h>
#include "Enemigo.h"
#include "EnemigoFinal.h"
#include <string>
#include <conio.h>
#include <chrono>
#pragma comment(lib, "winmm.lib")

using namespace std;

void escribirLetraPorLetra(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        cout << texto[i];
        Sleep(10);
    }
    cout << endl;
}


void bienvenida() {
    string texto = " _________                  __  .__.__  .__           __________\n"
        "\\_   ___ \\_____    _______/  |_|__|  | |  |   ____   \\______   \\ ______  _  ________ ___________\n"
        "/    \\  \\/\\__  \\  /  ___/\\   __\\  |  | |  |  /  _ \\   |    |  _//  _ \\ \\/ \\/ /  ___// __ \\_  __ \\\n"
        "\\     \\____/ __ \\_\\___ \\  |  | |  |  |_|  |_(  <_> )  |    |   (  <_> )     /\\___ \\\\  ___/|  | \\/\n"
        " \\______  (____  /____  > |__| |__|____/____/\\____/   |______  /\\____/ \\/\\_//____  >\\___  >__|\n"
        "        \\/     \\/     \\/                                     \\/                  \\/     \\/";

    string textoIntro = " Estas listo para empezar una gran aventura en el Reino Koopa??";
    escribirLetraPorLetra(textoIntro);
    system("pause");
    system("cls");
    PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC);
    escribirLetraPorLetra(texto);
    Sleep(4000);
}

void miniBatalla(Personaje& heroe, Personaje& enemigo) {
    while (heroe.getHp() > 0 && enemigo.getHp() > 0) {
        // Mostrar opciones de ataque al héroe
        cout << "¡Es el turno del heroe!" << endl;
        cout << "Elige tu ataque:" << endl;
        cout << "1. Ataque normal" << endl;
        cout << "2. Ataque especial" << endl;

        int opcion;
        cin >> opcion;

        // Realizar el ataque basado en la opción seleccionada
        int ataqueHeroe;
        switch (opcion) {
        case 1:
            ataqueHeroe = heroe.getAttack();
            break;
        case 2:
            heroe.setAttack(100);
            ataqueHeroe = heroe.getAttack();
            break;
        default:
            cout << "Opcion invalida. Se realizara un ataque normal." << endl;
            ataqueHeroe = heroe.getAttack();
            break;
        }

        // Reducir la salud del enemigo
        enemigo.setHp(enemigo.getHp() - ataqueHeroe);

        // Turno del enemigo
        int ataqueEnemigo = enemigo.getAttack();
        heroe.setHp(heroe.getHp() - ataqueEnemigo);

        // Mostrar los resultados de cada turno
        cout << "El heroe inflige " << ataqueHeroe << " puntos de dano al enemigo." << endl;
        cout << "El enemigo tiene " << enemigo.getHp() << " puntos de vida restantes." << endl;
        cout << endl;
        cout << "¡Es el turno del enemigo!" << endl;
        cout << "El enemigo inflige " << ataqueEnemigo << " puntos de dano al heroe." << endl;
        cout << "El héroe tiene " << heroe.getHp() << " puntos de vida restantes." << endl;
        cout << endl;

        // Pausa para mostrar los resultados
        system("pause");
        system("cls");
    }

    // Verificar el resultado de la batalla
    if (heroe.getHp() <= 0) {
        cout << "¡El heroe ha sido derrotado! Game Over." << endl;
    }
    else {
        cout << "¡El heroe ha derrotado al enemigo! Victoria." << endl;
    }
}

void miniBatallaConBowser(Personaje& heroe, EnemigoFinal& bowser) {
    // Mostrar mensaje de encuentro con Bowser
    cout << "¡Has encontrado al jefe final, Bowser!" << endl;
    cout << "¡Prepárate para la batalla final!" << endl;
    cout << endl;

    // Mostrar información de Bowser
    bowser.printAllStats();

    // Iniciar la batalla con Bowser
    while (heroe.getHp() > 0 && bowser.getHp() > 0) {
        // Mostrar opciones de ataque al héroe
        cout << "¡Es el turno del heroe!" << endl;
        cout << "Elige tu ataque:" << endl;
        cout << "   1. Ataque normal" << endl;
        cout << "   2. Ataque especial" << endl;
        cout << endl;

        int opcion;
        cin >> opcion;

        // Realizar el ataque basado en la opción seleccionada
        int ataqueHeroe;
        switch (opcion) {
        case 1:
            ataqueHeroe = heroe.getAttack();
            break;
        case 2:
            heroe.setAttack(100);
            ataqueHeroe = heroe.getAttack();
            break;
        default:
            cout << "Opcion invalida. Se realizara un ataque normal." << endl;
            ataqueHeroe = heroe.getAttack();
            break;
        }

        // Reducir la salud de Bowser
        bowser.setHp(bowser.getHp() - ataqueHeroe);

        // Turno de Bowser
        int ataqueBowser = bowser.getAttack();
        heroe.setHp(heroe.getHp() - ataqueBowser);

        // Mostrar los resultados de cada turno
        cout << "El heroe hace " << ataqueHeroe << " puntos de dano a Bowser." << endl;
        cout << "Bowser tiene " << bowser.getHp() << " puntos de vida restantes." << endl;
        cout << endl;
        cout << "¡Es el turno de Bowser!" << endl;
        cout << "Bowser hace " << ataqueBowser << " puntos de dano al heroe." << endl;
        cout << "El heroe tiene " << heroe.getHp() << " puntos de vida restantes." << endl;
        cout << endl;

        // Pausa para mostrar los resultados
        system("pause");
        system("cls");
    }

    // Verificar el resultado de la batalla
    if (heroe.getHp() <= 0) {
        cout << endl;
        PlaySound(TEXT("mueres.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(4000);
        PlaySound(TEXT("gameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "  El héroe ha sido derrotado! Game Over." << endl;
        string loser = R"(
            ██████   █████  ███    ███ ███████     
            ██       ██   ██ ████  ████ ██          
            ██   ███ ███████ ██ ████ ██ █████       
            ██    ██ ██   ██ ██  ██  ██ ██          
            ██████  ██   ██ ██      ██ ███████     
                                        
                                        
             ██████  ██    ██ ███████ ██████        
            ██    ██ ██    ██ ██      ██   ██       
            ██    ██ ██    ██ █████   ██████        
            ██    ██  ██  ██  ██      ██   ██       
             ██████    ████   ███████ ██   ██  
            )";
        escribirLetraPorLetra(loser);
        Sleep(6000);

    }
    else {
        PlaySound(TEXT("bowserCae.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(2000); // Pausa de 2 segundos
        PlaySound(TEXT("victoria.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "   ¡El heroe ha derrotado a Bowser! ¡Victoria!" << endl;
        string winner = R"(
            ██    ██  ██████  ██    ██     
             ██  ██  ██    ██ ██    ██     
              ████   ██    ██ ██    ██     
               ██    ██    ██ ██    ██     
               ██     ██████   ██████      
                               
                               
             ██     ██ ██ ███    ██         
             ██     ██ ██ ████   ██         
             ██  █  ██ ██ ██ ██  ██         
             ██ ███ ██ ██ ██  ██ ██         
              ███ ███  ██ ██   ████         
             )";
        escribirLetraPorLetra(winner);
        Sleep(7000);
    }
}


int main() {
    srand(time(0));

    bienvenida();

    int arrX[4];
    int arrY[4];

    // Inicializar los arreglos arrX y arrY
    for (int i = 0; i < 4; i++) {
        arrX[i] = rand() % 5;
        arrY[i] = rand() % 3 + 1;
    }

    int posicionHeroeX = rand() % 5;
    int posicionHeroeY = 0;

    int posicionBowserX = rand() % 5; // El jefe final se coloca en una posición aleatoria
    int posicionBowserY = 4; // El jefe final siempre se coloca en la última fila

    string tablero[5][5];

    Personaje AndreuTorrentbo(50, "Andres", 50, posicionHeroeX, posicionHeroeY);
    Personaje goomba1(100, "Goomba 1", 50, arrX[0], arrY[0]);
    Personaje goomba2(100, "Goomba 2", 50, arrX[1], arrY[1]);
    Personaje goomba3(100, "Goomba 3", 50, arrX[2], arrY[2]);
    Personaje goomba4(100, "Goomba 4", 50, arrX[3], arrY[3]);
    EnemigoFinal kingBowser(500, "Bowser", 100, posicionBowserX, posicionBowserY, 150, 1000);

    int key;
    bool continuarJuego = true;

    while (continuarJuego) {
        system("cls");

        // Construir y mostrar el tablero
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == posicionHeroeY && j == posicionHeroeX) {
                    tablero[i][j] = "| \x1B[34mH\x1B[0m |";  // Letra H en azul
                }
                else if (i == posicionBowserY && j == posicionBowserX) {
                    tablero[i][j] = "| B |";
                }
                else if (i == arrY[0] && j == arrX[0]) {
                    tablero[i][j] = "| \x1B[31mE\x1B[0m |";  // Letra E en1 rojo
                }
                else if (i == arrY[1] && j == arrX[1]) {
                    tablero[i][j] = "| \x1B[31mE\x1B[0m |";  // Letra E en rojo
                }
                else if (i == arrY[2] && j == arrX[2]) {
                    tablero[i][j] = "| \x1B[31mE\x1B[0m |";  // Letra E en rojo
                }
                else if (i == arrY[3] && j == arrX[3]) {
                    tablero[i][j] = "| \x1B[31mE\x1B[0m |";  // Letra E en rojo
                }
                else {
                    tablero[i][j] = "|   |";
                }

                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }

        key = _getch();

        int nuevaPosX = posicionHeroeX;
        int nuevaPosY = posicionHeroeY;

        switch (key) {
        case 75: // Flecha izquierda
            nuevaPosX = posicionHeroeX - 1;
            break;
        case 77: // Flecha derecha
            nuevaPosX = posicionHeroeX + 1;
            break;
        case 72: // Flecha arriba
            nuevaPosY = posicionHeroeY - 1;
            break;
        case 80: // Flecha abajo
            nuevaPosY = posicionHeroeY + 1;
            break;
        default:
            break;
        }

        // Verificar si la nueva posición coincide con el jefe final
        if (nuevaPosX == posicionBowserX && nuevaPosY == posicionBowserY) {
            // Lógica para la batalla con el jefe final...
            miniBatallaConBowser(AndreuTorrentbo, kingBowser);
            continuarJuego = false;

        }
        
        else if (nuevaPosX >= 0 && nuevaPosX < 5 && nuevaPosY >= 0 && nuevaPosY < 5) {
            // Actualizar la posición del héroe
            posicionHeroeX = nuevaPosX;
            posicionHeroeY = nuevaPosY;

            // Verificar si la nueva posición coincide con un enemigo
            if ((nuevaPosX == arrX[0] && nuevaPosY == arrY[0]) ||
                (nuevaPosX == arrX[1] && nuevaPosY == arrY[1]) ||
                (nuevaPosX == arrX[2] && nuevaPosY == arrY[2]) ||
                (nuevaPosX == arrX[3] && nuevaPosY == arrY[3])) {
                cout << "¡Has encontrado a un enemigo! ¡Preparate para la batalla!" << endl;
                // Lógica para batalla
                if (nuevaPosX == arrX[0] && nuevaPosY == arrY[0]) {
                    miniBatalla(AndreuTorrentbo, goomba1);
                }
                else if (nuevaPosX == arrX[1] && nuevaPosY == arrY[1]) {
                    miniBatalla(AndreuTorrentbo, goomba2);
                }
                else if (nuevaPosX == arrX[2] && nuevaPosY == arrY[2]) {
                    miniBatalla(AndreuTorrentbo, goomba3);
                }
                else if (nuevaPosX == arrX[3] && nuevaPosY == arrY[3]) {
                    miniBatalla(AndreuTorrentbo, goomba4);
                }
            }
        }
    }

    return 0;
}

//goomba1.printStatus();
//goomba2.printStatus();
//goomba3.printStatus();
//goomba4.printStatus();


//PROBAMOS LOS MÉTODOS PROPIOS
//kingBowser.printAllStats

