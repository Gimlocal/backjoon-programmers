#include <iostream>
#include <vector>
using namespace std;
using VP = vector<pair<int, int>>;
using V = vector<vector<int>>;

int MinCost(int i, int j, VP& v, V& dp)
{
	if (dp[i][j] != 0) return dp[i][j];
	if (i == j) return 0;

	int result = 2'147'483'647;
	for (int a = i; a < j; a++)
	{
		result = min(MinCost(i, a, v, dp) + MinCost(a + 1, j, v, dp) + v[i].first * v[a].second * v[j].second, result);
	}
	dp[i][j] = result;

	return result;
}

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

	V dp(N, vector<int>(N, 0));

	cout << MinCost(0, N - 1, v, dp);
}