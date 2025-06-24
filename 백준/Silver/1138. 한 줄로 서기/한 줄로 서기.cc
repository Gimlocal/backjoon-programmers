#include <iostream>
#include <vector>
using namespace std;

bool check(int idx, int compare, int num, vector<int>& v)
{
	int count = 0;
	for (int i = 0; i <= compare; i++)
	{
		if (v[i] == 0 || v[i] > num) count++;
	}
	return count <= idx;
}

int main()
{
	int N; cin >> N;
	vector<int> v(N);
	int idx;
	for (int i = 0; i < N; i++)
	{
		cin >> idx;
		int num = idx;
		while (v[idx] != 0 || check(num, idx ,i+1, v))
			idx++;
		v[idx] = i + 1;
	}

	for (int i = 0; i < N; i++)
		cout << v[i] << " ";
}