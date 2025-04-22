#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string, int> m;
    for (int i = 0;i < friends.size();i++)
    {
        m[friends[i]] = i;
    }
    
    vector<vector<int>> v(friends.size(), vector<int>(friends.size(), 0));
    
    for (int i = 0;i < gifts.size();i++)
    {
        string a = "";
        string b = "";
        string c = "";
        for (int j = 0;j < gifts[i].length();j++)
        {
            if (gifts[i][j] == ' ')
            {
                a = c;
                c = "";
            }
            else
            {
                c += gifts[i][j];
            }
        }
        b = c;
        v[m[a]][m[b]] += 1;
    }
    
    vector<int> give(friends.size());
    vector<int> receive(friends.size());
    vector<int> value(friends.size());
    
    for (int i = 0;i < friends.size();i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int j = 0;j < friends.size();j++)
        {
            sum1 += v[i][j];
            sum2 += v[j][i];
        }
        give[i] = sum1;
        receive[i] = sum2;
    }
    
    for (int i = 0;i < friends.size();i++)
    {
        value[i] = give[i] - receive[i];
    }
    
    vector<int> result(friends.size(), 0);
    
    for (int i = 0;i < friends.size();i++)
    {
        for (int j = 0;j < friends.size();j++)
        {
            if (i > j)
            {
                if (v[i][j] > v[j][i]) result[i]++;
                else if (v[i][j] < v[j][i]) result[j]++;
                else
                {
                    if (value[i] > value[j]) result[i]++;
                    else if (value[i] < value[j]) result[j]++;
                }
            }
        }
    }
    
    int max = 0;
    for (int i = 0;i < result.size();i++)
    {
        if (result[i] > max) max = result[i];
    }
    
    return max;
}