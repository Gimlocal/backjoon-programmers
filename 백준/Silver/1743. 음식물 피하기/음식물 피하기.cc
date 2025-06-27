#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<vector<bool>> V;
typedef queue<pair<int, int>> Q;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void FindAndPush(int x, int y, V& v, Q& q)
{
	for (int dir = 0; dir < 4; ++dir) 
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < v.size() && ny >= 0 && ny < v[0].size())
		{
			if (v[nx][ny])
			{
				q.push({ nx, ny });
				v[nx][ny] = false;
			}
		}
	}
}

int BFS(int x, int y, V& v)
{
	int area = 1;
	v[x][y] = false;
	Q q;
	FindAndPush(x, y, v, q);

	while (!q.empty())
	{
		pair<int, int> p = q.front(); q.pop();
		area++;
		FindAndPush(p.first, p.second, v, q);
	}

	return area;
}

int main()
{
	int N, M, K; cin >> N >> M >> K;
	V v(N, vector<bool>(M, false));
	vector<int> ans;

	int x, y;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		v[x - 1][y - 1] = true;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!v[i][j]) continue;
			ans.push_back(BFS(i, j, v));
		}
	}

	cout << *max_element(ans.begin(), ans.end());
}