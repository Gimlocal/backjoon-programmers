#include <iostream>
#include <map>`
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		string a; int len;
		cin >> a >> len;

		map<char, queue<int>> m;
		int min = a.size(), max = 0;
		bool flag = false;

		for (int j = 0; j < a.size(); j++)
		{
			m[a[j]].push(j);

			if (m[a[j]].size() == len)
			{
				flag = true;
				if (m[a[j]].back() - m[a[j]].front() + 1 < min) 
				{
					min = m[a[j]].back() - m[a[j]].front() + 1;
				}
				if (m[a[j]].back() - m[a[j]].front() + 1 > max)
				{
					max = m[a[j]].back() - m[a[j]].front() + 1;
				}
				m[a[j]].pop();
			}
		}

		if (flag)
		{
			cout << min << " " << max << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
}