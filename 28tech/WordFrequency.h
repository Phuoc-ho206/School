#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

#include <map>
#include <string>
#include <iostream>

class WordFrequency
{
private:
    std::map<std::string, int> mp;
    int n;

public:
    void readInput();
    void findMaxFrequencyWord();

    void insertWord(const string& word); //chèn
    bool countWord(const string& word); //Kiểm tra từ có tồn tại k
    bool findWord(const string& word);  //Tìm từ
    void eraseWord(const string& word);    //Xoá Từ
    int getsize(); // Lấy kich thước map
    void clearMap(); // Xoá map
    int GetFrequency(const string& word); // Lấy tần suất xuất hiện của từ
    void DisplayMap(); //Duyệt và hiển thị

};

#endif