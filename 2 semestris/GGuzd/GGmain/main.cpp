#include <iostream>
#include "LL.h"

using namespace std;

int main()
{
    node *first = NULL;
    int n;

    makeList(&first);

    if (first == NULL)
    {
        cout << "Cipari netika ievaditi" << endl;
        return 1;
    }

    cout << "Ievadiet n (kārtas skaitlis, kuru elementu izdzēsīs): " << endl;
    cin >> n;

    printList(first);

    changeNElem(first, n);

    printList(first);

    deleteList(first);
}
