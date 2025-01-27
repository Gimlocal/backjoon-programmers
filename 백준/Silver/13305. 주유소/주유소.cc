#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int lineNum;
	cin >> lineNum;
	vector<int> lv(lineNum - 1);
	vector<int> sv(lineNum);

	for (int i = 0; i < lineNum - 1; i++)
	{
		cin >> lv[i];
	}
	for (int i = 0; i < lineNum; i++)
	{
		cin >> sv[i];
	}

	int minCost = 1000000001;
	int result = 0;

	for (int i = 0; i < lineNum - 1; i++) 
	{
		minCost = min(sv[i], minCost);
		result += minCost * lv[i];
	}

	cout << result;
}