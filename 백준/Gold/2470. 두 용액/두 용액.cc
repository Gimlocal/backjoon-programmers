#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int start = 0, end = v.size()-1;
	int sum = 2'000'000'000;
	int val1 = 0, val2 = 0;

	while (start < end)
	{
		if (abs(v[start] + v[end]) < sum)
		{
			sum = abs(v[start] + v[end]);
			val1 = v[start], val2 = v[end];
			if (v[start] + v[end] > 0) end--;
			else if (v[start] + v[end] < 0) start++;
			else break;
		}
		else
		{
			if (v[start] + v[end] > 0) end--;
			else if (v[start] + v[end] < 0) start++;
			else break;
		}
	}

	cout << val1 << " " << val2;
}