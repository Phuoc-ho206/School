#include "AVL_tree.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
using namespace std;
AVL_tree::AVL_tree()
{
    //ctor
    this->root = nullptr;
}


AVL_tree::~AVL_tree()
{
    //dtor
}
bool AVL_tree::InsertNode(Node* n) {
    Node* p = this->root;
    Node* T=nullptr;
    if (root == nullptr)
    {
        this->root = n;


        return true;
    }
    while (p != nullptr) {
        T = p;


        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                    return false;
    }


    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    n->Setparent(T);
    /////////////////////////////////////////
    Node* x = n;
    Node* parentX = x->Getparent();
    while (x!= nullptr) {
        int bal = this->CheckBal(x);
        switch (bal) {
        case 0:    break;     // Can bang
        case 1:    break;     //
        case -1:   break;   //


        case 2: {
            int left_ball = this->CheckBal(x->Getleft());
            if (left_ball >= 0)// LEFT-LEFT
            {
                parentX = x->Getparent();
                this->RightRotate(x);
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else parentX->Setleft(x);
            }
            else // Left-Right
            {
                Node* y = x->Getleft();
                this->LeftRotate(y);
                x->Setleft(y);
                y->Setparent(x);
                parentX = x->Getparent();
                this->RightRotate(x);
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else parentX->Setleft(x);
            }
            break;     //
        }
        case -2: {
            int right_ball = this->CheckBal(x->Getright());
            if (right_ball <= 0) // RIGHT-RIGHT
            {
                parentX = x->Getparent();
                this->LeftRotate(x);
                x->Setparent(parentX);
                if(parentX!=nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else parentX->Setleft(x);
            }
            else // Right-left
            {
                Node* y = x->Getright();
                this->RightRotate(y);
                x->Setright(y);
                y->Setparent(x);
                parentX = x->Getparent();
                this->LeftRotate(x);
                x->Setparent(parentX);
                if (parentX != nullptr)
                    if (x->Getkey() > parentX->Getkey())
                        parentX->Setright(x);
                    else parentX->Setleft(x);
            }
            break;   //
        }
        }
        if (x->Getparent() == nullptr)
            this->root = x;
        x = x->Getparent();
       
    }
    return true;
}
Node* AVL_tree::InsertNode(Node* r, Node* p) {
    if (r == nullptr) {
        r = p;
        return r;
    }
    if (r->Getkey() == p->Getkey())
        return nullptr;
    else if (r->Getkey() > p->Getkey()) {
        r->Setleft(InsertNode(r->Getleft(), p));
        return r->Getleft();
    }
    else {
        r->Setright(InsertNode(r->Getright(), p));
        return r->Getright();
    };
    //
 /*   r->Setheight ( 1 + max(r->Getleft()->Getheight(),r->Getright()->Getheight()));


    int valBalance = r->Getleft()->Getheight() - r->Getright()->Getheight();


    if(valBalance>1&&r->Getleft()->Getkey()>p->Getkey())
        this->RightRotate(r);*/


}

void AVL_tree::InsertNodeRe(Node* p) {
    this->root = InsertNode(this->root, p);
}
void AVL_tree::NLR(Node* r) {
    if (r != nullptr) {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void AVL_tree::LNR(Node* r) {
    //sinh vien code
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << "\n";
        LNR(r->Getright());
    }
}
void AVL_tree::LRN(Node* r) {
    //sinh vien code
    if (r != nullptr){
        LRN(r->Getleft());
        LRN(r->Getright());
        cout<<r->Getkey()<<"\n";
    }}
void AVL_tree::TravelNLR() {
    NLR(this->root);
}
void AVL_tree::TravelLNR() {
    //sinh vien code
    LNR(this->root);
}
void AVL_tree::TravelLRN() {
    //sinh vien code
    LRN(this->root);
}

Node* AVL_tree::search_x(Node* root, int k) {
    if (root == nullptr) return nullptr;
    if (root->Getkey() == k) return root;
    if (k < root->Getkey()) {
        return search_x(root->Getleft(), k);
    } else {
        return search_x(root->Getright(), k);
    }
}

Node* AVL_tree::search_x(int k) {
    return search_x(this->root, k);
}
void AVL_tree::deleteNode(Node* n) {
    Node* p = n;
    if (n->Getleft() == nullptr && n->Getright() == nullptr) {
        if (n->Getparent() != nullptr) {
            if (n->Getparent()->Getleft() == n)
                n->Getparent()->Setleft(nullptr);
            else
                n->Getparent()->Setright(nullptr);
        }
        delete n;
    }
    else {
        if (p->Getright() != nullptr) {
            while (p->Getleft() != nullptr)
                p = p->Getleft();
            n->Setkey(p->Getkey());
            if (p->Getparent()->Getleft() == p)
                p->Getparent()->Setleft(nullptr);
            else
                p->Getparent()->Setright(nullptr);
            delete p;
        }
        else {
            while (p->Getright() != nullptr)
                p = p->Getright();
            n->Setkey(p->Getkey());
            if (p->Getparent()->Getleft() == p)
                p->Getparent()->Setleft(nullptr);
            else
                p->Getparent()->Setright(nullptr);
            delete p;
        }
    }
}

void AVL_tree::LeftRotate(Node*& P) {
    Node* Q;
    Node* T;
    Q = P->Getright();
    T = Q->Getleft();
    P->Setright(T);
    Q->Setleft(P);
    P->Setparent(Q);
    if(T!=nullptr)
    T->Setparent(P);
    P = Q;
}
void AVL_tree::RightRotate(Node*& P) {
    // sinh vien code
    Node* Q;
    Node* T;
    Q = P->Getleft();
    T = Q->Getright();
    P->Setleft(T);
    Q->Setright(P);
    P->Setparent(Q);
    if (T != nullptr)
        T->Setparent(P);
    P = Q;   
}
int AVL_tree::CheckBal(Node* p) {
    int bal = this->GetHeight(p->Getleft()) - this->GetHeight(p->Getright());
    return bal;
}
int AVL_tree::GetHeight(Node* p) {
    if (p == nullptr) return 0;
    else
    return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}

void AVL_tree::SearchKeyUser(){
    int x;
    cout <<"Nhập khoá cần tìm: ";
    cin >> x;
    Node* tim = this->search_x(x);
    if (tim != nullptr){
        cout << "Khoá " << x << " nằm trong cây AVL.\n";
    } else {
        cout << "Khoá " << x << " không tồn tại trong cây AVL.\n";
    }
}

int AVL_tree::Search_x_count(int k){
    int so_sanh = 0;
    Node* htai = this->root;
    while (htai != nullptr){
        so_sanh++;
        if (k == htai->Getkey()){
            return so_sanh;
        } else if (k < htai->Getkey()){
            htai = htai->Getleft();
        } else {
            htai = htai->Getright();
        }
    }
    return so_sanh;
}

void AVL_tree::BuildFromTXT(const std::string& filename){
    ifstream fin(filename);
    if (!fin){
        cerr << "Không thể mở file" << filename << endl;
        return;
    }
    int x;
    while (fin >> x){
        this->InsertNode(new Node(x));
    }
    fin.close();
}

