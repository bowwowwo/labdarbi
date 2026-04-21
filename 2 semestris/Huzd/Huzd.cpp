#include<windows.h>
#include<iostream>
#include<cstring>
#include<fstream>


using namespace std;
#pragma execution_character_set( "utf-8" )

/*
H13. Doti divi bināri faili f1 un f2, kuru komponentes ir ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus).
Failu komponentes sakārtotas atslēgu pieaugšanas secībā. Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3  tā,
lai arī f3 komponentes būtu atslēgu pieaugšanas secībā (failos  nedrīkst parādīties divas komponentes ar vienādu atslēgu vērtību).
Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.
*/

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

void writeBinFile(string f);
void readBinFile(string f);
void combineFiles();

int main(){
    SetConsoleOutputCP( 65001 );
    writeBinFile("f1");
    readBinFile("f1");
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
