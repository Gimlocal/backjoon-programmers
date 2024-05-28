#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> vec) {
	if (vec.empty())
		return;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void check(int arr[], bool arr2[], int num1, int num2, int zero, vector<int> vec,int j = 0) {
	if (zero == num2) {
		print(vec);
		return;
	}

	for (int i = 0; i < num1; i++) {
		if (!arr2[i] && i >= j) {
			if (zero == num2 - 1) { arr2[i] = true; }
			vec.push_back(arr[i]);
			check(arr, arr2, num1, num2, zero + 1, vec,i);
			vec.pop_back();
			arr2[i] = false;
		}
	}
}


int main() {
	int num1, num2;
	cin >> num1 >> num2;

	int* arr = new int[num1];
	bool* arr2 = new bool[num1];
	for (int i = 0; i < num1; i++) {
		arr[i] = i + 1;
		arr2[i] = false;
	}

	vector<int> vec;
	check(arr, arr2, num1, num2, 0, vec);

	delete[] arr;
	delete[] arr2;
}
