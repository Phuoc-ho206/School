#include "Binary_Search.h"
#include "Map.h"
#include "FrequencyCounter.h"
#include "WordFrequency.h"
#include "MultipleMap_EX.h"
#include "UnorderedMap.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "=== Binary Search Example ===" << endl;
    Binary_Search bs;
    int a[10] = {1, 2, 3, 5, 5, 6, 8, 9, 14, 21};
    int n = 10, X = 5;
    bs.searchInArray(a, n, X);
    vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 8, 9};
    bs.searchInVector(v, X);

    cout << "\n=== Map Operations Example ===" << endl;
    Map mo;
    mo.insertElements();
    mo.displayMap();
    mo.checkCount(500);
    mo.checkFind(100);
    mo.eraseElement(100);

    cout << "\n=== Frequency Counter Example (EX1) ===" << endl;
    cout << "Enter n and array elements (e.g., 8 1 1 2 1 3 5 1 -4):" << endl;
    FrequencyCounter fc;
    fc.readInput();
    fc.displayFrequencies();

    cout << "\n=== Word Frequency Example (EX2) ===" << endl;
    cout << "Enter n and words (e.g., 9 python java sql java sql ruby C++ string string):" << endl;
    WordFrequency wf;
    wf.readInput();
    wf.findMaxFrequencyWord();

    cout << "\n=== Multimap Example ===" << endl;
    MultimapExample me;
    me.insertElements();
    me.displayMultimap();

    cout << "\n=== Unordered Map Example ===" << endl;
    UnorderedMap ue;
    ue.insertElements();
    ue.displayUnorderedMap();

    return 0;
}