#include "BST.h"

BST::BST() {
    this->root = nullptr;
}

BST::~BST() {}

Node* BST::Getroot() { return root; }
void BST::Setroot(Node* val) { root = val; }

bool BST::InsertNode(Node* n) {
    Node *p = this->root;
    Node *T;
    if (root == nullptr) {
        this->root = n;
        return true;
    }
    while (p != nullptr) {
        T = p;
        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else if (p->Getkey() < n->Getkey())
            p = p->Getright();
        else
            return false; // trùng
    }
    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else
        T->Setright(n);
    n->Setparent(T);
    return true;
}

bool BST::InsertNodeRe(Node* root, Node* p) {
    if (root == nullptr) {
        this->root = p;
        return true;
    }
    if (root->Getkey() == p->Getkey()) return false;
    if (p->Getkey() < root->Getkey()) {
        if (root->Getleft() == nullptr) {
            root->Setleft(p);
            p->Setparent(root);
            return true;
        }
        return InsertNodeRe(root->Getleft(), p);
    } else {
        if (root->Getright() == nullptr) {
            root->Setright(p);
            p->Setparent(root);
            return true;
        }
        return InsertNodeRe(root->Getright(), p);
    }
}

void BST::NLR(Node*r) {
    if (r != nullptr) {
        cout << r->Getkey() << " ";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}

int BST::SumTree(Node* r) {
    if (r == nullptr) return 0;
    return r->Getkey() + SumTree(r->Getleft()) + SumTree(r->Getright());
}

void BST::LNR(Node*r) {
    if (r != nullptr) {
        LNR(r->Getleft());
        cout << r->Getkey() << " ";
        LNR(r->Getright());
    }
}

void BST::LRN(Node*r) {
    if (r != nullptr) {
        LRN(r->Getleft());
        LRN(r->Getright());
        cout << r->Getkey() << " ";
    }
}

void BST::TravelNLR() { NLR(this->root); }
void BST::TravelLNR() { LNR(this->root); }
void BST::TravelLRN() { LRN(this->root); }

Node* BST::search_x(Node *r, int k) {
    if (r == nullptr) return nullptr;
    if (k == r->Getkey()) return r;
    if (k > r->Getkey())
        return search_x(r->Getright(), k);
    else
        return search_x(r->Getleft(), k);
}

void BST::deleteNode(Node* n, Node* parent) {
    if (n == nullptr) return;
    if (n->Getleft() == nullptr && n->Getright() == nullptr) {
        if (parent != nullptr) {
            if (parent->Getleft() == n) parent->Setleft(nullptr);
            else parent->Setright(nullptr);
        } else {
            root = nullptr;
        }
        delete n;
        return;
    }
    if (n->Getleft() == nullptr || n->Getright() == nullptr) {
        Node* child = (n->Getleft() != nullptr) ? n->Getleft() : n->Getright();
        if (parent != nullptr) {
            if (parent->Getleft() == n) parent->Setleft(child);
            else parent->Setright(child);
        } else {
            root = child;
        }
        child->Setparent(parent);
        delete n;
        return;
    }
    Node* p = n->Getright();
    while (p->Getleft() != nullptr) {
        p = p->Getleft();
    }
    int val = p->Getkey();
    deleteNode(p, p->Getparent());
    n->Setkey(val);
}

int BST::Max(Node* r) {
    if (r == nullptr) return 0;
    while (r->Getright() != nullptr) r = r->Getright();
    return r->Getkey();
}

int BST::Min(Node* r) {
    if (r == nullptr) return 0;
    while (r->Getleft() != nullptr) r = r->Getleft();
    return r->Getkey();
}

int BST::CountNode(Node* r) {
    if (r == nullptr) return 0;
    return 1 + CountNode(r->Getleft()) + CountNode(r->Getright());
}

int BST::Countleaf(Node* r) {
    if (r == nullptr) return 0;
    if (r->Getleft() == nullptr && r->Getright() == nullptr) return 1;
    return Countleaf(r->Getleft()) + Countleaf(r->Getright());
}

int BST::DemGiatriPhanBiet(Node* r) {
    if (r == nullptr) return 0;
    return 1 + DemGiatriPhanBiet(r->Getleft()) + DemGiatriPhanBiet(r->Getright());
}

int BST::Demsoluongphantuphanbiet(Node* r) {
    if (r == nullptr) return 0;
    return 1 + Demsoluongphantuphanbiet(r->Getleft()) + Demsoluongphantuphanbiet(r->Getright());
}

int BST::Height(Node* r) {
    if (r == nullptr) return 0;
    int leftHeight = Height(r->Getleft());
    int rightHeight = Height(r->Getright());
    return 1 + max(leftHeight, rightHeight);
}

int BST::TongNode_1_level(Node* r, int currentLevel) {
    if (r == nullptr) return 0;
    if (currentLevel == 1) return r->Getkey();
    return TongNode_1_level(r->Getleft(), currentLevel - 1) +
           TongNode_1_level(r->Getright(), currentLevel - 1);
}

bool BST::isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int BST::SumSoNguyenTo(Node* r) {
    if (r == nullptr) return 0;
    int sum = 0;
    if (isPrime(r->Getkey())) sum += r->Getkey();
    sum += SumSoNguyenTo(r->Getleft());
    sum += SumSoNguyenTo(r->Getright());
    return sum;
}

void BST::XoaSoNguyenTo(Node* r) {
    if (r == nullptr) return;
    XoaSoNguyenTo(r->Getleft());
    XoaSoNguyenTo(r->Getright());
    if (isPrime(r->Getkey())) {
        Node* parent = r->Getparent();
        deleteNode(r, parent);
    }
}
