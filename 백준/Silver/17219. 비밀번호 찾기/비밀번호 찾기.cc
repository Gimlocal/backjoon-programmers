#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	map<string, string> m;
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string key, val;
		cin >> key >> val;
		m[key] = val;
	}

	for (int i = 0; i < M; i++)
	{
		string key; cin >> key;
		cout << m[key] << "\n";
	}
}