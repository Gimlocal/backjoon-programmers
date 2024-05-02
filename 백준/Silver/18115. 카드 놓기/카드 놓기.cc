#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {
	int num; cin >> num;
	vector<int> v(num);
	queue<int> card;
	deque<int> dq;

	for (int i = 0; i < num; i++) {
		cin >> v[i];
		card.push(i+1);
	}

	for (int i = num - 1; i >= 0; i--) {
		if (v[i] == 1) {
			dq.push_front(card.front());
			card.pop();
		}

		else if (v[i] == 2) {
			int dqFront = dq.front();
			dq.pop_front();
			dq.push_front(card.front());
			dq.push_front(dqFront);
			card.pop();
		}

		else {
			dq.push_back(card.front());
			card.pop();
		}
	}

	for (int i = 0; i < num; i++) {
		cout << dq[i] << " ";
	}
}