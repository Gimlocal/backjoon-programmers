#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Check(vector<vector<char>>& V, int i, int j, vector<vector<queue<pair<int, int>>>>& E)
{
	int row = V.size();
	int col = V[0].size();
	if (i - 1 >= 0) if (V[i - 1][j] == '1') E[i][j].push(make_pair(i - 1, j));
	if (i + 1 < row) if (V[i + 1][j] == '1') E[i][j].push(make_pair(i + 1, j));
	if (j - 1 >= 0) if (V[i][j - 1] == '1') E[i][j].push(make_pair(i, j - 1));
	if (j + 1 < col) if (V[i][j + 1] == '1') E[i][j].push(make_pair(i, j + 1));
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
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int row, col, count;
		cin >> row >> col >> count;

		vector<vector<char>> V(row, vector<char>(col));
		for (int i = 0; i < count; i++)
		{
			int a, b;
			cin >> a >> b;

			V[a][b] = '1';
		}

		vector<vector<queue<pair<int, int>>>> E(row, vector<queue<pair<int, int>>>(col));
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (V[i][j] == '1')
					Check(V, i, j, E);
			}
		}

		vector<vector<bool>> B(row, vector<bool>(col, false));
		vector<int> ans;
		int len = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (V[i][j] == '1')
				{
					Search(V, i, j, E, B, len, ans);
					if (ans.size() > len) len++;
				}
			}
		}

		cout << ans.size() << "\n";
	}
}