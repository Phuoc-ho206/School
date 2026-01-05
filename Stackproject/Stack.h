#ifndef STACK_H
#define STACK_H
#include "Linkedlist.h"


class Stack {
private:
    int nNum;
    linkedlist* list;
public:
    Stack();
    virtual ~Stack();
    void push(int);
    int pop();
    void printStack();
    bool isEmpty();
    void InsertTail(int x);
    void DeleteTail();
    void DectoBin(int num, Stack* s);
};
#endif // STACK_H
