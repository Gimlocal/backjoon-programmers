#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	vector<int> l;

	for (int i = 0; i < N; i++)
	{
		if (l.empty() || v[i] > l.back()) l.push_back(v[i]);
		else
		{
			int start = 0, end = l.size() - 1;
			int mid, idx;
			while (start <= end)
			{
				mid = (start + end) / 2;
				if (v[i] <= l[mid])
				{
					idx = mid;
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			l[idx] = v[i];
		}
	}

	cout << l.size();
}