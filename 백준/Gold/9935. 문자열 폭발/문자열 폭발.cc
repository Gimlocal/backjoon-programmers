#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b; cin >> a >> b;
	string ans = "";
	for (int i = 0; i < a.size(); i++)
	{
		ans += a[i];
		if (a[i] == b.back() && ans.size() >= b.size())
		{
			string c = ans.substr(ans.size() - b.size(), b.size());
			if (c == b)
			{
				ans.erase(ans.size() - b.size());
			}
		}
	}

	if (ans == "")
	{
		cout << "FRULA";
		return 0;
	}
	cout << ans;
}