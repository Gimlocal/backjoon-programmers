#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> MultipleMatrix(const vector<vector<int>>& v1, const vector<vector<int>>& v2)
{
	int len = v1.size();
	vector<vector<int>> result(len, vector<int>(len, 0));
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				result[i][j] = ((result[i][j] % 1000) + (v1[i][k] * v2[k][j]) % 1000) % 1000;
			}
		}
	}
	return result;
}

vector<vector<int>> PowerMatrix(const vector<vector<int>>& origin, long long count)
{
	if (count == 1) return origin;
	if (count % 2 == 1)
	{
		return MultipleMatrix(origin, PowerMatrix(origin, count - 1));
	}
	else
	{
		return PowerMatrix(MultipleMatrix(origin, origin), count / 2);
	}
}

int main()
{
	int N;
	long long B;
	cin >> N >> B;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
			v[i][j] %= 1000;
		}
	}

	vector<vector<int>> result = PowerMatrix(v, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

}