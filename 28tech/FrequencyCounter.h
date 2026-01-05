#ifndef FREQUENCYCOUNTER_H
#define FREQUENCYCOUNTER_H

#include <map>
#include <vector>
#include <iostream>
using namespace std;

class FrequencyCounter
{
private:
    map<int, int> mp;
    int n;
    vector<int> a;

public:
    void readInput();
    void displayFrequencies();
};

#endif