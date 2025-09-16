#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int V, vector<vector<int>>& E, int R, vector<bool>& C, vector<int>& A, int& count)
{
	C[R] = true;
	A[R] = count;
	count++;
	for (int i = 0; i < E[R].size(); i++)
	{
		if (!C[E[R][i]]) dfs(V, E, E[R][i], C, A, count);
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
		E[start-1].push_back(end-1);
		E[end - 1].push_back(start - 1);
	}
	
	for (int i = 0; i < V; i++)
	{
		sort(E[i].begin(), E[i].end());
	}

	vector<bool> C(V, false);
	vector<int> A(V, 0);
	int count = 1;

	dfs(V, E, R-1, C, A, count);

	for (int i = 0; i < V; i++)
	{
		cout << A[i] << "\n";
	}
}