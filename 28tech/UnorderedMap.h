#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <unordered_map>
#include <iostream>

class UnorderedMap
{
private:
    std::unordered_map<int, int> ump;

public:
    void insertElements();
    void displayUnorderedMap();
};

#endif