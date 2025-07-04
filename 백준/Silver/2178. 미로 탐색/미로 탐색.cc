#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef vector<vector<int>> V;
typedef queue<pair<int, int>> Q;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void Check(V& v, V& dist, Q& q,int x, int y)
{
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < v.size() && ny >= 0 && ny < v[0].size() && v[nx][ny] == 1)
		{
			if (dist[nx][ny] == 0 || dist[nx][ny] > dist[x][y] + 1)
			{
				q.push({nx, ny});
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int BFS(V& v)
{
	V dist(v.size(), vector<int>(v[0].size(), 0));
	Q q;
	dist[0][0] = 1;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		auto p = q.front(); q.pop();
		Check(v, dist, q, p.first, p.second);
	}
	return dist[v.size() - 1][v[0].size() - 1];
}

int main()
{
	int N, M; cin >> N >> M;
	V v(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		string a; cin >> a;
		for (int j = 0; j < M; j++)
		{
			v[i][j] = a[j] - '0';
		}
	}

	cout << BFS(v);
}