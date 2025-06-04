#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int INF = numeric_limits<int>::max();

vector<int> Dijkstra(int start, vector<vector<PII>>& g)
{
	int n = g.size();
	vector<int> dist(n, INF);
	priority_queue < PII, vector<PII>, greater<PII>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curDist = pq.top().first; int curNode = pq.top().second;
		pq.pop();

		if (curDist > dist[curNode]) continue;

		for (auto& nb : g[curNode])
		{
			int node = nb.first; int weight = nb.second;
			int newDist = curDist + weight;

			if (newDist < dist[node])
			{
				dist[node] = newDist;
				pq.push({ newDist, node });
			}
		}
	}

	return dist;
}

int main()
{
	int N, M, X; cin >> N >> M >> X;
	vector<vector<PII>> g(N);
	for (int i = 0; i < M; i++)
	{
		int start, end, cost; cin >> start >> end >> cost;
		g[start - 1].push_back({ end - 1, cost });
	}

	vector<int> dist(N);
	for (int i = 0; i < N; i++)
	{
		dist[i] = Dijkstra(i, g)[X - 1];
	}
	vector<int> backDist = Dijkstra(X - 1, g);
	for (int i = 0; i < N; i++)
	{
		dist[i] += backDist[i];
	}

	cout << *max_element(dist.begin(), dist.end());
}