#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, S; cin >> N >> S;
	vector<int> v(N);
	v.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int num; cin >> num;
		v[i] = num + v[i - 1];
	}

	int distStart = 0, distEnd = N , sum = 0, ans = 0;
	while (distStart <= distEnd)
	{
		int dist = (distStart + distEnd) / 2;
		int start = N - dist, end = N;
		bool flag = false;
		
		while (start >= 0)
		{
			sum = v[end] - v[start];
			if (sum >= S)
			{
				flag = true;
				break;
			}
			start--, end--;
		}
		
		if (flag)
		{
			distEnd = dist - 1;
			ans = dist;
		}
		else distStart = dist + 1;
	}

	cout << ans;
}
