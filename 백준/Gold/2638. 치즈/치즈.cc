#include <iostream>
#include <queue>
using namespace std;

void CheckAir(vector<vector<int>>& v, vector<vector<bool>>& air, queue<pair<int,int>> q)
{
	while (!q.empty())
	{
		pair<int, int> n = q.front();
		q.pop();

		if (air[n.first][n.second]) continue;
		air[n.first][n.second] = true;

		if (n.first > 0 && v[n.first - 1][n.second] == 0 && !air[n.first - 1][n.second])
			q.push({ n.first - 1, n.second });
		if (n.first < v.size() - 1 && v[n.first + 1][n.second] == 0 && !air[n.first + 1][n.second])
			q.push({ n.first + 1, n.second });
		if (n.second > 0 && v[n.first][n.second - 1] == 0 && !air[n.first][n.second - 1])
			q.push({ n.first, n.second - 1 });
		if (n.second < v[0].size() - 1 && v[n.first][n.second + 1] == 0 && !air[n.first][n.second + 1])
			q.push({ n.first, n.second + 1 });
	}
}

bool CheckCheese(const vector<vector<int>>& v, const vector<vector<bool>>& air, int i, int j)
{
	int count = 0;
	if (i > 0 && air[i - 1][j]) count++;
	if (i < v.size() - 1 && air[i + 1][j]) count++;
	if (j > 0 && air[i][j - 1]) count++;
	if (j < v[0].size() - 1 && air[i][j + 1]) count++;
	if (count >= 2) return true;
	return false;
}

bool CheckEmpty(vector<vector<int>>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[i][j] == 1) return false;
		}
	}
	return true;
}

int main()
{
	int N, M; cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
		}
	}

	int count = 0;
	vector<vector<bool>> air(N, vector<bool>(M));
	queue<pair<int, int>> q; q.push({ 0, 0 });
	CheckAir(v, air, q);
	while (!CheckEmpty(v))
	{
		count++;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[i][j] == 1 && CheckCheese(v, air, i, j))
				{
					v[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		
		CheckAir(v, air, q);
	}

	cout << count;
}