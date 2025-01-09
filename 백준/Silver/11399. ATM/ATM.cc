#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num; cin >> num;
	vector<int> v(num);
	for (int i = 0; i < num; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int result = v[0];
	for (int i = 1; i < num; i++) 
	{
		v[i] += v[i - 1];
		result += v[i];
	}

	cout << result;
}