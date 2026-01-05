#ifndef MULTIPLEMAP_EX_H
#define MULTIPLEMAP_EX_H

#include <map>
#include <iostream>

class MultimapExample
{
private:
    std::multimap<int, int> mp;

public:
    void insertElements();
    void displayMultimap();
};

#endif