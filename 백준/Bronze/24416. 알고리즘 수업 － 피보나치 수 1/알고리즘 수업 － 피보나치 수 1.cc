#include <iostream>
using namespace std;

int fib(int num,int& cnt) {
	if (num == 1 || num == 2) {
		cnt++; return 1;
	}
	else return (fib(num - 1,cnt) + fib(num - 2,cnt));
}

int main() {
	int num; cin >> num;
	int cnt = 0;
	fib(num,cnt);
	cout << cnt << " " << num - 2;
}