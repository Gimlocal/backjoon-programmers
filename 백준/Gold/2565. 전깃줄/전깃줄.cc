#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorting(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

vector<int> longest_increasing_subsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> lis(n, 1);
    vector<int> prev_index(n, -1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev_index[i] = j;
            }
        }
    }

    vector<int> result;
    int max_index = max_element(lis.begin(), lis.end()) - lis.begin();
    result.push_back(arr[max_index]);

    while (prev_index[max_index] != -1) {
        max_index = prev_index[max_index];
        result.push_back(arr[max_index]);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
	int num; cin >> num;
	vector<vector<int>> v;
	vector<int> dp;

	for (int i = 0; i < num; i++) {
		int a, b; cin >> a; cin >> b;
		vector<int> vec = { a,b };
		v.push_back(vec);
	}

	sort(v.begin(), v.end(), sorting);

	for (int i = 0; i < v.size(); i++) {
		dp.push_back(v[i][1]);
	}

    vector<int> result = longest_increasing_subsequence(dp);

    cout << dp.size() - result.size();
}