#include <iostream>
#include <vector>
using namespace std;
using VVI = vector<vector<int>>;
using VI = vector<int>;

int MinCost(int i, int j, VI& sum, VVI& dp)
{
	if (dp[i][j] != 0) return dp[i][j];
	if (i == j) return 0;

	int result = 1'000'000'000;
	for (int a = i; a < j; a++)
	{
		result = min(MinCost(i, a, sum, dp) + MinCost(a + 1, j, sum, dp) + sum[j] - (i == 0 ? 0 : sum[i - 1]), result);
	}
	dp[i][j] = result;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int K; cin >> K;
		VI sum(K);
		cin >> sum[0];
		for (int j = 1; j < K; j++)
		{
			int a; cin >> a;
			sum[j] = a + sum[j - 1];
		}

		VVI dp(K, VI(K, 0));
		cout << MinCost(0, K - 1, sum, dp) << "\n";
	}
}