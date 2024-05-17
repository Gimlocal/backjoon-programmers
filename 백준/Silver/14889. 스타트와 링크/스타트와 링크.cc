#include <iostream>
#include <set>
using namespace std;

void checkDiff(set<int>& s,int** arr,bool* arr2,int perNum,int num,int num2) {
	if (num2 > perNum - 1) return;
	if (num == perNum/2) {
		int result1 = 0;int result2 = 0;
		for (int i = 0; i < perNum; i++) {
			for (int j = 0; j < perNum; j++) {
				if (arr2[i] && arr2[j]) result1 += arr[i][j];
			}
		}

		for (int i = 0; i < perNum; i++) {
			for (int j = 0; j < perNum; j++) {
				if (!arr2[i] && !arr2[j]) result2 += arr[i][j];
			}
		}

		s.insert(abs(result1 - result2));
		return;
	}

	for (int i = num2; i < perNum; i++) {
		if (!arr2[i]) {
			arr2[i] = true;
			checkDiff(s, arr, arr2, perNum, num+1,i+1);
			arr2[i] = false;
		}
	}
}



int main() {
	int perNum; cin >> perNum;
	int** arr = new int* [perNum];
	for (int i = 0; i < perNum; i++) {
		arr[i] = new int[perNum];
	}

	for (int i = 0; i < perNum; i++) {
		for (int j = 0; j < perNum; j++) {
			cin >> arr[i][j];
		}
	}

	bool* arr2 = new bool[perNum]();

	set<int> s;
	checkDiff(s, arr, arr2, perNum,0,0);

	cout << *s.begin();
}