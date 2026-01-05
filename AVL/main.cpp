#include <iostream>
#include "AVL_tree.h"
#include "BST.h"
#include "Node.h"
using namespace std;

int main() {
    AVL_tree avl;
    BST bst;

    cout << "=== Chèn node vào AVL và BST ===" << endl;
    int A[] = {10, 20, 5, 6, 15, 30, 25, 16};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n; i++) {
        avl.InsertNode(new Node(A[i]));
        bst.InsertNode(new Node(A[i]));
    }

    cout << "\n--- Duyệt cây AVL ---" << endl;
    cout << "NLR: "; avl.TravelNLR(); cout << endl;
    cout << "LNR: "; avl.TravelLNR(); cout << endl;
    cout << "LRN: "; avl.TravelLRN(); cout << endl;

    cout << "\n--- Tìm kiếm trong AVL ---" << endl;
    int key = 15;
    Node* found = avl.search_x(key);
    if (found != nullptr)
        cout << "Tìm thấy khóa " << key << " trong AVL.\n";
    else
        cout << "Không tìm thấy khóa " << key << " trong AVL.\n";

    int x = 25;
    int cmp_avl = avl.Search_x_count(x);
    int cmp_bst = bst.search_x_count(x);
    cout << "\nSố phép so sánh để tìm " << x << " trong AVL: " << cmp_avl << endl;
    cout << "Số phép so sánh để tìm " << x << " trong BST: " << cmp_bst << endl;

    cout << "\n--- Xóa node 15 trong AVL ---" << endl;
    Node* nodeDel = avl.search_x(15);
    if (nodeDel != nullptr) {
        avl.deleteNode(nodeDel);
        cout << "Cây AVL sau khi xóa 15 (LNR): ";
        avl.TravelLNR(); cout << endl;
    }

    cout << "\n--- Xây dựng AVL từ file mau.txt ---" << endl;
    avl.BuildFromTXT("mau.txt");
    cout << "Cây AVL (LNR): ";
    avl.TravelLNR(); cout << endl;

    return 0;
}
