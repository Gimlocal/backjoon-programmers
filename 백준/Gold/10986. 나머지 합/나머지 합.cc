#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    unordered_map<int, int> m;
    m[0] = 1;

    long long sum = 0;
    long long result = 0;

    for (int i = 1; i <= N; ++i) {
        sum += v[i - 1];
        int mod = sum % M;
        if (mod < 0) mod += M;

        if (m.find(mod) != m.end()) {
            result += m[mod];
        }
        m[mod]++;
    }

    cout << result;
}
