#include "BST.h"
#include <iostream>
using namespace std;

int main() {
    BST *tree = new BST();
    Node *n;

    n = new Node(10); tree->InsertNode(n);
    n = new Node(19); tree->InsertNode(n);
    n = new Node(9);  tree->InsertNode(n);
    n = new Node(3);  tree->InsertNode(n);
    n = new Node(19); tree->InsertNode(n); // sẽ bị bỏ qua vì trùng
    n = new Node(8);  tree->InsertNode(n);
    n = new Node(4);  tree->InsertNode(n);
    n = new Node(1);  tree->InsertNode(n);
    n = new Node(15); tree->InsertNode(n);

    cout << "Tong gia tri cay: " << tree->SumTree(tree->Getroot()) << "\n";
    cout << "Tong so nguyen to: " << tree->SumSoNguyenTo(tree->Getroot()) << "\n";
    cout << "So luong phan tu phan biet: " << tree->Demsoluongphantuphanbiet(tree->Getroot()) << "\n";
    cout << "So nut la: " << tree->Countleaf(tree->Getroot()) << "\n";
    cout << "Chieu cao cay: " << tree->Height(tree->Getroot()) << "\n";

    cout << "\nXoa so nguyen to...\n";
    tree->XoaSoNguyenTo(tree->Getroot());

    cout << "Cay sau khi xoa (NLR): ";
    tree->TravelNLR();
    cout << endl;

    delete tree;
    return 0;
}
