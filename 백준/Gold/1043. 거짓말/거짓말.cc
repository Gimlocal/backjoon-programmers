#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void DFS(const vector<vector<int>>& E, int index, unordered_set<int>& s)
{
	s.insert(index);
	for (int a : E[index])
	{
		if (s.find(a) == s.end()) DFS(E, a, s);
	}
	return;
}

int main()
{
	int N, M; cin >> N >> M;
	int num; cin >> num;
	vector<int> knows;
	for (int i = 0; i < num; i++)
	{
		int per; cin >> per;
		knows.push_back(per - 1);
	}

	vector<vector<int>> E(N);
	vector<vector<int>> R(M);
	for (int i = 0; i < M; i++)
	{
		int k; cin >> k;
		vector<int> link;
		for (int j = 0; j < k; j++) 
		{
			int input; cin >> input;
			R[i].push_back(input - 1);
			link.push_back(input - 1);
		}
		for (int j = 0; j < k - 1; j++)
		{
			E[link[j]].push_back(link[j + 1]);
			E[link[j + 1]].push_back(link[j]);
		}
	}

	unordered_set<int> s;
	for (int i = 0; i < num; i++)
	{
		if (s.find(knows[i]) == s.end()) 
		{
			DFS(E, knows[i], s);
		}
	}

	int ans = 0;

	for (int i = 0; i < M; i++)
	{
		bool flag = true;
		for (int j = 0; j < R[i].size(); j++)
		{
			if (s.find(R[i][j]) != s.end())
			{
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}

	cout << ans;
}