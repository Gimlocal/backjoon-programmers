#include <iostream>
#include <vector>
using namespace std;

vector<int> FindPrimeNum(int N)
{
    vector<int> ret;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
        if (isPrime[i]) ret.push_back(i);

    return ret;
}

int main()
{
	int N; cin >> N;
	vector<int> PN = FindPrimeNum(N);

    int left = 0, right = 0, sum = 0,count = 0;

    while (1)
    {
        if (sum >= N) sum -= PN[left++];
        else if (right == PN.size()) break;
        else sum += PN[right++];

        if (sum == N) count++;
    }

    cout << count;
}