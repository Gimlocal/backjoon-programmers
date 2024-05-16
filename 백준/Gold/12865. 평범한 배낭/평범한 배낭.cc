#include <iostream>
#include <vector>

using namespace std;

int pack(int K, vector<pair<int, int>> v) {
	int N = v.size();
	vector<vector<int>> dp(N+1, vector<int>(K + 1,0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (v[i - 1].first <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[N][K];
}


int main() {
	int N, K; cin >> N >> K;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	cout << pack(K, v);
}