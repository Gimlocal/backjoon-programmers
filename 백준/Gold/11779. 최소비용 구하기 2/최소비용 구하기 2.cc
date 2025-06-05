#include <iostream>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

typedef pair<int, int> PII;
const int INF = numeric_limits<int>::max();

int Dijkstra(int start, int end, vector<vector<PII>>& G, vector<int>& A)
{
	vector<int> dist(G.size(), INF);
	priority_queue<PII, vector<PII>, greater<PII>> pq;

	dist[start] = 0;
	pq.push({ 0, start });
	if (start == end) return 0;

	while (!pq.empty())
	{
		int curDist = pq.top().first, curNode = pq.top().second; pq.pop();

		if (curDist > dist[curNode]) continue;

		for (auto& p : G[curNode])
		{
			int newNode = p.first, weight = p.second, newDist = curDist + weight;
			if (newDist < dist[newNode])
			{
				A[newNode] = curNode;
				dist[newNode] = newDist;
				pq.push({ newDist, newNode });
			}
		}
	}

	return dist[end];
}

int main()
{
	int N, M; cin >> N >> M;

	vector<vector<PII>> G(N);
	for (int i = 0; i < M; i++)
	{
		int start, end, weight; cin >> start >> end >> weight;
		G[start - 1].push_back({ end - 1, weight });
	}

	int start, end; cin >> start >> end;
	vector<int> trace(N); vector<int> ans;

	cout << Dijkstra(start - 1, end - 1, G, trace) << "\n";
	int num = end - 1;

	while (num != start - 1)
	{
		ans.push_back(num);
		num = trace[num];
	}
	ans.push_back(start - 1);

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[ans.size() - 1 - i] + 1 << " ";
}