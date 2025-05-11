#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void Check(vector<vector<char>>& V, int i, int j, vector<vector<queue<pair<int, int>>>>& E)
{
	int len = V.size();
	if (i - 1 >= 0) if (V[i - 1][j] == '1') E[i][j].push(make_pair(i - 1, j));
	if (i + 1 < len) if (V[i + 1][j] == '1') E[i][j].push(make_pair(i + 1, j));
	if (j - 1 >= 0) if (V[i][j - 1] == '1') E[i][j].push(make_pair(i, j - 1));
	if (j + 1 < len) if (V[i][j + 1] == '1') E[i][j].push(make_pair(i, j + 1));
}

void Search(vector<vector<char>>& V, int i, int j, vector<vector<queue<pair<int, int>>>>& E, vector<vector<bool>>& B, int len, vector<int>& ans)
{
	if (!B[i][j])
	{
		Check(V, i, j, E);
		B[i][j] = true;
		if (ans.empty() || ans.size() - 1 < len) ans.push_back(0);
		ans[len]++;
		while (!E[i][j].empty())
		{
			pair<int, int> p = E[i][j].front();
			E[i][j].pop();
			Search(V, p.first, p.second, E, B, len, ans);
		}
	}
}

int main()
{
	int N; cin >> N;
	vector<string> v1(N);
	vector<vector<char>> V(N, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		cin >> v1[i];
		for (int j = 0; j < N; j++)
		{
			V[i][j] = v1[i][j];
		}
	}

	vector<vector<queue<pair<int, int>>>> E(N, vector<queue<pair<int, int>>>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (V[i][j] == '1')
				Check(V, i, j, E);
		}
	}

	vector<vector<bool>> B(N, vector<bool>(N, false));
	vector<int> ans;
	int len = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (V[i][j] == '1')
			{
				Search(V, i, j, E, B, len, ans);
				if (ans.size() > len) len++;
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}