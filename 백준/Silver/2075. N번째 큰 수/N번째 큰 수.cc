#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	int num;
	for (int i = 0; i < N * N; i++)
	{
		cin >> num;
		pq.push(num);
		if (pq.size() > N) pq.pop();
	}

	cout << pq.top();
}