#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<pair<long long, long long>> v(N);
	long long a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v[i] = { a, b };
	}

	double cal1 = 0, cal2 = 0;
	for (int i = 0; i < N; i++)
	{
		cal1 += v[i].first * v[(i + 1) % N].second;
		cal2 += v[i].second * v[(i + 1) % N].first;
	}

	double area = (abs(cal1 - cal2) / 2);

	cout << fixed << setprecision(1) << area;
}