#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& E, int R, vector<bool>& C)
{
	C[R] = true;
	cout << R+1 << " ";
	for (int i = 0; i < E[R].size(); i++)
	{
		if (!C[E[R][i]]) dfs(E, E[R][i], C);
	}
}

void bfs(queue<int> Q, vector<vector<int>>& E, int R, vector<bool>& C)
{
	C[R] = true;
	cout << R+1 << " ";
	Q.push(R);

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < E[u].size(); i++)
		{
			if (!C[E[u][i]])
			{
				C[E[u][i]] = true;
				cout << E[u][i] + 1 << " ";
				Q.push(E[u][i]);
			}
		}
	}
}

int main()
{
	int V, M, R;
	cin >> V >> M >> R;
	vector<vector<int>> E(V);
	int start, end;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		E[start - 1].push_back(end - 1);
		E[end - 1].push_back(start - 1);
	}

	for (int i = 0; i < V; i++)
	{
		sort(E[i].begin(), E[i].end());
	}

	vector<bool> C1(V, false);
	vector<bool> C2(V, false);
	queue<int> Q;

	dfs(E, R - 1, C1);
	cout << "\n";
	bfs(Q, E, R - 1, C2);
}