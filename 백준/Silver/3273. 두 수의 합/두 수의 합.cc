#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int x; cin >> x;

	sort(v.begin(), v.end());

	int start = 0, end = n - 1, count = 0;

	while (start < end)
	{
		if (v[start] + v[end] == x)
		{
			count++;
			start++, end--;
		}
		else if (v[start] + v[end] < x) start++;
		else end--;
	}

	cout << count;
}