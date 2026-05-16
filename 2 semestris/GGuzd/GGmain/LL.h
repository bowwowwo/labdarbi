#ifndef LL_H_INCLUDED
#define LL_H_INCLUDED

struct node
{
    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};

void makeList(node **first);
void printList(node *first);
void deleteList(node *first);
void changeNElem(node *&first, int n);

#endif
