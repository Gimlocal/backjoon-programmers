#include <iostream>
#include <vector>
using namespace std;

void maxSum(const vector<int>& v, vector<vector<int>>& vec, int stairNum) {
    vec[0][0] = v[0];
    if (stairNum > 1) {
        vec[1][0] = v[1];
        vec[1][1] = v[0] + v[1];
    }

    for (int i = 2; i < stairNum; i++) {
        vec[i][0] = max(vec[i - 2][0], vec[i - 2][1]) + v[i];
        vec[i][1] = vec[i - 1][0] + v[i];
    }
}

int main() {
    int stairNum;
    cin >> stairNum;

    vector<int> v(stairNum);
    for (int i = 0; i < stairNum; i++) {
        cin >> v[i];
    }

    vector<vector<int>> vec(stairNum, vector<int>(2, 0));

    maxSum(v, vec, stairNum);

    cout << max(vec[stairNum - 1][0], vec[stairNum - 1][1]);
}
