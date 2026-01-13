#include <iostream>
#define MOD 1000000007
using namespace std;
struct matran
{
    int val[3][3];
};
matran nhan(matran a, matran b)
{
    matran c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            c.val[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c.val[i][j] = ((c.val[i][j] + (long long)a.val[i][k] * b.val[k][j]) %
                               MOD) %
                              MOD;
        }
    return c;
}
matran mu(matran a, long long k)
{
    matran x;
    if (k == 1)
        return a;
    x = mu(a, k / 2);
    x = nhan(x, x);
    if (k % 2)
        x = nhan(x, a);
    return x;
}
int main()
{
    matran a, c;
    long long n;
    cout << "n= ";
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2)
    {
        cout << 2;
        return 0;
    }
    a.val[0][0] = 1;
    a.val[0][1] = 1;
    a.val[1][0] = 1;
    a.val[1][1] = 0;
    c = mu(a, n - 1);
    cout << (c.val[0][0] + c.val[0][1]) % MOD;
    cout << endl;
    return 0;
}