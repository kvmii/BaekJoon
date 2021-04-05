#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, p, l;
int result = 0;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> Q;
	// 마일리지가 적은 순으로 정렬
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		if (p < l) {
			// 자리가 비어있으면
			for (int j = 0; j < p; j++) {
				int a;
				cin >> a;
			}
			Q.push(1);
			// 최소단위인 1을 넣기
		}
		else {
			vector<int> vec;
			for (int j = 0; j < p; j++) {
				int a;
				cin >> a;
				vec.push_back(a);
			}
			sort(vec.begin(), vec.end(), greater<int>());
			// 큰 순서대로 정렬
			Q.push(vec[l - 1]);
			// l번째로 큰 것과 같은 마일리지를 내면 성준이가 올라감
		}
	}

	while (!Q.empty()) {
		if (m - Q.top() >= 0) {
			// 작은 것부터 하나씩 신청
			m -= Q.top();
			Q.pop();
			result++;
		}
		else break;
	}

	cout << result;
}