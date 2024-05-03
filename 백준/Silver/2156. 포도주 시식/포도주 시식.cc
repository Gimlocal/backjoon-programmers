#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWine(vector<int>& wines) {
    int n = wines.size();
    vector<int> dp(n);

    dp[0] = wines[0];
    if (n > 1)
        dp[1] = wines[0] + wines[1];
    if (n > 2)
        dp[2] = max({ wines[0] + wines[2], wines[1] + wines[2], dp[1] });

    for (int i = 3; i < n; i++) {
        dp[i] = max({ wines[i] + wines[i - 1] + dp[i - 3], wines[i] + dp[i - 2], dp[i - 1] });
    }

    return dp[n - 1];
}

int main() {
    int n; cin >> n;
    vector<int> wines(n);

    for (int i = 0; i < n; ++i) {
        cin >> wines[i];
    }

    int maxAmount = maxWine(wines);
    cout << maxAmount;
}
