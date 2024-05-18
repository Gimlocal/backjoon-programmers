#include <iostream>
#include <vector>
#include <set>
using namespace std;

int operate(vector<int> v,int element, int*& num, int num1, int num2) {
	int temp = num[num2];

	if (element == 0) {
		num[num2] = num[num1] + num[num2];
	}
	else if (element == 1) {
		num[num2] = num[num1] - num[num2];
	}
	else if (element == 2) {
		num[num2] = num[num1] * num[num2];
	}
	else if (element == 3) {
		if (num[num1] < 0) {
			if (-num[num1] / num[num2] == 0) num[num2] = 0;
			else num[num2] = -(-num[num1] / num[num2]);
		}
		else num[num2] = num[num1] / num[num2];
	}

	return temp;
}


void operates(set<int>& s,vector<int> v,int* num,int numNum,int num1,int num2) {
	if (num2 == numNum) {
		s.insert(num[num2 - 1]);
		return;
	}

	for (int i = 0; i < v.size();i++) {
		if (v[i] != 4) {
			int temp2 = operate(v, v[i], num, num1, num2);
			int temp = v[i];
			v[i] = 4;
			operates(s, v, num, numNum, num1 + 1, num2 + 1);
			num[num2] = temp2;
			v[i] = temp;
		}
	}

	return;
}

int main() {
	int numNum; cin >> numNum;
	int* num = new int[numNum];
	for (int i = 0; i < numNum; i++) {
		cin >> num[i];
	}

	vector<int> v;
	for (int i = 0; i < 4; i++) {
		int num; cin >> num;
		if (num != 0) {
			for (int j = 0; j < num; j++) {
				if (i == 0) v.push_back(0);
				else if (i == 1) v.push_back(1);
				else if (i == 2) v.push_back(2);
				else v.push_back(3);
			}
		}
	}

	set<int> s;
	operates(s, v, num, numNum, 0, 1);

	cout << *s.rbegin() << "\n" << *s.begin();
}