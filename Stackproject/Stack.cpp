#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
void Stack::push(int x) {
    element* p = new element(x);
    this->list->InsertFirst(p);
}
int Stack::pop(){
    int p = this->list->Gethead()->Getdata();
    this->list->DeleteFirst();
    return p;
}
void Stack::printStack(){
    cout << "Stack contents (top to bottom): ";
    list->Travel();
}
Stack::Stack(){
    this->nNum = 0;
    this->list = new linkedlist();
}
Stack::~Stack(){
    //dtor
}

bool Stack::isEmpty(){
    return (this->list->Gethead() == nullptr);
}

void Nhapphantu(Stack* s, int x){
    for (int i = 0; i < x; i++){
        int val;
        cout << "Nhập giá trị thứ "<< i+1 << ":";
        cin >> val;
        s->push(val);
    }
}

void layphantu(Stack* s, int x){
   for (int i = 0; i < x; i++){
    if (s->isEmpty()){
        cout << "STACK RONG, KHONG LAY DUOC PHAN TU";
    } else {
        cout << "Lấy ra: "<< s->pop() << endl;
    }
   }
}

void Stack::InsertTail(int x){
    list->InsertLast(x);
    nNum++;
}

void Stack::DeleteTail(){
    list->DeleteTail();
    nNum--;
}

void Stack::DectoBin(int num, Stack* s){
    if (num == 0){
        push(0);
        return;
    }
    while (num > 0){
        int tmp = num % 2;
        push(tmp);
        num /= 2;
    }
}

