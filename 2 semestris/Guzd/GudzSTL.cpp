#include <windows.h>
#include<iostream>
#include<list>

using namespace std;
#pragma execution_character_set( "utf-8" )

/* *********************************************************
Toms Gerbaševskis, tg25032

G13. Uzrakstīt funkciju, kas saraksta n-to elementu iznīcina un tā vietā ievieto to elementu,
kura numurs glabājās n-tajā elementā.
Darbība jāveic, pārkabinot saites, nevis pārkopējot elementu vērtības.

Programma izveidota: 22.02.2026.
********************************************************* */

/*
Funkcija changeNElem(ll, n) -
nomaina stl bibliotēkas saraksta n elementu ar aizvietojuma elementu,
kur aizvietojuma elements ir stl saraksta elements pēc kārtas m,
kurš iegūts no n elementa datiem.
*/
void changeNElem(list<int>& ll, int n);

int main(){
    SetConsoleOutputCP( 65001 );
    list<int> ll = {1,8,4,6,5,3,2,11,9};


    int n = 0;
    int ok = 1;
    do{
        cout << "Pašreizējais saraksts: ";
        for (int n : ll){cout << n << " ";}
        cout << endl;

        do{
            cout << "Ievadiet n (kārtas skaitlis, kuru elementu izdzēsīs): ";
            cin >> n;
        }while(n < 1);

        changeNElem(ll, n);

        cout << "Izmainītais saraksts: ";
        for (int n : ll){cout << n << " ";}
        cout << endl;

        cout << "Vai turpināt (1) vai beigt (0)?\n";
        cin >> ok;

    }while(ok == 1);
}

void changeNElem(list<int>& ll, int n){ // n=2 num=8 m=11 {1,8,4,6,5,3,2,11,9} n =8 num=11 m =?
    auto num = next(ll.begin(), n-1); //iegust iteratoru uz nto skaitli
    if(*num > ll.size()){
        cout << "cipars kas atrodas n elementā ir lielāks par sarakstu" << endl;
        return;
    }

    int m = *next(ll.begin(), *num-1); //iegust aizvietojuma skaitli
    if(*num == m){ //elementu tikai izdzes ja n un m ir vienadi
        auto it = next(ll.begin(), n-1);
        ll.erase(it);
        return;
    }

    auto it2 = next(ll.begin(), *num-1); //izdzes originalo aizvietojuma skaitli
    ll.erase(it2);
    *num  = m;

}
