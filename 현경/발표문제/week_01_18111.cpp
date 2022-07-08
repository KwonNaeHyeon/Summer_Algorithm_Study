#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, b;
vector<vector<int>> arr;

void solve(int& mintime, int& maxheight,int height) {
	int add = 0; // 인벤에서 꺼내서 더함. 1초 걸림
	int remove = 0; // 제거함. 2초 걸림

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = arr[i][j] - height; // 현재 높이를 구해봄.
			if (tmp < 0) { // 더 높은 높이로 만들어야 함.(현재 높이가 음수이므로)
				add -= tmp; // 음수이므로, 빼서 양수를 더하게 만들어줌.
			}
			else { // 양수이면, 더 낮은 높이로 만들어야 함.
				remove += tmp; // 제거해야하므로 remove 개수 추가함.
			}
		}
	}

	if (remove + b >= add) {
		int ttime = 2 * remove + add; // 걸리는 시간 계산. remove는 2초, add는 1초
		if (mintime >= ttime) { // 최소시간, 최대 높이 갱신
			mintime = ttime;
			maxheight = height;
		}
	}
}

int main() {

	cin >> n >> m >> b;
	int high = -1;
	int low = 999;

	for (int i = 0; i < n; i++) {
		vector<int> element(m);
		for (int j = 0; j < m; j++) {
			cin >> element[j];
			low = min(low, element[j]);
			high = max(high, element[j]);
		}
		arr.push_back(element);
	}
	int mintime = 1e9;
	int maxheight = -1;
	for (int i = low; i <= high; i++) {
		solve(mintime, maxheight, i); // 전부 해보기. brute force.
	}

	cout << mintime << " " << maxheight;
}
