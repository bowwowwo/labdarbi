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
    int data; node *next;
    node(int val) : data(val), next(nullptr) {}
};

void printList(node* first);
void deleteList(node* first);
void changeNElem(node* first, int n);


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

    printList(first);
    changeNElem(first, 2);
    printList(first);
    deleteList(first);
}

void printList(node* first){
    node *p = first;
    while(p){
        cout << p->data << " ";
        p=p->next;
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

void changeNElem(node* first, int n){

}
