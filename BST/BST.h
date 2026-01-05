#ifndef BST_H
#define BST_H

#include "Node.h"
#include <iostream>
using namespace std;

class BST {
public:
    BST();
    virtual ~BST();

    Node* Getroot();
    void Setroot(Node* val);

    bool InsertNode(Node* n);
    bool InsertNodeRe(Node* root, Node* p);
    void deleteNode(Node* n, Node* parent);

    void TravelNLR();
    void TravelLNR();
    void TravelLRN();

    void NLR(Node* r);
    void LNR(Node* r);
    void LRN(Node* r);

    int SumTree(Node* r);
    Node* search_x(Node*, int);
    int Max(Node* r);
    int Min(Node* r);
    int CountNode(Node* r);
    int Countleaf(Node* r);
    int DemGiatriPhanBiet(Node* r);
    int Demsoluongphantuphanbiet(Node* r);
    int Height(Node* r);

    int TongNode_1_level(Node* r, int currentLevel);

    int SumSoNguyenTo(Node* r);
    void XoaSoNguyenTo(Node* r);
    bool isPrime(int n);

private:
    Node* root;
};

#endif // BST_H
