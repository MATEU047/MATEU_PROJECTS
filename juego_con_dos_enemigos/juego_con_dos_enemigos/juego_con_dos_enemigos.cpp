// juego_con_dos_enemigos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP = 150;
string enemyName = "Creeper";
bool enemyIsAlive = true;
int enemyDamage = rand() % 100 + 1;

//Atributos del enemigo2
int enemyHP = 200;
string enemyName = "Slime";
bool enemy2IsAlive = true;
int enemyDamage2 = rand() % 100 + 1;


//Atributos de héroe
string heroName;
int heroDamage;
int heroHP = 500;
bool heroIsAlive = true;

int main()
{

    cout << " Un " << enemyName << " acaba de aparecer y tiene " << enemyHP << " puntos de vida\n";
    cout << " Como se llama el heroe?\n";
    cin >> heroName;
    cout << " El nombre del heroe es " << heroName << " \n";


    while (enemyIsAlive == true && heroIsAlive == true) {

        cout << " cuanto damage quieres hacerle al " << enemyName << " \n";
        cin >> heroDamage;
        enemyHP = enemyHP - heroDamage;

        if (enemyHP <= 0)
        {
            cout << " Te acabas de cargar al enemigo " << enemyName << "\n";
            enemyIsAlive = false;
        }

        else {

            cout << " Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida\n";
        }

        if (enemyIsAlive == true) {
            //ATACO AL HÉROE
            enemyDamage = rand() % 100 + 1;

            heroHP = heroHP - enemyDamage;

            if (heroHP <= 0) {

                cout << " El enemigo " << enemyName << " te ha matado \n";
                heroIsAlive = false;
            }
            else {
                cout << " El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << "  puntos de vida\n";
            }

        }
    }


}



