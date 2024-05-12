#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    
    for (const string& p : participant) {
        m[p]++;
    }
    
    for (const string& c : completion) {
        m[c]--;
    }
    
    for (const auto& pair : m) {
        if (pair.second != 0) {
            answer = pair.first;
            break;
        }
    }
    
    return answer;
}
