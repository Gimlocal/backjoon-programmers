#include <iostream>
#include <vector>
using namespace std;
using V = vector<vector<pair<int, int>>>;

pair<int, int> dfs(V& v, vector<bool>& check, int start)
{
	check[start] = true;
	auto max = make_pair(start, 0);

	for (auto& p : v[start])
	{
		if (check[p.first]) continue;

		auto result = dfs(v, check, p.first);
		result.second += p.second;

		if (result.second > max.second)
		{
			max = result;
		}
	}

	return max;
}

int main()
{
	int n; cin >> n;
	V v(n + 1);
	vector<bool> check(n + 1);

	int start, end, w;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> start >> end >> w;
		v[start].push_back({ end, w });
		v[end].push_back({ start, w });
	}

	auto p = dfs(v, check, 1);
	fill(check.begin(), check.end(), false);
	auto max = dfs(v, check, p.first);

	cout << max.second;
}