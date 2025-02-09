#include <iostream>
using namespace std;

int Multiple(int a, int b, int c)
{
	if (b == 1) return a % c;
	else if (b % 2 == 0) return Multiple(((long)(a % c) * (long)(a % c)) % c, b / 2, c);
	else if (b % 2 == 1) return ((long)Multiple(a, b - 1, c) * (long)(a % c)) % c;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << Multiple(a, b, c);
}