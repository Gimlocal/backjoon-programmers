#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(queue<int> Q, vector<vector<int>>& E, int R, vector<bool>& C, vector<int>& A, int& count)
{
	C[R] = true;
	A[R] = count;
	count++;
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
				A[E[u][i]] = count;
				count++;
				Q.push(E[u][i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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

	vector<bool> C(V, false);
	vector<int> A(V, 0);
	int count = 1;
	queue<int> Q;

	bfs(Q, E, R - 1, C, A, count);

	for (int i = 0; i < V; i++)
	{
		cout << A[i] << "\n";
	}
}