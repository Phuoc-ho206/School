#ifndef Queue_h
#define Queue_h
#include "LinkedList.h"

class Queue 
{
private:
    int nNum;
    linkedlist* list;
public:
 Queue (/* args */);
 virtual ~Queue ();
 void enqueue(int);
 int dequeue();
 void printQueue();
 bool isEmpty();
 void InsertTail(int x);
 void DeleteTail();
 void DectoBin(Queue* q, int num);
};

#endif // <Queue_h>