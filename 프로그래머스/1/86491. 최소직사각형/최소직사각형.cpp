#include <vector>
using namespace std;

int solution(vector<vector<int>> vec) {
    for (auto& v : vec) {
        if (v[0] > v[1]) {
            int temp = v[0];
            v[0] = v[1];
            v[1] = temp;
        }
    }
    
    int row = 0; int col = 0;
    
    for (auto& v : vec) {
        row = max(row,v[0]);
        col = max(col,v[1]);
    }
    
    return row * col;
}