#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M; cin >> N >> M;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (i != 0) {
			arr[i] += arr[i - 1];
		}
	}

	
	for (int i = 0; i < M; i++) {
		int result = 0;
		int begin, end; cin >> begin >> end;

		if (begin == 1) {
			result = arr[end - 1];
		}
		else {
			result = arr[end - 1] - arr[begin - 2];
		}

		cout << result << "\n";
	}
}