#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSum(int arr[], int len) {
    int maxsum = arr[0];
    int sum = arr[0];

    for (int i = 1; i < len; i++) {
        sum = max(arr[i], sum + arr[i]);
        maxsum = max(maxsum, sum);
    }

    return maxsum;
}

int main() {
    int len;
    cin >> len;

    int* arr = new int[len];

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    int result = maxSum(arr, len);

    cout << result;
}
