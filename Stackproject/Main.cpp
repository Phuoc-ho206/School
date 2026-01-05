#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;
int main(){
    Stack *s = new Stack();
    s->push(7);
    s->push(10);
    s->push(18);
    s->push(20);
    s->printStack();
    s->pop();
    cout<<"\n";
    //s->printStack();
    Queue *q = new Queue();
    q->enqueue(5);
    q->enqueue(15);
    q->enqueue(25);
    q->printQueue();
    q->dequeue();
    cout<<"\n";
    q->printQueue();
    delete s;
    delete q;
    return 0;
}