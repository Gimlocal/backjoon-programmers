#include <iostream>
#include <vector>
using namespace std;

int makeOneToNum(int num) {
	vector<int> dp(num+1, 0);

	for (int i = 2; i < num + 1; i++) {
		if (i % 3 == 0) {
			dp[i] = dp[i / 3] + 1;
		}

		if (i % 2 == 0) {
			if (dp[i] == 0) {
				dp[i] = dp[i / 2] + 1;
			}
			else dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if (dp[i] == 0) {
			dp[i] = dp[i - 1] + 1;
		}

		else dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	return dp[num];
}

int main() {
	int num; cin >> num;

	cout << makeOneToNum(num);
}