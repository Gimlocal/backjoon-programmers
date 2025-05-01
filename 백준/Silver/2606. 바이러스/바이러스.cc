#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(queue<int> Q, vector<vector<int>>& E, int R, vector<bool>& C, vector<int>& A)
{
	C[R] = true;
	A[R] = 1;
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
				A[E[u][i]] = 1;
				Q.push(E[u][i]);
			}
		}
	}
}

int main()
{
	int V, M;
	cin >> V >> M;
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

	vector<bool> C(V, false);
	vector<int> A(V, 0);
	queue<int> Q;

	bfs(Q, E, 0, C, A);

	int result = 0;
	for (int i = 0; i < V; i++)
	{
		result += A[i];
	}

	cout << result - 1;
}