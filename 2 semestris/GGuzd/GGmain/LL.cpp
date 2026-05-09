#include<iostream>
#include"LL.h"

using namespace std;

void makeList(node *first){
    node* p, * last = NULL;
	int n;

    	do {
		cout << "Ievadiet skaitli, 0 lai beigtu:";
		cin >> n;

		if (cin.fail()) { //???
			throw - 1;
		}

		if (n == 0) {
			return;
		}

		p = new Elem;
		p->num = n;
		p->next = NULL;

		if (*first == NULL)
		{
			*first = last = p;
		}
		else {
			last->next = p;
			last = last->next;
		};
	} while (n != 0);
}

void printList(node *first)
{
    node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteList(node *first)
{
    node *p;
    while (first)
    {
        p = first->next;
        delete first;
        first = p;
    }
}

void changeNElem(node *&first, int n)
{
    node *Nelem = first;
    node *prevN = nullptr;
    int num;
    node *m = first;
    node *prevM = nullptr;

    for (int i = 1; i < n; i++)
    { // iegūst n elementu
        if (Nelem != nullptr)
        {
            prevN = Nelem;
            Nelem = Nelem->next;
        }
        else
            break;
    }
    if (Nelem == nullptr)
    {
        cout << "Šāds n elements nav saistītajā sarakstā" << endl;
        return;
    }

    num = Nelem->data;

    for (int i = 1; i < num; i++)
    { // iegūst aizvietojuma elementu
        if (m != nullptr)
        {
            prevM = m;
            m = m->next;
        }
        else
            break;
    }
    if (m == nullptr)
    {
        cout << "Elements ar šo kārtas skaitli nav saistītajā sarakstā" << endl;
        return;
    }

    if (m == Nelem)
    { // ja aizvietosanas elements vienads ar n elementu to uzreiz izdzes
        if (prevN)
            prevN->next = Nelem->next;
        else
            first = Nelem->next;

        delete Nelem;
        return;
    }

    // ja m ir pirms n tā norādi nomaina uz iepriekšējā
    if (m == prevN)
    {
        prevN = prevM;
    }

    // izņem m elementu no sarakst  liekot iepriekšējai to izlaist
    if (prevM)
        prevM->next = m->next;
    else
        first = m->next;

    // ievieto m elementu n elementa vietā
    if (prevN)
        prevN->next = m;
    else
        first = m;

    m->next = Nelem->next;

    delete Nelem;
}
