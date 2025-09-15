#include<iostream>
#include<stack>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int N; cin >> N;
	stack<pair<int, int>> s;
	vector<int> v(N);
	vector<int> ans(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	ans[0] = 0;
	s.push({ v[0], 1 });

	for (int i = 1; i < N; i++)
	{
		while (!s.empty())
		{
			if (s.top().first < v[i])
			{
				s.pop();
				if (s.empty())
				{
					s.push({ v[i], i + 1 });
					ans[i] = 0;
					break;
				}
			}
			else
			{
				ans[i] = s.top().second;
				s.push({ v[i], i + 1 });
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}