#include<iostream>

using namespace std;

/* *********************************************************
Toms Gerbaševskis, tg25032

G13. Uzrakstīt funkciju, kas saraksta n-to elementu iznīcina un tā vietā ievieto to elementu,
kura numurs glabājās n-tajā elementā.
Darbība jāveic, pārkabinot saites, nevis pārkopējot elementu vērtības.

Programma izveidota: 22.02.2026.
********************************************************* */
struct node {
    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};

void printList(node* first);
void deleteList(node* first);


void changeNElem(node*& first, int n);


int main(){

    int arr[]={1,8,4,6,5,3,2,7,9};
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
        prevN = Nelem;
        Nelem = Nelem->next;
    }
    if(Nelem == nullptr){
        cout << "Šāds n elements nav saistītajā sarakstā" << endl;
        return;
    }

    num = Nelem->data;

    for(int i = 1; i < num; i++){ // iegūst aizvietojuma elementu m
        prevM = m;
        m = m->next;
    }
    if(m == nullptr){
        cout << "Elements ar šo kārtas skaitli nav saistītajā sarakstā" << endl;
        return;
    }

    if(m == Nelem){ // ja aizvietosanas elements vienads ar n elementu to tikai izdzes
        if(prevN != nullptr)
            prevN->next = Nelem->next;
        else
            first = Nelem->next;

        delete Nelem;
        return;
    }

    if(prevM != nullptr) prevM->next = m->next; //nomaina elementa pirms m saiti uz m saiti, lai to "iznemtu"
    else first = m->next;

    if(prevN != nullptr) prevN->next = m; // ievieto aizvietojuma elementu n vietā
    else first = m;

    m->next = Nelem->next; //nomaina atmiņas adresi aizvietojuma elementam, lai saraksts nebūtu pārtraukts
    delete Nelem;

}


