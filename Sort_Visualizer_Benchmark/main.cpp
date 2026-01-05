#include <iostream>
#include "Generate_vecto.h"
#include <vector>

using namespace std;

// print elements of an int vector on a single line separated by spaces
void printVector(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ' ';
    }
    cout << '\n';
}

int main()
{
    int n;
    cout << "Nhap so phan tu n = ";
    cin >> n;

    vector<int> A_random = Tao_mang_random(n, 1, 100000);
    vector<int> B_nearly = Tao_mang_gan_sort(n);
    vector<int> C_reverse = Tao_mang_nguoc(n);

    if (n <= 20)
    {
        cout << "\nMang ngau nhien:\n";
        printVector(A_random);

        cout << "\nMang gan sap xep:\n";
        printVector(B_nearly);

        cout << "\nMang dao nguoc:\n";
        printVector(C_reverse);
    }

    return 0;
}