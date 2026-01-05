#include <iostream>
#include <fstream>

using namespace std;

void floy_w(int a[100][100], int n) //0(n^3)
{
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}

int main()
{
    ifstream ifs("input.txt");
    int n;
    int a[100][100];
    ifs>>n;
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ifs>>a[i][j];
        }
    }
    floy_w(a,n);
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cout<<a[i][j]<<" ";
           if(j==n-1) cout<<endl;
        }
    }
}