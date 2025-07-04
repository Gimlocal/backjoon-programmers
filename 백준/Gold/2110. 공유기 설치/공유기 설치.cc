#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Check(vector<int>& v, int C, int stand)
{
	int lastIdx = 0;
	C--;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - v[lastIdx] >= stand)
		{
			lastIdx = i;
			C--;
		}
	}
	return C <= 0;
}

int main()
{
	int N, C; cin >> N >> C;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int start = 0, end = v.back();
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (Check(v, C, mid))
		{
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << ans;
}