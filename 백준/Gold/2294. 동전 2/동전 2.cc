#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	vector<int> dp(k + 1, k + 1);
	dp[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - coin[j] >= 0)
			{
				dp[i] = min(dp[i - coin[j]] + 1, dp[i]);
			}
		}
	}

	if (dp[k] == k + 1)
	{
		cout << -1;
	}
	else
	{
		cout << dp[k];
	}
} 