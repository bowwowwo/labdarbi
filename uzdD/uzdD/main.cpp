#include <cstdio>
#include <windows.h>
#include <iostream>
#include "uzdD.h"

#pragma execution_character_set( "utf-8" )

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

using namespace std;

int main()
{

SetConsoleOutputCP( 65001 );

int ok;

/*
Nqueue *queue;

cout << queue.isEmpty() << endl; // ir tukša
queue.enqueue(1);
cout << queue.isEmpty() << endl; // nav tukša

queue.enqueue(2);
queue.enqueue(3);
queue.enqueue(4);
queue.enqueue(5);
queue.enqueue(6);

cout << queue.Count() << endl;
cout << queue.dequeue() << endl; // izvada 1. elementa vērtību
cout << queue.Count() << endl;
*/

Nqueue *queue1;
queue1 = new Nqueue;

int input;
int queueInput;

do{



    cout << "Darbības" << endl << "1 - pievienot rindā skaitli" << endl << "2 - noņemt rindas skaitli" << endl << "3 - rindas lielums" << endl << "4 - uzzināt vai rinda ir tukša" << endl;
    cin >> input;

    do{
        switch(input){
            case 1:
                cout << "Kādu skaitli pievienot?" << endl;
                cin >> queueInput;
                queue1->enqueue(queueInput);
                break;
            case 2:
                cout << "Tika noņemts skaitlis: " << queue1->dequeue() << endl;
                break;
            case 3:
                cout << "Rindas lielums: " << queue1->Count() << endl;
                break;
            case 4:
                cout << ((queue1->isEmpty()) ? "Rinda ir tukša" : "Rinda nav tukša") << endl;
        }
    }while(input > 4 && input < 1);



    cout << " Vai turpināt (1) vai beigt (0)?" << endl;
    cin >> ok;
}while(ok == 1);

delete queue1;
}


/*


╔═══════════════════════════════╦═══════════════════════════════════╦═══════════════════════════╦═══════════════════════════════════╦═════════════════════════════════════════════════════════╗
║ Programmas izpildes iterācija ║  Lietotāja izvēlētā darbība (1-4) ║ Papildus lietotāja ievade ║        Gaidāmais rezultāts        ║                        Rezultāts                        ║
╠═══════════════════════════════╬═══════════════════════════════════╬═══════════════════════════╬═══════════════════════════════════╬═════════════════════════════════════════════════════════╣
║ 1.                            ║ "3 - rindas lielums"              ║                           ║ 0                                 ║ "Rindas lielums: 0"                                     ║
║ 2.                            ║ 4 - uzzināt vai rinda ir tukša    ║                           ║ "Rinda ir tukša"                  ║ "Rinda ir tukša"                                        ║
║ 3.                            ║ "1 - pievienot rindā skaitli"     ║                        90 ║ "Skaitlis pievienots!"            ║ "Skaitlis pievienots!"                                  ║
║ 4.                            ║ "1 - pievienot rindā skaitli"     ║                        91 ║ "Skaitlis pievienots!"            ║ "Skaitlis pievienots!"                                  ║
║ 5.                            ║ "3 - rindas lielums"              ║                           ║  2                                ║ Rindas lielums: 2                                       ║
║ 6.                            ║ "1 - pievienot rindā skaitli"     ║                        92 ║ "Skaitlis pievienots!"            ║ "Skaitlis pievienots!"                                  ║
║ 7.                            ║ "1 - pievienot rindā skaitli"     ║                        93 ║ "Skaitlis pievienots!"            ║ "Skaitlis pievienots!"                                  ║
║ 8.                            ║ "1 - pievienot rindā skaitli"     ║                        94 ║ "Skaitlis pievienots!"            ║ "Skaitlis pievienots!"                                  ║
║ 9.                            ║ "1 - pievienot rindā skaitli"     ║                        94 ║ Rinda ir pilna                    ║ "Rinda ir pilna, noņemt elementu pirms ievietot jaunu!" ║
║ 10.                           ║ "2 - noņemt rindas skaitli"       ║                           ║ noņemts 1. elements, vērtība = 90 ║ "Noņemts 1. elements Tika noņemts skaitlis: 90"         ║
║ 11.                           ║ "3 - rindas lielums"              ║                           ║ 4                                 ║ Rindas lielums: 4                                       ║
║ 12.                           ║ "4 - uzzināt vai rinda ir tukša"  ║                           ║ "Rinda nav tukša"                 ║ "Rinda nav tukša"                                       ║
║ Izpildes beigas               ║                                   ║                           ║ Nostrādā destruktors              ║ Tiek likvidēts objekts: 0x1007ec0                       ║
╚═══════════════════════════════╩═══════════════════════════════════╩═══════════════════════════╩═══════════════════════════════════╩═════════════════════════════════════════════════════════╝




*/
