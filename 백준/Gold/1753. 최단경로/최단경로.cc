#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main()
{
	int V, E; cin >> V >> E;
	int K; cin >> K;
	vector<vector<pair<int, int>>> G(V + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({ v, w });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(V + 1, numeric_limits<int>::max());

	dist[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();

		if (p.first > dist[p.second]) continue;

		for (auto& e : G[p.second])
		{
			if (dist[e.first] > dist[p.second] + e.second)
			{
				dist[e.first] = dist[p.second] + e.second;
				pq.push({ dist[e.first], e.first });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == numeric_limits<int>::max())
		{
			cout << "INF\n";
		}
		else
		{
			cout << dist[i] << "\n";
		}
	}
}