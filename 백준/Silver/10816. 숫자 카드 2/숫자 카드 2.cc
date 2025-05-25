#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int num, intnum, testnum, testintnum;
	unordered_map<int, int> map1;
	unordered_map<int, int> map2;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> intnum;
		map1.insert(make_pair(i, intnum));
	}

	cin >> testnum;
	int* arr = new int[testnum];

	for (int i = 0; i < testnum; i++) {
		cin >> testintnum;
		map2.insert(make_pair(testintnum,0));
		arr[i] = testintnum;
	}

	unordered_map<int, int>::iterator iter1;
	unordered_map<int, int>::iterator iter2;

	for (int i = 0; i < num; i++) {
		iter1 = map1.find(i);
		if (map2.count(iter1->second)) {
			iter2 = map2.find(iter1->second);
			iter2->second++;
		}
	}

	unordered_map<int, int>::iterator iter3;

	for (int i = 0; i < testnum; i++) {
		iter3 = map2.find(arr[i]);
		cout << iter3->second << " ";
	}

}