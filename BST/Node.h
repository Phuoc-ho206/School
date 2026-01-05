#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(int);
    virtual ~Node();

    Node *Getleft();
    void Setleft(Node *val);
    Node *Getright();
    void Setright(Node *val);
    Node *Getparent();
    void Setparent(Node *val);
    int Getkey();
    void Setkey(int val);

private:
    Node *left;
    Node *right;
    Node *parent;
    int key;
};

#endif // NODE_H
