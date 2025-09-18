#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	int X, A;
	vector<pair<int, int>> v;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> A;
		sum += A;
		v.push_back({ X, A });
	}

	sort(v.begin(), v.end());

	long long count = 0, half = (sum + 1) / 2, idx = v[0].first;
	for (auto p : v)
	{
		count += p.second;
		if (count >= half)
		{
			idx = p.first;
			break;
		}
	}

	cout << idx;
}