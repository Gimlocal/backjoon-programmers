#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool prime(int num) {
    if (num == 1) return false;
    int checkNum = num;
    int check = 2;
    while (check < checkNum) {
        if (checkNum % check == 0) return false;
        check++;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.length();
    vector<int> v(len, 0);
    map<int,int> m;
    map<int, int> mCheck;

    for (int i = 0; i < len; i++) {
        v[i] = (int)numbers[i] - 48;
        m[(int)numbers[i]- 48]++;
    }

    sort(v.begin(), v.end());

    int max = 0;
    for (int i = 0; i < len; i++) {
        max += v[i] * (int)pow(10, i);
    }

    while (max > 1) {
        int num = max;
        int flag = 1;
        mCheck = m;
        while (num > 0) {
            int digit = num % 10;
            if (mCheck[digit] == 0) {
                flag = 0;
                break;
            }
            else mCheck[digit]--;
            num /= 10;
        }
        if (flag == 1 && prime(max)) answer++;
        max--;
    }

    return answer;
}