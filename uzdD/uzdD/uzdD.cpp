#include<iostream>
#include "uzdD.h"

using namespace std;

Nqueue::Nqueue(){
    queueCount = 0;
}

Nqueue::~Nqueue(){
    if(queueCount != 0){
        cout << "Tiek likvidēts objekts: " << this << ", tā elementu skaits: " << queueCount << endl;
    }

    cout << "Tiek likvidēts objekts: " << this << endl;
}

void Nqueue::enqueue(int x){  //ievieto jaunu beigās
    if(queueCount == 5){
        cout << "Rinda ir pilna, noņemt elementu pirms ievietot jaunu!" << endl;
        return;
    }

    numValue[queueCount] = x;
    queueCount++;
}

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

int Nqueue::Count(){
    return queueCount;
}

bool Nqueue::isEmpty(){
    if(queueCount == 0)
        return true;
    return false;
}
