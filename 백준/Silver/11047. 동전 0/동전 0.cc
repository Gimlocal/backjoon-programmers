#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K; cin >> N >> K;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int ans = 0;

	for (int i = N - 1; i >= 0; i--) {
		while (K - v[i] >= 0) {
			K -= v[i];
			ans++;
		}
		if (K == 0) break;
	}

	cout << ans;
}