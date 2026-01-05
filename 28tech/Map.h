#ifndef Map_H
#define Map_H

#include <map>
#include <iostream>

class Map
{
private:
    std::map<int, int> mp;

public:
    void insertElements();
    void displayMap();
    void checkCount(int key);
    void checkFind(int key);
    void eraseElement(int key);
};

#endif