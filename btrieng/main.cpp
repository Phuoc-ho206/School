#include <iostream>
using namespace std;

bool checkw(int w)
{
    if (1 <= w && w <= 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int w;
    cout << "Enter the weight of the watermelon: ";
    cin >> w;
    if (checkw(w))
    {
        if (w % 2 == 0 && w != 2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    system("pause");
    return 0;
}
// change after commit