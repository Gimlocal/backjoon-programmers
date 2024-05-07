#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(string a, string b) {
    return a + b < b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    string ans = "";
    vector<string> nums(numbers.size());

    for (int i = 0; i < numbers.size(); i++) {
        nums[i] = to_string(numbers[i]);
    }

    sort(nums.begin(),nums.end(),sorting);
    
    for (int i = 0;i < nums.size();i++) {
        ans = nums[i] + ans;
    }
    
    int cnt = 0; //앞자리 0개수 확인
    for (int i = 0;i < ans.size() - 1;i++) {
        if (ans[i] == '0') cnt++;
        else break;
    }
    
    for (int i = cnt;i < ans.size();i++) {
        answer += ans[i];
    }
    
    return answer;
}