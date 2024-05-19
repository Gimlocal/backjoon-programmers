#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool checkFull(int** arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

// 후보의 개수를 계산하는 함수
pair<int, pair<int, int>> calculateCandidateCount(int** arr) {
    int minCandidates = 10; // 가장 가능성이 낮은 후보의 개수로 초기화
    pair<int, int> cellCoords;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                set<int> candidates;

                // 현재 셀에 들어갈 수 있는 후보들을 candidates에 추가
                for (int num = 1; num <= 9; num++) {
                    bool valid = true;
                    for (int k = 0; k < 9; k++) {
                        if (arr[i][k] == num || arr[k][j] == num || arr[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3] == num) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) candidates.insert(num);
                }

                // 후보의 개수 갱신
                if (candidates.size() < minCandidates) {
                    minCandidates = candidates.size();
                    cellCoords = { i, j };
                }
            }
        }
    }

    return { minCandidates, cellCoords };
}

void sudoku(int**& arr) {
    if (checkFull(arr)) return;

    // 후보의 개수를 계산하고 후보가 가장 적은 셀을 선택
    pair<int, pair<int, int>> candidateInfo = calculateCandidateCount(arr);
    int row = candidateInfo.second.first;
    int col = candidateInfo.second.second;

    // 후보들을 벡터로 저장
    set<int> candidates;
    for (int num = 1; num <= 9; num++) {
        bool valid = true;
        for (int k = 0; k < 9; k++) {
            if (arr[row][k] == num || arr[k][col] == num || arr[(row / 3) * 3 + k / 3][(col / 3) * 3 + k % 3] == num) {
                valid = false;
                break;
            }
        }
        if (valid) candidates.insert(num);
    }

    // 후보들을 시도
    for (int num : candidates) {
        arr[row][col] = num;
        sudoku(arr);
        if (checkFull(arr)) return;
        arr[row][col] = 0; // 백트래킹
    }
}

int main() {
    int** arr = new int* [9];
    for (int i = 0; i < 9; i++) {
        arr[i] = new int[9];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    sudoku(arr);

    // 결과 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // 메모리 해제
    for (int i = 0; i < 9; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
