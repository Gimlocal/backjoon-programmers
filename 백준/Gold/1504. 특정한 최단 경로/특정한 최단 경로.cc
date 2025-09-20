#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
using G = vector<vector<pair<int, int>>>;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
const int MAX = numeric_limits<int>::max();

vector<int> dijkstra(G& g, int start)
{
	vector<int> dist(g.size(), MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();

		if (p.first > dist[p.second]) continue;

		for (auto& e : g[p.second])
		{
			if (dist[e.first] > dist[p.second] + e.second)
			{
				dist[e.first] = dist[p.second] + e.second;
				pq.push({ dist[e.first], e.first });
			}
		}
	}

	return dist;
}

int main()
{
	int N, E; cin >> N >> E;
	G g(N + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}

	int mid1, mid2; cin >> mid1 >> mid2;

	auto dist1 = dijkstra(g, 1);
	auto distMid1 = dijkstra(g, mid1);
	auto distMid2 = dijkstra(g, mid2);

	long long path1 = (long long)dist1[mid1] + distMid1[mid2] + distMid2[N];
	long long path2 = (long long)dist1[mid2] + distMid2[mid1] + distMid1[N];

	long long ans = min(path1, path2);
	if (ans >= MAX) cout << -1;
	else cout << ans;
}