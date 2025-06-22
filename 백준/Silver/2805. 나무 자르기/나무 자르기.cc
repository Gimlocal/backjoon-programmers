#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool Check(int value, int M, vector<ll>& v, vector<ll> s)
{
	ll start = 0, end = v.size() - 1;
	int idx = 0;
	while (start <= end)
	{
		ll mid = (start + end) / 2;
		if (v[mid] >= value)
		{
			idx = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	ll sum = s[v.size() - 1] - s[idx] + v[idx] - value * (v.size() - idx);
	return sum >= M;
}

int main()
{
	int N, M; cin >> N >> M;
	vector<ll> v(N);
	vector<ll> s(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		s[i] = v[i];
		if (i != 0) s[i] += s[i - 1];
	}

	ll start = 0, end = v[N - 1];
	int ans = 0;
	while (start <= end)
	{
		ll mid = (start + end) / 2;
		if (Check(mid, M, v, s))
		{
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	
	cout << ans;
}