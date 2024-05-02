#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int len; cin >> len;
    vector<int> A;
    for (int i = 0; i < len; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    vector<int> result = longest_increasing_subsequence(A);

    cout << result.size();
}
