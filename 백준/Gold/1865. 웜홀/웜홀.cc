#include <iostream>
#include <vector>
using namespace std;

#define INF 50000000

struct edge
{
	int a, b, c;
};

bool BF(int N, vector<edge>& E)
{
	vector<int> dist(N, INF);
	dist[0] = 0;
	int u, v, w;
	for (int i = 0; i < N; i++)
	{
		for (const auto& e : E)
		{
			u = e.a, v = e.b, w = e.c;
			if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
		}
	}
	for (const auto& e : E)
	{
		u = e.a, v = e.b, w = e.c;
		if (dist[u] + w < dist[v]) return true;
	}
	return false;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	int TC; cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		int N, M, W; cin >> N >> M >> W;
		vector<edge> E;
		int start, end, weight;
		for (int j = 0; j < M; j++)
		{
			cin >> start >> end >> weight;
			E.push_back({ start - 1, end - 1, weight });
			E.push_back({ end - 1, start - 1, weight });
		}
		for (int j = 0; j < W; j++)
		{
			cin >> start >> end >> weight;
			E.push_back({ start - 1, end - 1, -weight });
		}

		if (BF(N, E)) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}