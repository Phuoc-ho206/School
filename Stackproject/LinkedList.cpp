// LinkedList.cpp
#include "LinkedList.h"
#include <cmath>

// element class

element::element() {
    this->data = 0;
    this->pointer = nullptr;
}
element::element(int data) {
    this->data = data;
    this->pointer = nullptr;
}
element::~element() {}

int element::Getdata() { return data; }
void element::Setdata(int val) { data = val; }
element* element::Getpointer() { return pointer; }
void element::Setpointer(element* val) { pointer = val; }

// linkedlist class
linkedlist::linkedlist() {
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}
linkedlist::~linkedlist() {}

element* linkedlist::Gethead() { return head; }
void linkedlist::Sethead(element* val) { head = val; }
element* linkedlist::Gettail() { return tail; }
void linkedlist::Settail(element* val) { tail = val; }

void linkedlist::InsertFirst(element* e) {
    if (head == nullptr)
        head = tail = e;
    else {
        e->Setpointer(head);
        head = e;
    }
    nNum++;
}

void linkedlist::InsertTail(element* e) {
    if (head == nullptr)
        head = tail = e;
    else {
        tail->Setpointer(e);
        tail = e;
    }
    nNum++;
}

bool linkedlist::DeleteFirst() {
    if (head == nullptr) return false;
    element* p = head;
    head = head->Getpointer();
    delete p;
    return true;
}

bool linkedlist::DeleteTail() {
    if (head == nullptr) return false;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return true;
    }
    element* p = head;
    while (p->Getpointer() != tail) p = p->Getpointer();
    delete tail;
    tail = p;
    tail->Setpointer(nullptr);
    return true;
}
void linkedlist::Travel(){
    element* p=this->head; //trỏ p trỏ vào ptu head
    while(p!=nullptr){ // duyệt từng phần tử
        cout<<p->Getdata()<<"\t"; //lấy data bằng con trỏ p
        p=p->Getpointer(); // dịch sang phần tử kế 
    }
}
bool linkedlist::DeleteP(element* p) {
    if (head == nullptr) return false;
    if (head == p) return DeleteFirst();
    element* x = head;
    while (x->Getpointer() != p) x = x->Getpointer();
    x->Setpointer(p->Getpointer());
    delete p;
    return true;
}

void linkedlist::InsertAfterP(element* p, int n) {
    if (p == nullptr) return;
    element* x = new element;
    x->Setdata(n);
    x->Setpointer(p->Getpointer());
    p->Setpointer(x);
}

void linkedlist::DeleteAfterP(element* p) {
    if (p == nullptr || p->Getpointer() == nullptr) return;
    element* xoa = p->Getpointer();
    p->Setpointer(xoa->Getpointer());
    delete xoa;
}

void linkedlist::insertE(element* p, element* x) {
    if (p != nullptr) {
        x->Setpointer(p->Getpointer());
        p->Setpointer(x);
    }
}

element* linkedlist::MaxElement() {
    if (head == nullptr) return nullptr;
    element* p = head;
    element* max = head;
    while (p != nullptr) {
        if (p->Getdata() > max->Getdata()) max = p;
        p = p->Getpointer();
    }
    return max;
}

int linkedlist::Sumlist() {
    element* p = head;
    int sum = 0;
    while (p != nullptr) {
        sum += p->Getdata();
        p = p->Getpointer();
    }
    return sum;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int linkedlist::CountPrime() {
    element* p = head;
    int count = 0;
    while (p != nullptr) {
        if (isPrime(p->Getdata())) count++;
        p = p->Getpointer();
    }
    return count;
}

int linkedlist::Timphantutrung(int x) {
    int count = 0;
    element* p = head;
    while (p != nullptr) {
        if (p->Getdata() == x) count++;
        p = p->Getpointer();
    }
    return count;
}

bool linkedlist::Kiemtra(int x) {
    element* p = head;
    while (p != nullptr) {
        if (p->Getdata() == x) return true;
        p = p->Getpointer();
    }
    return false;
}

void linkedlist::InsertLast(int x) {
    if (!Kiemtra(x)) {
        element* Node = new element;
        Node->Setdata(x);
        Node->Setpointer(nullptr);
        if (head == nullptr)
            head = tail = Node;
        else {
            tail->Setpointer(Node);
            tail = Node;
        }
    }
}

void linkedlist::InsertFirst_new(element* e) {
    element* p = head;
    while (p != nullptr) {
        if (p->Getdata() == e->Getdata()) return;
        p = p->Getpointer();
    }
    e->Setpointer(head);
    head = e;
    if (tail == nullptr) tail = e;
    nNum++;
}

void linkedlist::SplitList(element* goc, int z, element*& lessHead, element*& greaterHead) {
    element* lessTail = nullptr;
    element* greaterTail = nullptr;
    while (goc) {
        if (goc->Getdata() < z)
            InsertTail_New(lessHead, lessTail, goc->Getdata());
        else if (goc->Getdata() > z)
            InsertTail_New(greaterHead, greaterTail, goc->Getdata());
        goc = goc->Getpointer();
    }
}

void TravelCustom(element* head) {
    element* p = head;
    while (p != nullptr) {
        cout << p->Getdata() << "\t";
        p = p->Getpointer();
    }
    cout << endl;
}

void InsertTail_New(element*& head, element*& tail, int data) {
    element* newNode = new element(data);
    newNode->Setpointer(nullptr);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->Setpointer(newNode);
        tail = newNode;
    }
}
