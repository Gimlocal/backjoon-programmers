#include <iostream>
#include <map>
#include <set>
using namespace std;

void CheckCycle(map<int, int>& m, set<int>& ans, set<int>& check, int start)
{
	if (ans.find(start) != ans.end()) return;
	
	int count = m.size();
	int num = start;
	bool flag = false;

	while (count > 0)
	{
		count--;
		check.insert(start);
		if (m[start] == num)
		{
			flag = true;
			break;
		}
		start = m[start];
	}

	if (flag)
	{
		for (auto val : check)
		{
			ans.insert(val);
		}
	}

	check.clear();
}

int main()
{
	int N; cin >> N;
	map<int, int> m;
	set<int> ans;
	set<int> check;
	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		m[i + 1] = num;
	}

	for (int i = 0; i < N; i++)
	{
		CheckCycle(m, ans, check, i + 1);
	}

	cout << ans.size() << "\n";
	for (auto val : ans)
	{
		cout << val << "\n";
	}
}