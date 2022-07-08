#include <iostream>
#include <vector>
using namespace std;
vector <long long > cnt_0(41); // n+1 크기의 배열
vector<long long> cnt_1(41);

void fibo(int n) {
	if (n == 0) {
		cout << cnt_0[n] << " " << cnt_1[n] << endl;
		return;
	}
	if (n == 1) {
		cout << cnt_0[n] << " " << cnt_1[n] << endl;
		return;
	}

	for (int i = 2; i < n + 1; i++) {
		cnt_0[i] = cnt_0[i - 1] + cnt_0[i - 2];
		cnt_1[i] = cnt_1[i - 1] + cnt_1[i - 2];
	}

	cout << cnt_0[n] << " " << cnt_1[n] << endl;
}

int main() {
	int t;
	cin >> t;
	cnt_0[0] = 1;
	cnt_1[0] = 0;

	cnt_0[1] = 0;
	cnt_1[1] = 1;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		fibo(n);
	}
}
