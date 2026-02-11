#include<iostream>
#include<fstream>
#include<cctype>

using namespace std;

/* ********************************************
Toms Gerbaševskis, tg25032

F13. Dots teksta fails f. Uzrakstīt programmu,
kura izveido failu f1, kurā, salīdzinot ar failu f,
visi sastaptie cipari būtu nomainīti ar nākošo ciparu pēc moduļa 10,
t.i., 0->1, 1->2, 2->3, …, 9->0.

Programma izveidota: 08.02.2026.
********************************************** */

string convertLine(string l);
/*
Funkcija convertLine(l) -
atgriež augsta līmeņa simbolu virkni, kur tiek pārveidots 1 simbols par ciparu,
ja tas ir derīgs cipars, un tad tiek izmainīts ar funkciju modNum(int n),
pēc tam izmainīts esošais simbols ar modificēto
*/

int modNum(int n);
/*
Funkcija modNum(n) -
atgriež veselu skaitli, kas ir parametrā iedots vesels skaitlis,
kas nomainīts ar nākošo ciparu pēc moduļa 10
*/

int main(){

string fName = "f.txt";
string line;

ifstream fin(fName);
ofstream fout("f1.txt");

if(!fin){
    cout << "nevar atvērt failu " << fName << endl;
    return 1;
}

if (!fout) {
    cout << "nevar izveidot failu \"f1.txt\"" << endl;
    return 1;
}

while (getline(fin, line)) {
    fout << convertLine(line) << endl;
}

cout << "\"f1.txt\" atrodas pašreizējā direktorijā" << endl;
fin.close();
fout.close();

}

string convertLine(string l){
    int n;
    for(char &c : l){
        if(isdigit(c)){ // vai (c >= '0' && c <= '9')
            n = modNum(c - '0');
            c = n + '0';
        }
    }
    return l;
}

int modNum(int n){
    return (n+1)%10;
}

// Testa plāns un rezultāti (lasīti pa līnijai)
// ╔═════════════════════════════╦══════════════════════════════╦════════════════════════════╗
// ║ Ievades dati(failā "f.txt") ║ Izvades dati(failā "f1.txt") ║ Programmas vēlamā reakcija ║
// ╠═════════════════════════════╬══════════════════════════════╬════════════════════════════╣
// ║ 1 2 3 4 5 6 7 8 9 10        ║ 2 3 4 5 6 7 8 9 0 21         ║ 2 3 4 5 6 7 8 9 0 21       ║
// ║ 1234567890ccb               ║ 2345678901ccb                ║ 2345678901ccb              ║
// ║ 0912 8888 6713              ║ 1023 9999 7824               ║ 1023 9999 7824             ║
// ║ bumbieris5                  ║ bumbieris6                   ║ bumbieris6                 ║
// ╚═════════════════════════════╩══════════════════════════════╩════════════════════════════╝

