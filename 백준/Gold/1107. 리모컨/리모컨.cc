#include <iostream>
#include <unordered_set>
using namespace std;

bool CheckNum(unordered_set<int>& s, int num)
{
	do
	{
		int end = num % 10;
		num /= 10;
		if (s.empty() || s.find(end) == s.end()) return false;
	} while (num > 0);
	return true;
}

int main()
{
	int N, M; cin >> N >> M;

	unordered_set<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.insert(i);
	}

	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		if (s.find(num) != s.end()) s.erase(num);
	}

	int num = 0, diff = 1000000;
    bool flag = false;
	for (int i = 0; i < N + 500000; i++)
	{
		if (CheckNum(s, i) && abs(N - i) < diff)
		{
			diff = abs(N - i);
			num = i;
            flag = true;
		}
	}

	int val = num, count = 0;
	do
	{
		val /= 10;
		count++;
	} while (val > 0);
    
    if (!flag) cout << abs(N - 100);
	else cout << min(abs(N - 100), count + abs(N - num));
}