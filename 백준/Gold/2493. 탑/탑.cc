#include<iostream>
#include<stack>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int N; cin >> N;
	stack<int> s;
	map<int, int> idx;
	vector<int> v(N);
	vector<int> ans(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		idx[v[i]] = i + 1;
	}

	ans[0] = 0;
	s.push(v[0]);

	for (int i = 1; i < N; i++)
	{
		while (!s.empty())
		{
			if (s.top() < v[i])
			{
				s.pop();
				if (s.empty())
				{
					s.push(v[i]);
					ans[i] = 0;
					break;
				}
			}
			else
			{
				ans[i] = idx[s.top()];
				s.push(v[i]);
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}