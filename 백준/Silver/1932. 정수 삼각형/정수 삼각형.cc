#include <iostream>
#include <vector>
using namespace std;

void sum(vector<vector<int>>& v, int num) {
	for (int i = 1; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) v[i][j] += v[i - 1][j];
			else if (j == i) v[i][j] += v[i-1][j-1];
			else {
				v[i][j] = max(v[i-1][j-1], v[i-1][j]) + v[i][j];
			}
		}
	}
	return;
}

int main() {
	int line; cin >> line;
	vector<vector<int>> v(line, vector<int>(line));

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < i+1; j++) {
			int num; cin >> num;
			v[i][j] = num;
		}
	}

	sum(v, line);

	int maxNum = 0;
	for (int i = 0; i < line; i++) {
		maxNum = max(v[line - 1][i], maxNum);
	}

	cout << maxNum;
}