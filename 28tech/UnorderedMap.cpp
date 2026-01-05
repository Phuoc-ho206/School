#include "UnorderedMap.h"
using namespace std;

void UnorderedMap::insertElements()
{
    ump[100] = 200;
    ump[200] = 300;
    ump.insert({300, 400});
}
// Unordered map ko có sắp xếp thứ tự
void UnorderedMap::displayUnorderedMap()
{
    for (auto it : ump)
    {
        cout << it.first << " " << it.second << endl;
    }
}