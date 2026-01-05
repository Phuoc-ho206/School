#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    this->nNum = 0;
    this->list = new linkedlist();
}

Queue::~Queue() {
    delete this->list;
}

void Queue::enqueue(int x) {
    this->list->InsertLast(x);
    this->nNum++;
}

int Queue::dequeue() {
    if (this->nNum == 0) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int p = this->list->Gethead()->Getdata();
    this->list->DeleteFirst();
    this->nNum--;
    return p;
}

void Queue::printQueue() {
    element* current = this->list->Gethead();
    while (current != nullptr) {
        cout << current->Getdata() << " ";
        current = current->Getpointer();
    }
    cout << "\n" << endl;
}

void NhapPhanTu(Queue* q, int n){
    for (int i = 0; i < n; i++){
        int value;
        cout << "Nhập phần tử thứ "<< i+1 <<":\n";
        cin >> value;
        q->enqueue(value);
    }
}

void Layphantu(Queue* q, int n){
    for (int i = 0; i < n; i++){
        if (q->isEmpty()){
            cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU";
        } else {
            cout << "Lấy ra: " << q->dequeue() << "\n";
        }
    }
}

void Queue::DectoBin(Queue* q, int num){
    if (num == 0){
        cout << 0;
        return;
    }
    while (num > 0){
        int tmp = num % 2;
        q->enqueue(tmp);
        num/= 2;
    }
    while (!q->isEmpty()){
        cout << q->dequeue();
    }
}
