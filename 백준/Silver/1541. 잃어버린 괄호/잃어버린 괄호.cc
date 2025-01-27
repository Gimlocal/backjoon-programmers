#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string a; cin >> a;
	string num = "";
	vector<int> v;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '+' && a[i] != '-')
		{
			num += a[i];
		}
		else
		{
			if (i != 0) v.push_back(stoi(num));
			num = "";
			if (a[i] == '+')
			{
				v.push_back(1);
			}
			else
			{
				v.push_back(-1);
			}
		}

		if (i == a.length() - 1) v.push_back(stoi(num));
	}

	vector<int> result;

	if (v[0] < 0)
	{
		for (int i = 0; i < v.size(); i = i + 2)
		{
			result.push_back(v[i] * v[i + 1]);
		}
	}
	else
	{
		result.push_back(v[0]);
		for (int i = 1; i < v.size(); i = i + 2)
		{
			result.push_back(v[i] * v[i + 1]);
		}
	}

	int answer = 0;
	bool flag = false;
	answer += result[0];
	flag = result[0] < 0 ? true : false;

	for (int i = 1; i < result.size(); i++)
	{
		if (result[i] < 0)
		{
			flag = true;
		}

		if (flag)
		{
			answer += -abs(result[i]);
		}
		else
		{
			answer += result[i];
		}
	}

	cout << answer;
}