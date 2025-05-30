#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long MaxArea(const vector<int>& v)
{
    long long maxArea = 0;
    stack<int> s;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] > v[i])
        {
            int topIndex = s.top(); 
            s.pop();
            long long height = v[topIndex];
            int width = s.empty() ? i : (i - s.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int topIndex = s.top(); 
        s.pop();
        long long height = v[topIndex];
        int width = s.empty() ? n : (n - s.top() - 1);
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (true)
	{
		int n; cin >> n;
		if (n == 0) break;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		cout << MaxArea(v) << "\n";
	}
}