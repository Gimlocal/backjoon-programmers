#include <iostream>
#include <map>

using namespace std;

const int divide = 1000000007;
map<long long, int> m;

long long Fibonacci(long long n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;

	if (m[n] != 0) return m[n];

	if (n % 2 == 1)
	{
		long long a = (n - 1) / 2;
		m[n] = ((Fibonacci(a + 1) % divide) * (Fibonacci(a + 1) % divide) + (Fibonacci(a) % divide) * (Fibonacci(a) % divide)) % divide;
		return m[n];
	}
	else
	{
		long long a = n / 2;
		m[n] = ((Fibonacci(a) % divide) * (((Fibonacci(a + 1) % divide) + (Fibonacci(a - 1) % divide)) % divide)) % divide;
		return m[n];
	}
}

int main()
{
	long long n;
	cin >> n;

	cout << Fibonacci(n);
}