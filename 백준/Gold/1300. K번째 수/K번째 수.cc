#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long N, k; cin >> N >> k;
	
	long long start = 1, end = N * N, ans = 0;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long count = 0;
		for (int i = 1; i <= N; i++) {
			count += min(mid / i, N);
		}
		if (count < k) start = mid + 1;
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}
	cout << ans;
}