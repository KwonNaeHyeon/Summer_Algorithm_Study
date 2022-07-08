#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_sum(vector<int>arr) {
	int sum = 0;
	for (auto iter = arr.begin(); iter != arr.end(); iter++) {
		sum += *iter;
	}
	return sum;
}

int up_limit(vector<int> arr, int m) {
	int sum = get_sum(arr);
	int up_limit = *max_element(arr.begin(),arr.end());

	while (sum > m) {
		up_limit--;

		for (int i = 0; i < arr.size();i++) {
			if (arr[i] > up_limit) {
				arr[i] = up_limit;
			}
		}
		sum = get_sum(arr);
	}
	return up_limit;
}

int main() {
	int n, m;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;

	sort(arr.begin(), arr.end());

	cout << up_limit(arr, m);
}
