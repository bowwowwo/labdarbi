#include<windows.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<map>


using namespace std;
#pragma execution_character_set( "utf-8" )

/* *****************************************
Toms Gerbaševskis, tg25032

H13. Doti divi bināri faili f1 un f2, kuru komponentes ir ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus).
Failu komponentes sakārtotas atslēgu pieaugšanas secībā. Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3  tā,
lai arī f3 komponentes būtu atslēgu pieaugšanas secībā (failos  nedrīkst parādīties divas komponentes ar vienādu atslēgu vērtību).
Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.

Programma izveidota: 20.04.2026.
***************************************** */

struct record{
    int key;
    char word[31];

    record(){
    key = 0;
    word[0] = '\0';
    }

    record(int val, char* val2){
        key = val;
        strcpy(word, val2);
        word[30] = '\0';
    }
};

/*
Funkcija writeBinFile(f) -
Funkcija ieraksta binārā failā ierakstus ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus).
*/

void writeBinFile(string f);
/*
Funkcija readBinFile(f) -
Funkcija nolasa binārā faila ierakstus,
ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus).
*/

void readBinFile(string f);

/*
Funkcija combineFiles(f, f1, f2) -
Funkcija izveido bināro failu f2.bin, tajā apvieno failus f un f1 failā tā,
lai arī f2 komponentes būtu atslēgu pieaugšanas secībā.
*/

void combineFiles(string f, string f1, string f2);

int main(){
    SetConsoleOutputCP( 65001 );
    writeBinFile("f1");
    readBinFile("f1");

    writeBinFile("f2");
    readBinFile("f2");

    combineFiles("f1", "f2", "f3");
    readBinFile("f3");
}

void writeBinFile(string f){
    int ok;
    string fname = f + ".bin";
    ofstream file(fname, ios::binary | ios::app);

    do{
        int k;
        char s[31];

        cout << "Ievadiet atslēgu(numurs) un vārdu(30 simbolus garu) failā \"" << fname  << "\""<< endl;
        cout << "Atslēga: ";
        cin >> k;
        cout << "Vārds: ";
        cin.ignore();
        while (1) {
            cin.getline(s, 31);
            if (!cin.fail()) break;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "simbolu virknei ir jābūt 30 simbolus garai" << endl;
        }

        record r = {k, s};

        file.write((char*)&r, sizeof(r));

        cout << "Vai vēlaties turpināt? (1 - jā)" << endl;
        cin >> ok;
    }while(ok == 1);


    file.close();
}

void readBinFile(string f){
    record r;
    string fname = f + ".bin";
    ifstream file(fname, ios::binary);

    if(!file){
        cout << "Failu nevarēja atvērt." << endl;
        return;
    }

    cout << "Ieraksti failā \"" << fname << "\":" << endl;

    while (file.read((char*)&r, sizeof(r))) {
        std::cout << "Atslega: " << r.key << ", vertiba: " << r.word << "\n";
    }

    file.close();
}

void combineFiles(string f, string f1, string f2){
    record r;
    string fname = f + ".bin", fname1 = f1 + ".bin", fname2 = f2 + ".bin";
    map<int, string> m;

    ifstream file(fname, ios::binary);
    ifstream file1(fname1, ios::binary);

    while (file.read((char*)&r, sizeof(r))) { //ievieto vardnica (ievietojot tiek sakartotas vertibas augosa seciba)
        m.insert({r.key, r.word});
    }

    while (file1.read((char*)&r, sizeof(r))) {
        m.insert({r.key, r.word});
    }

    file.close(); file1.close();

    ofstream file2(fname2, ios::binary);

    for (auto it = m.begin(); it != m.end(); ++it){ //ievieto faila
        string s = it->second;

        r.key = it->first;
        strcpy(r.word, s.c_str());

        file2.write((char*)&r, sizeof(r));
    }

    file2.close();
}

/* Testa rezultāti #$#$#$#$#$#$#$#$#$#$#$$#$#$#$##$#$#$#$#$#$#$#

╔══════════════════════════════╦════════════════════════════╦════════════════════════════════════════════════════════════╦══════════════════════════════╗
║        fails "f1.bin"        ║       fails "f2.bin"       ║  gaidītais "f3.bin" saturs                                 ║        fails "f3.bin"        ║
╠══════════════════════════════╬════════════════════════════╬════════════════════════════════════════════════════════════╬══════════════════════════════╣
║ Atslega: 2, vertiba: divi    ║ Atslega: 1, vertiba: viens ║ Atslega: 1, vertiba: viens                                 ║ Atslega: 1, vertiba: viens   ║
║ Atslega: 3, vertiba: septini ║ Atslega: 3, vertiba: tris  ║ Atslega: 2, vertiba: divi                                  ║ Atslega: 2, vertiba: divi    ║
║ Atslega: 4, vertiba: cetri   ║ Atslega: 5, vertiba: sesi  ║ Atslega: 3, vertiba: septini VAI Atslega: 3, vertiba: tris ║ Atslega: 3, vertiba: septini ║
║                              ║                            ║ Atslega: 4, vertiba: cetri                                 ║ Atslega: 4, vertiba: cetri   ║
║                              ║                            ║ Atslega: 5, vertiba: sesi                                  ║ Atslega: 5, vertiba: sesi    ║
╚══════════════════════════════╩════════════════════════════╩════════════════════════════════════════════════════════════╩══════════════════════════════╝

$$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$$#$#$#$##$#$#$#$#$#$#$# */
