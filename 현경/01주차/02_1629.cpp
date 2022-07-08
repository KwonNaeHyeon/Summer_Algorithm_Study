#include <iostream>
#include <cmath>
using namespace std;

int div(long long a, long long b, long long c) {

	if (b == 1) {
		return a % c;
	}

	if (b % 2 == 0) {
		long long tmp = div(a, b / 2, c) % c;
		return (tmp * tmp) % c;
	}
	else {
		long long tmp = div(a, (b - 1) / 2, c) % c;
		return  (((tmp * tmp)%c) * a ) % c;
	}
}
int main() {
	long long a, b, c;

	cin >> a >> b >> c;

	long long num = div(a, b, c);
	cout << num << endl;
}
