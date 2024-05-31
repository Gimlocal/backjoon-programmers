#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> check1(N, vector<int>(M));
    vector<vector<int>> check2(N, vector<int>(M));
    vector<string> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2 == 0) {
                check1[i][j] = (v[i][j] != 'B');
                check2[i][j] = (v[i][j] != 'W');
            }
            else {
                check1[i][j] = (v[i][j] != 'W');
                check2[i][j] = (v[i][j] != 'B');
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            check1[i][j] += check1[i][j - 1];
            check2[i][j] += check2[i][j - 1];
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 1; i < N; i++) {
            check1[i][j] += check1[i - 1][j];
            check2[i][j] += check2[i - 1][j];
        }
    }

    int ans = K * K;

    for (int i = K - 1; i < N; i++) {
        for (int j = K - 1; j < M; j++) {
            int total1 = check1[i][j];
            int total2 = check2[i][j];

            if (i >= K) {
                total1 -= check1[i - K][j];
                total2 -= check2[i - K][j];
            }

            if (j >= K) {
                total1 -= check1[i][j - K];
                total2 -= check2[i][j - K];
            }

            if (i >= K && j >= K) {
                total1 += check1[i - K][j - K];
                total2 += check2[i - K][j - K];
            }

            ans = min(min(total1,total2),ans);
        }
    }

    cout << ans;
}
