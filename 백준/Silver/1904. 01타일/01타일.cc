#include <iostream>
#include <vector>

using namespace std;

long long count(int n) {
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    if (n == 0) return 0;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1] % 15746;
        dp[i][1] = dp[i - 1][0] % 15746 + dp[i - 1][1] % 15746;
    }

    return dp[n][0] + dp[n][1] % 15746;
}

int main() {
    int len; cin >> len;
    cout << count(len) % 15746;
}
