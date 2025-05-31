#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M; cin >> M;
		priority_queue<int, vector<int>, greater<int>> lpq;
		priority_queue<int> gpq;
		vector<int> v;

		for (int j = 0; j < M; j++)
		{
			int num; cin >> num;
			if (j == 0) lpq.push(num);
			else
			{
				if (num >= lpq.top()) lpq.push(num);
				else gpq.push(num);
			}
			
			if (lpq.size() > gpq.size() + 1)
			{
				gpq.push(lpq.top());
				lpq.pop();
			}
			if (gpq.size() > lpq.size() + 1)
			{
				lpq.push(gpq.top());
				gpq.pop();
			}

			if (j % 2 == 0)
			{
				if (lpq.size() > gpq.size()) v.push_back(lpq.top());
				else if (gpq.size() > lpq.size()) v.push_back(gpq.top());
			}
		}

		cout << v.size();
		for (int j = 0; j < v.size(); j++)
		{
			if (j % 10 == 0) cout << "\n";
			cout << v[j] << " ";
		}
		cout << "\n";
	}
}