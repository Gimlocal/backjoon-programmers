#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int>& v, int len, int target)
{
	int begin = 0, end = len - 1;
	
	while (begin <= end)
	{
		int mid = (begin + end) / 2;

		if (target == v[mid]) return 1;
		if (target < v[mid]) end = mid - 1;
		else begin = mid + 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		int target; cin >> target;
		cout << BinarySearch(v, v.size(), target) << "\n";
	}
}