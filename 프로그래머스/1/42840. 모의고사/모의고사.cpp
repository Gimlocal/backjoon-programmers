#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int len = answers.size();
    vector<int> people(len,0);
    int num1 = 0;int num2 = 0;int num3 = 0;
    
    for (int i = 0;i < len;i++) { //1번
        people[i] = i%5+1;
    }
    for (int i = 0;i < len;i++) {
        if (people[i] == answers[i]) num1++;
    }
    
    for (int i = 0;i < len;i++) { //2번
        if (i%2 == 0) people[i] = 2;
        else {
            if (i%8 == 1) people[i] = 1;
            else if (i%8 == 3) people[i] = 3;
            else if (i%8 == 5) people[i] = 4;
            else if (i%8 == 7) people[i] = 5;
        }
    }
    for (int i = 0;i < len;i++) {
        if (people[i] == answers[i]) num2++;
    }
    
    for (int i = 0;i < len;i++) {
        if (i%10 == 0 || i%10 == 1)  people[i] = 3;
        else if (i%10 == 2 || i%10 == 3) people[i] = 1;
        else if (i%10 == 4 || i%10 == 5) people[i] = 2;
        else if (i%10 == 6 || i%10 == 7) people[i] = 4;
        else people[i] = 5;
    }
    for (int i = 0;i < len;i++) { //3번
        if (people[i] == answers[i]) num3++;
    }
    
    vector<int> answer;
    int maxnum = max(num1,max(num2,num3));
    
    if (num1 == maxnum) answer.push_back(1);
    if (num2 == maxnum) answer.push_back(2);
    if (num3 == maxnum) answer.push_back(3);
    
    return answer;
}