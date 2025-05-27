#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int K, N; cin >> K >> N;
	vector<int> lines(K);
	for (int i = 0; i < K; i++)
	{
		cin >> lines[i];
	}

	sort(lines.begin(), lines.end());

	long long count = 0, mid = 0, begin = 1, end = lines[K - 1], ans = 0;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		count = 0;
		for (int i = K - 1; i >= 0; i--)
		{
			count += lines[i] / mid;
		}

		if (count < N) end = mid - 1;
		else
		{
			ans = max(ans, mid);
			begin = mid + 1;
		}
	}

	cout << ans;
}