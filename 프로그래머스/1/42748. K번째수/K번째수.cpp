#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0;i < commands.size();i++) {
        vector<int> sortedArray;
        for (int j = commands[i][0]-1;j < commands[i][1];j++) {
            sortedArray.push_back(array[j]);
        }
        sort(sortedArray.begin(),sortedArray.end());
        answer.push_back(sortedArray[commands[i][2]-1]);
    }
    
    return answer;
}