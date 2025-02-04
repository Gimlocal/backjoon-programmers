#include <iostream>
#include <vector>
using namespace std;

int blue = 0;
int white = 0;

void check(vector<vector<int>> v, int startX, int startY, int endX, int endY)
{
	int startColor = v[startX][startY];
	bool ok = true;

	for (int i = startX; i < endX; i++)
	{
		for (int j = startY; j < endY; j++)
		{
			if (v[i][j] != startColor) ok = false;
		}
	}

	if (ok)
	{
		if (startColor == 0) white++;
		else blue++;
	}
	else
	{
		check(v, startX, startY, (startX + endX) / 2, (startY + endY) / 2);
		check(v, startX, (startY + endY) / 2, (startX + endX) / 2, endY);
		check(v, (startX + endX) / 2, startY, endX, (startY + endY) / 2);
		check(v, (startX + endX) / 2, (startY + endY) / 2, endX, endY);
	}
}

int main()
{
	int num; cin >> num;
	vector<vector<int>> v(num, vector<int>(num));

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> v[i][j];
		}
	}

	check(v, 0, 0, num, num);
	cout << white << "\n" << blue;
}