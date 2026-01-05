#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class element {
private:
    int data;
    element* pointer;
public:
    element();
    element(int);
    virtual ~element();

    int Getdata();
    void Setdata(int val);
    element* Getpointer();
    void Setpointer(element* val);
};

class linkedlist {
private:
    element* head;
    element* tail;
    int nNum;

public:
    linkedlist();
    virtual ~linkedlist();
    element* Gethead();
    void Sethead(element* val);
    element* Gettail();
    void Settail(element* val);

    void InsertFirst(element*);
    void InsertTail(element*);
    bool DeleteFirst();
    bool DeleteTail();
    bool DeleteP(element*);

    void InsertAfterP(element* p, int n);
    void DeleteAfterP(element* p);
    void insertE(element* p, element* x);
    void Travel();
    element* MaxElement();
    int Sumlist();
    int CountPrime();
    int Timphantutrung(int x);
    bool Kiemtra(int x);
    void InsertLast(int x);
    void InsertFirst_new(element*);

    void SplitList(element* goc, int x, element*& lessHead, element*& greaterHead);
};

bool isPrime(int n);
void TravelCustom(element* head);
void InsertTail_New(element*& head, element*& tail, int data);

#endif
