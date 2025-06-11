#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	}
};

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;
	priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> pq;
	int M, V;

	for (int i = 0; i < N; i++)
	{
		cin >> M >> V;
		pq.push({ M , V });
	}

	multiset<int> m;
	int c;
	for (int i = 0; i < K; i++)
	{
		cin >> c;
		m.insert(c);
	}


	long long sum = 0;
	while (!pq.empty() && !m.empty())
	{
		int weight = pq.top().first, value = pq.top().second;
		pq.pop();

		auto it = m.lower_bound(weight);
		if (it != m.end())
		{
			sum += value;
			m.erase(it);
		}
	}

	cout << sum;
}