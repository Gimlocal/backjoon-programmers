#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

pair<int,int> BFS(int start, vector<vector<pair<int, int>>>& W)
{
	queue<pair<int, int>> Q;
	vector<int> ret(W.size(), 0);
	vector<bool> c(W.size(), false);

	Q.push({ start, 0 });
	int idx;

	while (!Q.empty())
	{
		pair<int, int> p = Q.front(); Q.pop();
		idx = p.first; c[idx] = true;
		for (int i = 0; i < W[idx].size(); i++)
		{
			if (c[W[idx][i].first]) continue;
			ret[W[idx][i].first] = ret[idx] + W[idx][i].second;
			Q.push({ W[idx][i] });
		}
	}

	auto target = max_element(ret.begin(), ret.end());
	return { distance(ret.begin(), target), *target };
}

int main()
{
	int V; cin >> V;
	vector<vector<pair<int, int>>> W(V);
	for (int i = 0; i < V; i++)
	{
		int start, dest, cost;
		cin >> start;
		while (1)
		{
			cin >> dest;
			if (dest == -1) break;
			cin >> cost;
			W[start - 1].push_back({ dest - 1, cost });
		}
	}

	pair<int, int> pre = BFS(0, W);

	cout << BFS(pre.first, W).second;
}