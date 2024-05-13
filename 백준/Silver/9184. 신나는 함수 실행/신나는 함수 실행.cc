#include <iostream>
#include <vector>

using namespace std;

int w(int a, int b, int c, vector<vector<vector<int>>>& dp) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20, dp);
    }

    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }

    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c - 1, dp) + w(a, b - 1, c - 1, dp) - w(a, b - 1, c, dp);
    }
    else {
        dp[a][b][c] = w(a - 1, b, c, dp) + w(a - 1, b - 1, c, dp) + w(a - 1, b, c - 1, dp) - w(a - 1, b - 1, c - 1, dp);
    }

    return dp[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<vector<int>>> dp(21, vector<vector<int>>(21, vector<int>(21, -1)));

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) { break; }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c, dp) << "\n";
    }

}
