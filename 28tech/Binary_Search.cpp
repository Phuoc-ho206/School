#include "Binary_Search.h"
#include <algorithm>
using namespace std;

void Binary_Search::searchInArray(int a[], int n, int X)
{
    if (binary_search(a, a + n, X))
    {
        cout << "FOUND in array\n";
    }
    else
    {
        cout << "NOT FOUND in array\n";
    }
}

void Binary_Search::searchInVector(vector<int> v, int X)
{
    if (binary_search(v.begin(), v.end(), X))
    {
        cout << "FOUND in vector\n";
    }
    else
    {
        cout << "NOT FOUND in vector\n";
    }
}