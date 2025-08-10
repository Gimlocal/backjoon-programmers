#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, K; cin >> N >> K;
	vector<int> v(100'001, 100'000);
	queue<int> q;
	v[N] = 0;
	q.push(N);

	while (!q.empty())
	{
		int num = q.front(); q.pop();
		if (num > 0 && v[num] + 1 < v[num - 1])
		{
			v[num - 1] = v[num] + 1;
			q.push(num - 1);
		}
		if (num < 100'000 && v[num] + 1 < v[num + 1])
		{
			v[num + 1] = v[num] + 1;
			q.push(num + 1);
		}
		if (num * 2 <= 100'000 && v[num] + 1 < v[num * 2])
		{
			v[num * 2] = v[num] + 1;
			q.push(num * 2);
		}
	}

	cout << v[K];
}