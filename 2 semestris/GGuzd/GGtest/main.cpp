#include <iostream>
#include "../GGmain/LL.h"

using namespace std;

void arrayList(node **first, int *array, int size)
{
    node *last = NULL, *p;
    for (int i = 0; i < size; i++)
    {
        p = new node(array[i]);

        if (*first == NULL)
        {
            *first = last = p;
        }
        else
        {
            last->next = p;
            last = last->next;
        };
    }
}

bool checkResult(node *first, int *array, int size)
{
    node *n = first;
    for (int i = 0; i < size; i++)
    {
        if (n == NULL)
        {
            return false;
        }

        if (!(n->data == array[i]))
        {
            return false;
        }

        n = n->next;
    }

    return n == NULL;
}

// vai saraksts ir tukss
bool test_A()
{
    node *first = NULL;
    int n = 5;

    try
    {
        changeNElem(first, n);
    }
    catch (const int e)
    {
        return e == -210;
    }

    return false;
}

// vai saraksts ir pareizi izmainits
bool test_B()
{
    int arr[] = {10, 1, 3, 4, 7, 5, 1, 2, 9, 6};
    int result[] = {10, 1, 3, 4, 7, 5, 1, 2, 6}; // 10 1 3 4 7 5 1 2 6
    int n = 9;
    node *first = NULL;

    arrayList(&first, arr, 10);
    changeNElem(first, n);
    //printList(first);
    return checkResult(first, result, 9);
}

bool test_C()
{
    int arr[] = {8, 7, 4, 6, 1, 2, 5, 3};
    int result[] = {8, 7, 4, 2, 1, 5, 3}; // 8 7 4 2 1 5 3
    int n = 4;
    node *first = NULL;

    arrayList(&first, arr, 8);
    changeNElem(first, n);
    //printList(first);
    return checkResult(first, result, 7);
}

bool test_D()
{
    int arr[] = {4, 5, 1, 3, 2};
    int result[] = {4, 1, 3, 5}; // 4 1 3 5
    int n = 5;
    node *first = NULL;

    arrayList(&first, arr, 5);
    changeNElem(first, n);
    //printList(first);
    return checkResult(first, result, 4);
}

int main()
{
    cout << "Izņēmumsituācija" << endl;
    cout << test_A() << endl;
    cout << "Vienībtestēšana" << endl;
    cout << test_B() << endl;
    cout << test_C() << endl;
    cout << test_D() << endl;
}
