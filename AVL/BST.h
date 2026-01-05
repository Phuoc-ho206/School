#pragma once
#include "Node.h"

class BST {
private:
    Node* root;
public:
    BST() { root = nullptr; }
    Node* Getroot() { return root; }

    void InsertNode(Node* n) {
        if (root == nullptr) {
            root = n;
            return;
        }
        Node* p = root;
        Node* parent = nullptr;
        while (p != nullptr) {
            parent = p;
            if (n->Getkey() < p->Getkey())
                p = p->Getleft();
            else
                p = p->Getright();
        }
        if (n->Getkey() < parent->Getkey())
            parent->Setleft(n);
        else
            parent->Setright(n);
        n->Setparent(parent);
    }

    int search_x_count(int k) {
        int comparisons = 0;
        Node* current = root;
        while (current != nullptr) {
            comparisons++;
            if (k == current->Getkey()) return comparisons;
            else if (k < current->Getkey()) current = current->Getleft();
            else current = current->Getright();
        }
        return comparisons; // không thấy
    }
};
