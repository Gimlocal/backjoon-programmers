#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string LCS(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // LCS의 길이를 저장하는 dp 테이블
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // LCS를 구하기 위한 dp 테이블 채우기
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // LCS의 길이를 이용하여 LCS 문자열 찾기
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;

    cout << LCS(s1, s2).size();
}
