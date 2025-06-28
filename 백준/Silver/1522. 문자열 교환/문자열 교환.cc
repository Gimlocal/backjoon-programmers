#include <iostream>
using namespace std;

int main()
{
	string a; cin >> a;
	string b = a + a;
	int counta = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == 'a') counta++;
	if (counta == 0)
	{
		cout << 0; return 0;
	}

	int start = 0, end = counta - 1;
	int ans = 1000;
	while (end <= b.size() - 1)
	{
		int countb = 0;
		for (int i = start; i <= end; i++)
			if (b[i] == 'b') countb++;
		start++, end++;
		ans = min(ans, countb);
	}

	cout << ans;
}