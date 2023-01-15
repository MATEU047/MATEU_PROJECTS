// DosEnemigos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo1
string enemyName1 = "Creeper";
int creeperHP = 250;
bool CreeperIsAlive = true;

//Atributos del enemigo2
string enemyName2 = "Slime";
int slimeHP = 250;
bool SlimeIsAlive = true;

//Atributos hero
//string heroName; Eliminamos la variable global para crear la local
int heroHP = 700;
bool heroIsAlive = true;

//Ataques
int DamageGolpe = 30;
int DamageAscuas = 50;
int DamageRasengan = 100;

//LIMITE ATAQUES
int LimiteRasengan = 3;
int NumEnemy;
int enemyDamage;
int ataque;


string pedirNombreHero() {
    string heroName;
    cout << enemyName1 << " acaba de aparecer y tiene " << creeperHP << " puntos de vida\n";
    cout << enemyName2 << " acaba de aparecer y tiene " << slimeHP << " puntos de vida\n";

    cout << "como se llama el heroe? \n";
    cin >> heroName;

    return heroName;
}
int seleccionarEnemigo() {
    cout << "Elige al que atacar:\n";
    cout << "[1]: " << enemyName1 << " \n";
    cout << "[2]: " << enemyName2 << " \n";
    cin >> NumEnemy;

    return NumEnemy;
}

void heroDeadvsEnemies(string& enemyNames) {
    if (heroHP <= 0) {

        heroHP = 0;
        cout << "El " << enemyNames << " Te ha matado\n";
        heroIsAlive = false;
    }
    else {

        cout << "El enemigo " << enemyNames << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";
    }

}
void switchataque(int& enemiesHP, string& enemyNames) {
    switch (ataque) {

    case 1:

        enemiesHP = enemiesHP - DamageGolpe;
        cout << "Le has hecho " << DamageGolpe << " puntos de danyo\n";
        cout << "A " << enemyNames << " le quedan " << enemiesHP << " de vida\n";

        break;

    case 2:

        enemiesHP = enemiesHP - DamageAscuas;
        cout << "Le has hecho " << DamageAscuas << " puntos de danyo\n";
        cout << "A " << enemyNames << " le quedan " << enemiesHP << " de vida\n";

        break;

    case 3:
        LimiteRasengan = LimiteRasengan - 1;
        if (LimiteRasengan <= 0) {
            DamageRasengan = 0;
            cout << " Te quedaste sin usos de Rasengan \n";
            break;
        }
        enemiesHP = enemiesHP - DamageRasengan;
        cout << " Te quedan " << LimiteRasengan << " usos de Rasengan \n";
        cout << "Le has hecho " << DamageRasengan << " puntos de danyo\n";
        cout << " A " << enemyNames << " le quedan " << enemiesHP << " de vida\n";

        break;

    }
}

void batallaCreeper() {
    if (NumEnemy == 1)
    {

        cout << "Escoge tu ataque: \n";
        cout << "[1] Golpe (30 de danyo)\n";
        cout << "[2] Ascuas (50 de danyo)\n";
        cout << "[3] Rasengan (100 de damage)\n";
        cin >> ataque;

        switchataque(creeperHP, enemyName1);

        //MUERTE DE CREEPER O NO
        if (creeperHP <= 0) {
            CreeperIsAlive = false;
            cout << "Te acabas de cargar al " << enemyName1 << "\n";

            //SLIME TE ATACA
            enemyDamage = rand() % 100 + 10;
            heroHP = heroHP - enemyDamage;

            heroDeadvsEnemies(enemyName2);
        }
        else if (creeperHP > 0) {

            //SI CREEPER VIVE QUE TE HAGA DAMAGE
            enemyDamage = rand() % 100 + 10;
            heroHP = heroHP - enemyDamage;
            cout << "El enemigo " << enemyName1 << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida \n";

            
            if (heroHP > 0) {

                //SI HEROE VIVE QUE EL SLIME HAGA DAMAGE
                enemyDamage = rand() % 100 + 10;
                heroHP = heroHP - enemyDamage;

                heroDeadvsEnemies(enemyName2);
            }
        }
    }
} 
void batallaSlime() {
    if (NumEnemy == 2) {

        ataque;
        cout << "Escoge tu ataque: \n";
        cout << "[1] Golpe (30 de danyo)\n";
        cout << "[2] Ascuas (50 de danyo)\n";
        cout << "[3] Rasengan (100 de damage)\n";
        cin >> ataque;

        switchataque(slimeHP, enemyName2);

        //MUERTE DEL SLIME O NO
        if (slimeHP <= 0) {

            SlimeIsAlive = false;
            cout << "Te acabas de cargar al " << enemyName2 << "\n";

            //EL CREEPER ATACA
            enemyDamage = rand() % 100 + 10;
            heroHP = heroHP - enemyDamage;

            heroDeadvsEnemies(enemyName1);
        }

        // SI EL SLIME VIVE
        else if (slimeHP > 0) {

            enemyDamage = rand() % 100 + 10;
            heroHP = heroHP - enemyDamage;
            cout << "El enemigo " << enemyName2 << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << " puntos de vida\n";

            // MUERTE DEL HEROE O NO
            if (heroHP > 0) {

                enemyDamage = rand() % 100 + 10;
                heroHP = heroHP - enemyDamage;

                heroDeadvsEnemies(enemyName1);
            }
        }

    }
}

void switchAtaque(int& enemiesHP, string& Names) {
    if (enemiesHP > 0) {

        ataque;
        cout << "Solo queda " << Names << " con vida.\n";
        cout << "Escoge tu ataque: \n";
        cout << "[1] Golpe (50 de danyo)\n";
        cout << "[2] Ascuas (50 de danyo)\n";
        cout << "[3] Rasengan (100 de damage)\n";
        cin >> ataque;

        switch (ataque)
        {
        case 1:

            enemiesHP = enemiesHP - DamageGolpe;
            cout << "Le has hecho " << DamageGolpe << " puntos de danyo\n";
            cout << "A " << Names << " le quedan " << enemiesHP << " de vida\n";

            break;

        case 2:

            enemiesHP = enemiesHP - DamageAscuas;
            cout << "Le has hecho " << DamageAscuas << " puntos de danyo\n";
            cout << "A " << Names << " le quedan " << enemiesHP << " de vida\n";

            break;

        case 3:

            LimiteRasengan = LimiteRasengan - 1;
            if (LimiteRasengan <= 0) {
                DamageRasengan = 0;
                cout << " Te quedaste sin usos de Rasengan \n";
                break;
            }
            enemiesHP = enemiesHP - DamageRasengan;
            cout << "Le has hecho " << DamageRasengan << " puntos de danyo\n";
            cout << "A " << Names << " le quedan " << enemiesHP << " de vida\n";

            break;
        }

    }
} //ns porq me da error
void batallaSoloUnoVivo(int& enemiesHP, string& enemiesNames, bool& enemyAlive) {
    if (enemiesHP > 0) {

        switchAtaque(enemiesHP, enemiesNames);
    }

    if (enemiesHP <= 0) {

        enemyAlive = false;
    }
    else if (enemiesHP >= 0) {

            //EL SLIME ATACA PORQ ESTA VIVO
            enemyDamage = rand() % 100 + 10;
            heroHP = heroHP - enemyDamage;

            heroDeadvsEnemies(enemiesNames);
    }
}

bool estadoHero() {
    if (CreeperIsAlive == true && heroIsAlive == false && SlimeIsAlive == true) {

        heroHP = 0;
        cout << "Estas muerto crack.\n";
        return heroIsAlive = false;
    }
    else {
        return heroIsAlive = true;
    }
}
bool Ganas() {
    if (CreeperIsAlive == false && heroIsAlive == true && SlimeIsAlive == false) {
        cout << "Te acabas de fundir a los dos enemigos.\n";
        return false;
    }
    else {
        return true;
    }
}

int main() {
    string heroName = pedirNombreHero();

    while (CreeperIsAlive == true && heroIsAlive == true && SlimeIsAlive == true) {

        seleccionarEnemigo();
        batallaCreeper();
        batallaSlime();
    }   
    while (CreeperIsAlive == false && heroIsAlive == true && SlimeIsAlive == true) {

        batallaSoloUnoVivo(slimeHP, enemyName2, SlimeIsAlive);  
    }
    while (CreeperIsAlive == true && heroIsAlive == true && SlimeIsAlive == false) {

        batallaSoloUnoVivo(creeperHP, enemyName1, CreeperIsAlive);       
    }
    Ganas();
    estadoHero();
}
    




