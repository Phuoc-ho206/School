#include <iostream>
using namespace std;

class Node {
private:
    Node* pLeft;
    Node* pRight;
    Node* parent;
    int X;
    int height;
public:
    Node();
    Node(int);
    virtual ~Node();

    Node* Getleft(){return pLeft};
    void Setleft(Node* val) {return pLeft = val};
    Node* Getright() {return pRight};
    void Setright(Node* val) {val = pRight};
    Node Getparent() {return parent};
    void Setparent(Node* val) {parent = val};
    int Getkey() {return X};
    void Setkey(int val) {X = val};
    int Getheight() {return height};
    void Setheight(int val) {height = val};

}

class AVL {
private:
    Node* root;
    int nNum;
    int height;
public:
    AVL();
    virtual ~AVL();

    Node* Getroot(){return root};
    void Setroot(Node* val) {root = val};
    bool InsertNode(Node*);
    Node* InsertNode(Node*, Node*);
    void DeleteNode(Node*);
    void TravelNLR();
    void TravelLNR();
    void TravelLRN();
}

AVL::AVL(){}

AVL::~AVL() {}

bool 