#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> arr;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		// a 시작시간 b 종료시간
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}

	sort(arr.begin(), arr.end());
	// 종료 시간 기준으로 정렬하기

	int result = 0;
	int end = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].second >= end) {
			// 시작시간이 종료시간 이후면
			end = arr[i].first;
			result++;
		}
	}

	cout << result << endl;
}