#include <iostream>
#include <vector>

using namespace std;

void padovan(vector<long long>& v,int num) {
	v[0] = 1; v[1] = 1; v[2] = 1; v[3] = 2; v[4] = 2;
	for (int i = 5; i < num; i++) {
		v[i] = v[i - 1] + v[i - 5];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int casenum; cin >> casenum;
	for (int i = 0; i < casenum; i++) {
		int num; cin >> num;
		vector<long long> v(101, 0);
		padovan(v,num);
		cout << v[num-1] << "\n";
	}
}