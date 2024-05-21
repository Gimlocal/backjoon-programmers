#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	vector<int> vec(N);
	vector<int> v(N-K+1);

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	for (int i = 1; i < N; i++) {
		vec[i] += vec[i - 1];
	}

	for (int i = 0; i < N - K + 1; i++) {
		if (i == 0) {
			v[i] = vec[K-1];
		}
		else {
			v[i] = vec[i + K - 1] - vec[i-1];
		}
	}

	int maxNum = v[0];
	for (int i = 0; i < N - K + 1; i++) {
		maxNum = max(maxNum, v[i]);
	}

	cout << maxNum;
}