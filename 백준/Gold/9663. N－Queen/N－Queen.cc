#include <iostream>
using namespace std;

bool isSafe(bool** arr, int row, int col, int N) {
    for (int i = 0; i < row; ++i) {
        if (!arr[i][col]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (!arr[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (!arr[i][j]) {
            return false;
        }
    }
    return true;
}

void Queen(bool** arr, int row, int N, int& count) {
    if (row == N) {
        count++;
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(arr, row, col, N)) {
            arr[row][col] = false;
            Queen(arr, row + 1, N, count);
            arr[row][col] = true;
        }
    }
}

int main() {
    int N; cin >> N;
    bool** arr = new bool* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new bool[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = true;
        }
    }

    int count = 0;
    Queen(arr, 0, N, count);

    cout << count;

    return 0;
}
