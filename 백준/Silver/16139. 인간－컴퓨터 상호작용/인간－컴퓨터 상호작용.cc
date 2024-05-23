#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S; int q;
	cin >> S >> q;

	int size = S.size();

	vector<vector<int>> v(26, vector<int>(200000, 0));

	for (int i = 0; i < 26; i++) {
		v[i][0] = ((S[0] - 97) == i);
		for (int j = 1; j < size; j++) {
			v[i][j] = v[i][j - 1] + ((S[j] - 97) == i);
		}
	}

	char alpha; int l, r;
	
	for (int i = 0; i < q; i++) {
		cin >> alpha >> l >> r;

		if (l == 0) {
			cout << v[alpha - 97][r] << "\n";
		}
		else {
			cout << v[alpha - 97][r] - v[alpha - 97][l - 1] << "\n";
		}
	}
}