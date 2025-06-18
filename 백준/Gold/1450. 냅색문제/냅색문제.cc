#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<ll> MITM(vector<ll> v)
{
	vector<ll> ret;
	for (int i = 0; i < (1 << v.size()); i++)
	{
		ll sum = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (i & (1 << j)) sum += v[j];
		}
		ret.push_back(sum);
	}
	return ret;
}

int main()
{
	ll N, C; cin >> N >> C;
	vector<ll> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	vector<ll> v1; vector<ll> v2;
	for (int i = 0; i < N; i++)
	{
		if (i <= N / 2) v1.push_back(v[i]);
		else v2.push_back(v[i]);
	}

	vector<ll> sub1 = MITM(v1);
	vector<ll> sub2 = MITM(v2);
	sort(sub2.begin(), sub2.end());

	ll count = 0;

	for (int i = 0; i < sub1.size(); i++)
	{
		int start = 0, end = sub2.size() - 1;
		int idx = -1;
		ll target = C - sub1[i];

		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (sub2[mid] <= target) {
				idx = mid;      
				start = mid + 1; 
			}
			else {
				end = mid - 1;
			}
		}
		if (idx != -1) count += idx + 1;
	}

	cout << count;
}