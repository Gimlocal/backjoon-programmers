#include <iostream>
#include <vector>

using namespace std;

int main() {
	int digits; cin >> digits;

	vector<vector<long long>> v(digits, vector<long long>(10, 0));

	for (int i = 1; i < 10; i++) {
		v[0][i] = 1;
	}

	if (digits > 1) {
		for (int i = 1; i < digits; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 1) {
					if (j == 0 || j == 1 || j == 9) {
						v[i][j] = 1;
					}
					else {
						v[i][j] = 2;
					}
				}
				else {
					if (j == 0) v[i][j] = (v[i - 1][j + 1]) % 1000000000;
					else if (j == 9) (v[i][j] = v[i - 1][j - 1]) % 1000000000;
					else v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % 1000000000;
				}
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += v[digits-1][i] % 1000000000;
	}

	cout << sum % 1000000000;
}