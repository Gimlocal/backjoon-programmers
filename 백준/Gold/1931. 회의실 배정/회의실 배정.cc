#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sorts(vector<int> a, vector<int> b)
{
	if (a[1] == b[1]) return a[0] < b[0];
	return a[1] < b[1];
}

int main()
{
	int len;
	cin >> len;
	vector<vector<int>> v(len, vector<int> (2));

	for (int i = 0; i < len; i++) 
	{
		cin >> v[i][0] >> v[i][1];
	}

	sort(v.begin(), v.end(), sorts);

	int time = v[0][1];
	int result = 1;

	for (int i = 1; i < len; i++)
	{
		if (v[i][0] >= time)
		{
			time = v[i][1];
			result++;
		}
	}

	cout << result;
}