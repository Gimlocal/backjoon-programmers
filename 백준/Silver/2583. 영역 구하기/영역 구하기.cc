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
	int M, N, K; cin >> M >> N >> K;
	V v(M, vector<bool>(N, true));
	vector<int> ans;

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				v[k][j] = false;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!v[i][j]) continue;
			ans.push_back(BFS(i, j, v));
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto it = ans.begin(); it != ans.end(); ++it) cout << *it << " ";
}