#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void checkAndAdd(int k, vector<vector<int>>& wires, vector<int>& v) {
    for (int i = 0; i < wires.size(); i++) {
        if (wires[i][0] == k && count(v.begin(),v.end(),wires[i][1]) == 0) {
            v.push_back(wires[i][1]);
            checkAndAdd(wires[i][1], wires, v);
        }
        if (wires[i][1] == k && count(v.begin(),v.end(),wires[i][0]) == 0) {
            v.push_back(wires[i][0]);
            checkAndAdd(wires[i][0], wires, v);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<int> v1;vector<int> v2;
        int a = wires[0][0];int b = wires[0][1];
        vector<int> v3;
        v1.push_back(a);v2.push_back(b);
        v3.push_back(a);v3.push_back(b);
        
        wires.erase(wires.begin());
        
        for (int j = 0; j < wires.size(); j++) {
            checkAndAdd(a, wires, v1);
            checkAndAdd(b, wires, v2);
        }
        
        answer = min(answer, abs((int)v1.size() - (int)v2.size()));
        wires.push_back(v3);
        
        v1.clear();v2.clear();v3.clear();
    }
    
    return answer;
}
