#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> dividers;
    int divide = 1;
    
    while (divide <= yellow) {
        if (yellow % divide == 0) dividers.push_back(divide);
        divide++;
    }
    
    int i = 0;int j = dividers.size()-1;
    while (i <= j) {
        if ((2*dividers[i] + 2*(dividers[j]+2)) == brown) {
            answer.push_back(dividers[j]+2);
            answer.push_back(dividers[i]+2);
            break;
        }
        i++;j--;
    }
    
    return answer;
}