#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//지방의 수 입력받기
	int n;
	cin >> n;

	//배열에 각 지방의 예산 요청 넣기
	vector<int> budget;
	int budget_request;

	for (int i = 0; i < n; i++) {
		cin >> budget_request;
		budget.push_back(budget_request);
	}

	//이진탐색을 위해 원소 정렬하기
	sort(budget.begin(), budget.end());

	// 총 예산 입력받기
	int budget_total;
	cin >> budget_total;

	// 이진탐색으로 상한액 찾기
	int start = 0;
	int end = budget[n - 1];
	int res = 0;
	
	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += min(mid, budget[i]);
		}
		
		if (sum <= budget_total) {
			start = mid + 1;
			res = mid;
		}
		else {
			end = mid - 1;
		}
	}
	
	cout << res;
	return 0;
}
