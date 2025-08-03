#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<pair<int, int>> v(N);
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}

	vector<vector<int>> dp(N, vector<int>(N, 0));

	for (int len = 2; len <= N; ++len)
	{
		for (int i = 0; i <= N - len; ++i)
		{
			int j = i + len - 1;
			dp[i][j] = INT_MAX;

			for (int k = i; k < j; ++k)
			{
				int cost = dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second * v[j].second;
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}

	cout << dp[0][N - 1];
}