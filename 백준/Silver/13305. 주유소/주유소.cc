#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int lineNum;
	cin >> lineNum;
	vector<long> lv(lineNum - 1);
	vector<long> sv(lineNum);

	for (int i = 0; i < lineNum - 1; i++)
	{
		cin >> lv[i];
	}
	for (int i = 0; i < lineNum; i++)
	{
		cin >> sv[i];
	}

	long minCost = 1000000001;
	long long result = 0;

	for (int i = 0; i < lineNum - 1; i++) 
	{
		minCost = min(sv[i], minCost);
		result += minCost * lv[i];
	}

	cout << result;
}