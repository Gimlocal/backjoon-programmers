#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string word; cin >> word;
	int num; cin >> num;
	vector<string> W(word.size());

	for (int i = 0; i < word.size(); i++) {
		if (i == 0) {
			W[i] = word[i];
		}
		else {
			W[i] = W[i - 1] + word[i];
		}
	}

	for (int i = 0; i < num; i++) {
		char ch; int begin, end;
		cin >> ch >> begin >> end;

		if (begin == 0) {
			cout << count(W[end].begin(), W[end].end(), ch) << "\n";
		}
		else {
			int a = count(W[end].begin(), W[end].end(), ch);
			int b = count(W[begin - 1].begin(), W[begin - 1].end(), ch);

			cout << max(0, a - b) << "\n";
		}
	}
}