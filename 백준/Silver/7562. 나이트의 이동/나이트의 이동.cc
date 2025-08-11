#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int diry[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T > 0)
	{
		T--;
		int I; cin >> I;
		vector<vector<int>> v(I, vector<int> (I, 1'000'000'000));
		queue<pair<int, int>> q;

		int startx, starty, destx, desty; 
		cin >> startx >> starty >> destx >> desty;

		v[startx][starty] = 0;
		q.push({ startx, starty });

		while (!q.empty())
		{
			auto p = q.front(); q.pop();
			for (int i = 0; i < 8; i++)
			{
				if (p.first + dirx[i] >= 0 && p.first + dirx[i] < I &&
					p.second + diry[i] >= 0 && p.second + diry[i] < I &&
					v[p.first][p.second] + 1 < v[p.first + dirx[i]][p.second + diry[i]])
				{
					v[p.first + dirx[i]][p.second + diry[i]] = v[p.first][p.second] + 1;
					q.push({ p.first + dirx[i], p.second + diry[i] });
				}
			}
		}

		cout << v[destx][desty] << "\n";
	}
}