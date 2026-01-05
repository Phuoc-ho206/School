#include <iostream>
#include "Generate_vecto.h"
#include <random>
#include <algorithm>
using namespace std;

vector<int> Tao_mang_random(int n, int MinVal, int MaxVal)
{
    vector<int> A;
    A.reserve(n); // tranh cap phat nhieu lan

    random_device rd;
    mt19937 gen(rd());                              // mt19937: Mersenne Twister (PRNG chất lượng cao)
    uniform_int_distribution<> dis(MinVal, MaxVal); // phan bo deu

    for (int i = 0; i < n; i++)
    {
        A.push_back(dis(gen));
    }

    return A;
}

vector<int> Tao_mang_gan_sort(int n)
{
    vector<int> B(n);

    for (int i = 0; i < n; i++)
    {
        B[i] = i + 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, n - 1);

    int k = n / 10; // so luong phan tu bi dao
    for (int t = 0; t < k; t++)
    {
        int i = dis(gen);
        int j = dis(gen);
        swap(B[i], B[j]); // dao vi tri cua 2 phan tu
    }
    return B;
}

vector<int> Tao_mang_nguoc(int n)
{
    vector<int> C(n);

    for (int i = 0; i < n; i++)
    {
        C[i] = i + 2;
    }
    reverse(C.begin(), C.end());
    return C;
}