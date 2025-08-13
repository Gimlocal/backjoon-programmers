#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using V = vector<vector<int>>;
using Q = queue<pair<int, int>>;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void CheckAdj(V& v, Q& q, int i, int j)
{
	for (int a = 0; a < 4; a++)
	{
		int ny = i + dy[a];
		int nx = j + dx[a];
		if (ny >= 0 && ny < v.size() &&
			nx >= 0 && nx < v[0].size() &&
			v[ny][nx] == 0)
		{
			q.push({ ny, nx });
			v[ny][nx] = 1;
		}
	}
}

bool Check(V& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int BFS(V& v)
{
	int count = 0;
	Q q1;
	Q q2;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[i][j] == 1) q2.push({ i,j });
		}
	}

	do 
	{
		while (!q1.empty())
		{
			auto p = q1.front(); q1.pop();
			q2.push(p);
		}
		while (!q2.empty())
		{
			auto p = q2.front(); q2.pop();
			CheckAdj(v, q1, p.first, p.second);
		}
		if (!q1.empty()) count++;
	} 
	while (!q1.empty());

	return Check(v) ? count : -1;
}

int main()
{
	int M, N; cin >> M >> N;
	V v(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
		}
	}

	cout << BFS(v);
}