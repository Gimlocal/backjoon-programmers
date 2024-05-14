#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool sorting(string a, string b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    unordered_set<string> set;
    
    sort(phone_book.begin(),phone_book.end(),sorting);
    
    set.insert(phone_book[0]);
    for (int i = 1;i < phone_book.size();i++) {
        string check = "";
        for (int j = 0;j < phone_book[i].size();j++) {
            check += phone_book[i][j];
            if (set.count(check) == 1)
                return false;
        }
        set.insert(phone_book[i]);
    }
    return true;
}