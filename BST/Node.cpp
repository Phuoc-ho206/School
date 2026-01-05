#include "Node.h"

Node::Node() {
    this->key = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

Node::Node(int k) {
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

Node::~Node() {}

Node* Node::Getleft() { return left; }
void Node::Setleft(Node *val) { left = val; }
Node* Node::Getright() { return right; }
void Node::Setright(Node *val) { right = val; }
Node* Node::Getparent() { return parent; }
void Node::Setparent(Node *val) { parent = val; }
int Node::Getkey() { return key; }
void Node::Setkey(int val) { key = val; }
