#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M;
	vector<vector<int>> v1(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v1[i][j];
		}
	}
	cin >> M >> K;
	vector<vector<int>> v2(M, vector<int>(K));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> v2[i][j];
		}
	}

	vector<vector<int>> result(N, vector<int>(K));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < M; k++)
			{
				result[i][j] += v1[i][k] * v2[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}