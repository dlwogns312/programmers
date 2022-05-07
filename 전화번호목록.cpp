#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    for (int i = 0; i < phone_book.size(); i++)
        um[phone_book[i]] = 1;
    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < phone_book[i].size() - 1; j++)
        {
            temp += phone_book[i][j];
            if (um[temp])
                return false;
        }
    }

    return true;
}