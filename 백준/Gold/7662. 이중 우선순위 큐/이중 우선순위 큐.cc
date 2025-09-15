#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		multiset<long long> ms;
		int k; cin >> k;
		for (int j = 0; j < k; j++)
		{
			char a; long long num;
			cin >> a >> num;
			if (a == 'I')
			{
				ms.insert(num);
			}
			else
			{
				if (!ms.empty()) 
				{
					multiset<long long>::iterator it = num == -1 ? 
						ms.begin() : --ms.end();
					ms.erase(it);
				}
			}
		}

		if (ms.empty()) cout << "EMPTY\n";
		else
		{
			cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
		}
	}
}