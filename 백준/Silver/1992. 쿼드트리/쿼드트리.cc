#include <iostream>
#include <vector>
#include <string>
using namespace std;

void QuadTree(vector<vector<int>> v, int startX, int startY, int endX, int endY)
{
	int startColor = v[startX][startY];
	bool flag = true;
	for (int i = startX; i < endX; i++)
	{
		for (int j = startY; j < endY; j++)
		{
			if (v[i][j] != startColor) flag = false;
		}
	}

	if (flag) cout << startColor;
	else
	{
		cout << "(";
		QuadTree(v, startX, startY, (startX + endX) / 2, (startY + endY) / 2);
		QuadTree(v, startX, (startY + endY) / 2, (startX + endX) / 2, endY);
		QuadTree(v, (startX + endX) / 2, startY, endX, (startY + endY) / 2);
		QuadTree(v, (startX + endX) / 2, (startY + endY) / 2, endX, endY);
		cout << ")";
	}
}

int main()
{
	int num; cin >> num;
	vector<string> strings(num);
	vector<vector<int>> ints(num, vector<int>(num));

	for (int i = 0; i < num; i++)
	{
		cin >> strings[i];
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			ints[i][j] = strings[i][j] - '0';
		}
	}

	QuadTree(ints, 0, 0, num, num);
}