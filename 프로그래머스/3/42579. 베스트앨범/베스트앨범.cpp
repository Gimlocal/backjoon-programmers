#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m;
    vector<pair<string,int>> v;
    vector<int> flag(genres.size(),0);
    
    int size = genres.size();
    
    for (int i = 0;i < size;i++) {
        m[genres[i]] += plays[i];
    }
    
    for (auto& ele : m) {
        v.push_back(ele);
    }
    
    sort(v.begin(),v.end(),sorting);
    
    for (int i = 0;i < v.size();i++) {
        for (int k = 0;k < 2;k++) {
            int max = -1;
            int index = 0;
            
            for (int j = 0;j < size;j++) {
                if (genres[j] == v[i].first) {
                    if (max < plays[j]) {
                        max = plays[j];
                        index = j;
                    }
                }
            }
            
            if (flag[index] == 0) {
                answer.push_back(index);
                flag[index] = 1;
                plays[index] = 0;
            }
        }
    }
    
    return answer;
}