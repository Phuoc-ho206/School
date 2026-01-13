#include <iostream>
using namespace std;
void sub_array(int *&a, int n, int *&dp, int *&T)
{
    int i, j, jmax;
    a[0] = INT_MIN;
    a[n + 1] = INT_MAX;
    dp[n + 1] = 1; // co so
    for (int i = n; i >= 0; i--)
    {
        jmax = n + 1;
        for (j = i + 1; j <= n + 1; j++)
            if ((a[j] > a[i]) && (dp[j] > dp[jmax]))
                jmax = j;
        dp[i] = dp[jmax] + 1;
        T[i] = jmax;
    }
}
int main()
{
    int n;
    cout << "n= ";
    cin >> n;
    int *a = new int[n + 2];
    int *dp = new int[n + 2];
    int *T = new int[n + 2];
    for (int i = 1; i <= n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    sub_array(a, n, dp, T);
    cout << "Chieu dai: " << dp[0] - 2 << endl;
    cout << "Day con tang dai nhat:" << endl;
    int i = T[0];
    while (i != n + 1)
    {
        cout << "a[" << i << "]= " << a[i] << endl;
        i = T[i];
    }
    delete[] a;
    delete[] dp;
    delete[] T;
    cout << endl;
    return 0;
}