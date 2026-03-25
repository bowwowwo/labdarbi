#include<iostream>

using namespace std;

/* *********************************************************
Toms Gerbaševskis, tg25032

G13. Uzrakstīt funkciju, kas saraksta n-to elementu iznīcina un tā vietā ievieto to elementu,
kura numurs glabājās n-tajā elementā.
Darbība jāveic, pārkabinot saites, nevis pārkopējot elementu vērtības.

Programma izveidota: 22.02.2026.
********************************************************* */
/*
Datu struktūra node -
node ir 1 vienvirziena saistīta saraksta mezgls
*/
struct node {
    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};

/*
Funkcijas printList(first) un deleteList(first) -
iegūtas no powerpoint prezentācijas:
"Dinamiskas datu struktūras Saistītais saraksts" Uldis Straujums, 2026
*/
void printList(node* first);
void deleteList(node* first);

/*
Funkcija changeNElem(first, n) -
nomaina saistīta saraksta n elementu ar aizvietojuma elementu,
kur aizvietojuma elements ir saistīta saraksta elements pēc kārtas m,
kurš iegūts no n elementa datiem.
*/
void changeNElem(node*& first, int n);


int main(){

    int arr[]={1,8,4,6,5,3,2,11,9};
    node *first=nullptr,*last=nullptr;
    for(int i=0;i<9;i++) {
        node *p=new node(arr[i]);
        if (first == nullptr) {
            first=last=p;
        }
        else {
            last->next=p;
            last = p;
        }
    }

    int n;
    int ok = 1;
    do{
        cout << "Pašreizējais saraksts: "; printList(first);
        cout << "Ievadiet n (kārtas skaitlis, kuru elementu izdzēsīs): ";

        cin >> n;
        changeNElem(first, n);

        cout << "Izmainītais saraksts: "; printList(first);

        cout << "Vai turpināt (1) vai beigt (0)?\n";
        cin >> ok;

    }while(ok == 1);

    deleteList(first);
}

void printList(node* first){
    node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteList(node* first){
    node* p;
        while(first){
            p = first->next;
            delete first;
            first = p;
        }
}

void changeNElem(node*& first, int n){
    node* Nelem = first;
    node* prevN = nullptr;
    int num;
    node* m = first;
    node* prevM = nullptr;


    for(int i = 1; i < n; i++){ //iegūst n elementu
        if(Nelem != nullptr){
            prevN = Nelem;
            Nelem = Nelem->next;
        }
        else break;
    }
    if(Nelem == nullptr){
        cout << "Šāds n elements nav saistītajā sarakstā" << endl;
        return;
    }

    num = Nelem->data;

    for(int i = 1; i < num; i++){ // iegūst aizvietojuma elementu m
        if(m != nullptr){
        prevM = m;
        m = m->next;
        }
        else break;
    }
    if(m == nullptr){
        cout << "Elements ar šo kārtas skaitli nav saistītajā sarakstā" << endl;
        return;
    }

    if(m == Nelem){ // ja aizvietosanas elements vienads ar n elementu to tikai izdzes
        if(prevN)
            prevN->next = Nelem->next;
        else
            first = Nelem->next;

        delete Nelem;
        return;
    }


    // ja m ir pirms n tā norādi nomaina uz iepriekšējā
    if (m == prevN) {
        prevN = prevM;
    }

    // izņem m elementu no sarakst  liekot iepriekšējai to izlaist
    if (prevM) prevM->next = m->next;
    else first = m->next;

    // ievieto m elementu n elementa vietā
    if (prevN) prevN->next = m;
    else first = m;

    m->next = Nelem->next;

    delete Nelem;
}



// Testa plāns un rezultāti
/*


╔══════════════════════╦══════════════╦═════════════════════════════════╦═══════════════════════════════════════════════════════╗
║ Sākotnējāis saraksts ║ Ievades dati ║ Saraksts pēc funkcijas izpildes ║ Gaidītie rezultāti sarakstam                          ║
╠══════════════════════╬══════════════╬═════════════════════════════════╬═══════════════════════════════════════════════════════╣
║   1 8 4 6 5 3 2 11 9 ║            7 ║                1 4 6 5 3 8 11 9 ║             1 4 6 5 3 8 11 9                          ║
║     1 4 6 5 3 8 11 9 ║            3 ║                  1 4 8 5 3 11 9 ║               1 4 8 5 3 11 9                          ║
║       1 4 8 5 3 11 9 ║            2 ║                    1 5 8 3 11 9 ║                 1 5 8 3 11 9                          ║
║   1 8 4 6 5 3 2 11 9 ║            8 ║              1 8 4 6 5 3 2 11 9 ║ Elements ar šo kārtas skaitli nav saistītajā sarakstā ║
╚══════════════════════╩══════════════╩═════════════════════════════════╩═══════════════════════════════════════════════════════╝

*/
