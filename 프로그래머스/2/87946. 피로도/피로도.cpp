#include <vector>
#include <algorithm>

using namespace std;

int maxDungeons = 0;

void exploreDungeons(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int dungeonCount) {
    maxDungeons = max(maxDungeons, dungeonCount);
    
    for (int i = 0; i < dungeons.size(); ++i) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            exploreDungeons(k - dungeons[i][1], dungeons, visited, dungeonCount + 1); 
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    maxDungeons = 0;
    
    exploreDungeons(k, dungeons, visited, 0);
    
    return maxDungeons;
}