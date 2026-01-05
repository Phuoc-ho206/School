#include "MultipleMap_EX.h"
using namespace std;

void MultimapExample::insertElements()
{
    mp.insert({300, 400});
    mp.insert({400, 500});
    //  Multiple map cho phép sử dụng chung 1 key cho nhiều value
    // Không thể thêm dữ liệu bằng cách gán
}

void MultimapExample::displayMultimap()
{
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
}