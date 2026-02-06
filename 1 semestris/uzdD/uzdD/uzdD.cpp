#include<iostream>
#include "uzdD.h"

using namespace std;

/*

Izveidot programmu valodā C++, izmantojot objektorientētās programmēšanas līdzekļus un strukturējot programmu vismaz trīs failos.
Klases hederi obligāti novietot atsevišķā hedera failā (program.h).
Visas metodes realizēt ārpus hedera faila – speciālā C++ failā (program.cpp).
Funkcija main ievietojama vēl citā C++ failā (main.cpp). Klases dati pēc noklusēšanas ir slēpti (private),
bet metodes atklātas (public). Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne,
kāda tika prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt). Citas prasības sk.
Laboratorijas darbu noteikumos.

D6. Izveidot klasi "Skaitļu rinda" - Nqueue (queue, pa vienu pusi ieliek, pa otru izņem!),
kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā pieci un rindas elementu skaits.
Klasei izveidot šādas metodes: (1) konstruktors, (2) destruktors,
kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī rinda nav tukša),
(3) metode "Ielikt" - enqueue, kas pievieno rindai elementu, ja tā nav pilna, (4) metode "Izņemt" - dequeue,
kas izņem no rindas elementu un atgriež tā vērtību, (5) metode "CikElementu" - count,
kas atgriež elementu skaitu rindā, (6) metode "IrTukša" - isEmpty, kas noskaidro,
vai rinda ir tukša. Pirms uzdevuma veikšanas precīzi noskaidrot, ko nozīmē jēdziens rinda (queue) kā datu struktūra.

*/

/*
Nqueue::Nqueue();

Konstruktors Nqueue() -
izveidojot objekta Nqueue instanci, piešķir queueCount (rindas pašreizējā garuma mainīgajam) mainīgajam 0

*/
Nqueue::Nqueue(){
    queueCount = 0;
}

/*
Nqueue::~Nqueue();

Destruktors ~Nqueue() -
tiek izprintēts, ka tiek iznīcināta objekta instance

*/

Nqueue::~Nqueue(){
    if(queueCount != 0){
        cout << "Tiek likvidēts objekts: " << this << ", tā elementu skaits: " << queueCount << endl;
    }

    cout << "Tiek likvidēts objekts: " << this << endl;
}

/*
void Nqueue::enqueue(int x);

Metode enqueue(x) -
pievieno objekta Nqueue instances skaitļu masīvam numValue parametrā iegūto skaitli x un palielina rindas pašreizējā garuma mainīgo par 1,
ja rinda ir pilna, par to paziņo tiek paziņots un iziets no metodes
*/

void Nqueue::enqueue(int x){  //ievieto jaunu beigās
    if(queueCount == 5){
        cout << "Rinda ir pilna, noņemt elementu pirms ievietot jaunu!" << endl;
        return;
    }

    cout << "Skaitlis " << x << " pievienots!" << endl;

    numValue[queueCount] = x;
    queueCount++;
}

/*
int Nqueue::dequeue();

Metode dequeue() -
noņem masīva 1. vērtību pārbīdot visas masīva vērtības uz leju pa 1 un atgriež tā vērtību, kā arī pamazina pašreizējas rindas garuma mainīgo par 1
*/

int Nqueue::dequeue(){ // nonem pirmo elementu, kā queue datu struktūra
    int removedValue;

    if(queueCount == 0){
        cout << "Rinda ir tukša, pievienot elementu pirms var izņemt!" << endl;
        return 0;
    }

    removedValue = numValue[0];

    for(int i = 1; i < queueCount; i++){
        numValue[i-1] = numValue[i];
    }

    cout << "Noņemts 1. elements" << endl;

    queueCount--;
    return removedValue;
}

/*
int Nqueue::Count();

Metode Count() -
atgriež privāto mainīgo queueCount(masīva pašreizējais lielums)
*/

int Nqueue::Count(){
    return queueCount;
}

/*
bool Nqueue::isEmpty();

Metode isEmpty() -
atgriež vērtību patiess, ja masīva pašreizējais lielums ir 0
*/

bool Nqueue::isEmpty(){
    if(queueCount == 0)
        return true;
    return false;
}
