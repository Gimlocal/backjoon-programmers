#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    set<string> s;
    map<string,int> m;
    
    for (int i = 0;i < clothes.size();i++) {
        s.insert(clothes[i][1]);
        m[clothes[i][1]]++;
    }
    
    int com = 1;
    for (auto& ele : s) {
        com *= m[ele]+1;
    }

    return com-1;
}