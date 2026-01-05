#include <iostream>
using namespace std;
// int UCLN(int a, int b)
// {
//     a = abs(a);
//     b = abs(b);
//     if (a == b)
//         return a;
//     if (a > b)
//         return UCLN(a - b, b);
//     return UCLN(a, b - a);
// }
// int UCLN3(int a, int b, int c)
// {
//     return UCLN(a, UCLN(b, c));
// }
// int BCNN(int a, int b)
// {
//     a = abs(a);
//     b = abs(b);
//     return (a * b) / UCLN(a, b);
// }
// int BSCNN_mang(int a[], int n)
// {
//     if (n == 1)
//         return a[0];
//     return BCNN(a[n - 1], BSCNN_mang(a, n - 1));
// }
// int bo_3_usclnln(int a[], int n, int &so1, int &so2, int &so3)
// {
//     int max = 0;
//     for (int i = 0; i < n - 2; i++)
//         for (int j = i + 1; j < n - 1; j++)
//             for (int k = j + 1; k < n; k++)
//             {
//                 int max_tam = UCLN3(a[i], a[j], a[k]);
//                 if (max_tam > max)
//                 {
//                     max = max_tam;
//                     so1 = a[i];
//                     so2 = a[j];
//                     so3 = a[k];
//                 }
//             }
//     return max;
// }

// QUAY_LUI
/*void print_kq(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void quaylui(int a[], int n, int j)
{
    for (int i = 0; i < 2; i++)
    {
        a[j] = i;
        if (j == n - 1)
        {
            print_kq(a, n);
        }
        else
        {
            quaylui(a, n, j + 1);
        }
    }
} */

int TimMax(int A[], int n, int max)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            max = A[i];
            if (max < A[j])
            {
                max = A[j];
            }
        }
    }
    return max;
}

int CountX(int A[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
        {
            count++;
        }
    }
    return count;
}

bool Timdiemcodinh(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == i)
        {
            cout << A[i];
            return true;
        }
    }
}
int main()
{
    // int a[] = {8, 4, 3, 9, 6, 4, 1, 10};
    // int n = sizeof(a) / sizeof(int);
    // int so1, so2, so3;
    // cout << bo_3_usclnln(a, n, so1, so2, so3) << endl;
    // cout << "(" << so1 << "," << so2 << "," << so3 << ")";
    // cout << endl;

    /*quaylui
    int a[105];
    int n = 3;
    quaylui(a, n, 0);
    */

    // int a[] = {7, 1, 3, 4, 5, 6};
    // int n = 6;
    // int M = 11;

    int A[n];
    int max = 0;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int x;
    cout << "Nhap phan tu can dem: ";
    cin >> x;

    int solonhat = TimMax(A[], n, max);
    int demx = CountX(A[], n, x);

    if (Timdiemcodinh(A[], n))
    {
        cout << "Mang co diem co dinh" << endl;
    }
    else
    {
        cout << "Mang khong co diem co dinh" << endl;
    }
    cout << "So lon nhat la: " << solonhat << endl;
    cout << "So luong phan tu " << x << " trong mang la: " << demx << endl;
    return 0;
}
