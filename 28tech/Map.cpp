#include "Map.h"
using namespace std;

void Map::insertElements()
{
    mp[100] = 200;
    mp[200] = 300;
    mp.insert({300, 400});
    mp.insert({400, 500});
    mp[100] = 300; // Overwrite
}

void Map::displayMap()
{
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    // for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << (*it).first << " " << (*it).second << endl;
    // }
    // for (pair<int, int> it : mp)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
}

void Map::checkCount(int key)
{
    if (mp.count(key) != 0)
    {
        cout << "Found key " << key << "!" << endl;
    }
    else
    {
        cout << "Not found key " << key << "!" << endl;
    }
}

void Map::checkFind(int key)
{
    if (mp.find(key) != mp.end())
    {
        cout << "Found key " << key << "!" << endl;
    }
    else
    {
        cout << "Not found key " << key << "!" << endl;
    }
}

void Map::eraseElement(int key)
{
    mp.erase(key);
    cout << "After erasing " << key << ":" << endl;
    displayMap();
}