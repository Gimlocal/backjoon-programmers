#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int C, N; cin >> C >> N;
	vector<int> cost(N), client(N);
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i] >> client[i];
	}

	vector<int> dp(C + 1, 10'000'000);
	dp[0] = 0;

	for (int i = 0; i <= C; i++)
	{
		if (dp[i] == 10'000'000) continue;
		for (int j = 0; j < N; j++)
		{
			int ni = min(C, i + client[j]);
			dp[ni] = min(dp[ni], dp[i] + cost[j]);
		}
	}

	cout << dp[C];
}