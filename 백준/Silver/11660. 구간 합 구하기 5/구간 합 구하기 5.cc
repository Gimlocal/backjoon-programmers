#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			v[i][j] += v[i][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int result = 0;

		for (int j = x1 - 1; j < x2; j++) {
			if (y1 == 1) {
				result += v[j][y2 - 1];
			}
			else {
				result += v[j][y2 - 1] - v[j][y1 - 2];
			}
		}

		cout << result << "\n";
	}
}