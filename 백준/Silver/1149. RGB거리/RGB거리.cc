#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(vector<vector<int>>& cost, int houseNum) {
    vector<vector<int>> dp(houseNum, vector<int>(3, 1000000));

    for (int i = 0; i < 3; ++i) {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < houseNum; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j != k) {
                    dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][k]);
                }
            }
        }
    }

    return min(min(dp[houseNum - 1][0], dp[houseNum - 1][1]), dp[houseNum - 1][2]);
}

int main() {
    int houseNum;
    cin >> houseNum;

    vector<vector<int>> cost(houseNum, vector<int>(3));

    for (int i = 0; i < houseNum; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }

    int result = minCost(cost, houseNum);

    cout << result;

    return 0;
}
