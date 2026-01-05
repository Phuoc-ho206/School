#include "FrequencyCounter.h"
using namespace std;

void FrequencyCounter::readInput()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
}

void FrequencyCounter::displayFrequencies()
{
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] != 0)
        {
            cout << a[i] << " " << mp[a[i]] << endl;
            mp[a[i]] = 0;
        }
    }
}

