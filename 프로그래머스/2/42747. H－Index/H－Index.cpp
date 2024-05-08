#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    
    for (int i = 1;i < citations[citations.size()-1];i++) {
        if (citations.size() >= i) {
            if (citations[citations.size()-i] >= i) {
                answer = max(answer,i);
            }
        }
        else break;
    }
    
    return answer;
}