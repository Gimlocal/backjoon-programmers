#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX = 4000000;

vector<long long> factorial(MAX + 1);
vector<long long> inverse(MAX + 1);

long long Power(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

void Precompute()
{
    factorial[0] = 1;
    for (int i = 1; i <= MAX; ++i)
        factorial[i] = (factorial[i - 1] * i) % MOD;

    inverse[MAX] = Power(factorial[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; --i)
        inverse[i] = (inverse[i + 1] * (i + 1)) % MOD;
}

long long Binomial(int N, int K)
{
    if (K < 0 || K > N) return 0;
    return factorial[N] * inverse[K] % MOD * inverse[N - K] % MOD;
}

int main()
{
    int N, K;
    cin >> N >> K;

    Precompute();
    cout << Binomial(N, K);
}
