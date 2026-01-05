#include "WordFrequency.h"
using namespace std;

void WordFrequency::readInput()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
}

void WordFrequency::findMaxFrequencyWord()
{
    int max_fre = 0;
    string res;
    for (auto it : mp)
    {
        if (it.second >= max_fre) // Nếu muốn tìm từ có tần suất xuất hiện nhiều nhất đầu tiên thì chỉ cần so sánh >
        {
            max_fre = it.second;
            res = it.first;
        }
    }
    cout << res << " " << max_fre << endl;
}

void WordFrequency::insertWord(const string &word)
{
    mp[word]++;
    cout << "Update word" << word << "Frequency: " << mp[word] << endl;
}

bool WordFrequency::countWord(const string &word)
{
    if (mp.cout(word) != 0)
    {
        cout << "Found" << word << endl;
        return true;
    }
    else
    {
        cout << "Not Found" << word << endl;
        return false;
    }
}

bool WordFrequency::findWord(const string &word)
{
    auto it = mp.find(word); // hàm find trả về iterator(con trỏ thông minh) chỉ đến key cần tìm hoặc mp.end() nếu k tìm thấy
    if (it != mp.end())
    {
        cout << "Found!" << it->first << "with frequency" << it->second << endl;
        return true;
    }
    else
    {
        cout << "Word '" << word << "' not found." << endl;
        return false;
    }
}

void WordFrequency::eraseWord(const string &word)
{
    if (mp.erase(word) > 0) // trả về 1 nếu đã xoá
    {
        cout << "Erased word: " << word << endl;
    }
    else
    {
        cout << "Not found " << word << "to erase";
    }
}
