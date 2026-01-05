// main.cpp
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist *list_ = new linkedlist();
    element *e;

    e = new element(9);
    list_->InsertFirst(e);

    e = new element(11);
    list_->InsertFirst(e);

    e = new element(3);
    list_->InsertFirst(e);

    e = new element(4);
    list_->InsertTail(e);

    e = new element(7);
    list_->InsertTail(e);

    e = new element(15);
    list_->InsertTail(e);

    list_->InsertFirst_new(e);
    list_->Travel();

    list_->DeleteFirst();
    cout << "\n";

    list_->DeleteTail();
    list_->DeleteP(list_->MaxElement());
    list_->Travel();

    cout << "\nTổng giá trị của các phần tử: " << list_->Sumlist() << endl;
    cout << "\nSố lượng số nguyên tố là: " << list_->CountPrime() << endl;

    list_->InsertAfterP(e, 100);
    list_->insertE(e, new element(100));
    list_->DeleteAfterP(e);

    cout << "\nSố lượng phần tử trùng với 3 là: " << list_->Timphantutrung(3) << endl;

    int x;
    cout << "\nNhập giá trị cần kiểm tra: ";
    cin >> x;

    if (list_->Kiemtra(x)) {
        cout << x << " có trong danh sách.\n";
    } else {
        cout << x << " không có trong danh sách. Thêm vào danh sách.\n";
        list_->InsertLast(x);
    }

    cout << "Danh sách sau khi thêm:\n" << endl;
    list_->Travel();

    int z = 8;
    element* goc = list_->Gethead();
    element* less = nullptr;
    element* greater = nullptr;

    list_->SplitList(goc, z, less, greater);

    cout << "Danh sách < " << z << ":\n";
    TravelCustom(less);

    cout << "Danh sách > " << z << ":\n";
    TravelCustom(greater);

    return 0;
}