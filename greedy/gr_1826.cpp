#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> vec;
int l, p;
int result = 0;

int main() {
	priority_queue<int> pq;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
	// 정렬해주기
	cin >> l >> p;

	int i = 0;
	while (1) {
		if (p >= l) break;
		// 도착 했으면

		while (i < vec.size() && p >= vec[i].first) {
			// 지금 연료로 갈 수 있는 곳까지
			pq.push(vec[i].second);
			// 우선순위큐에 넣어주기
			i++;
		}

		if (pq.empty()) break;
		// 다 돌아봤다면

		p += pq.top();
		pq.pop();
		// 갈 수 있는 곳중에 연료를 젤 많이 채우는 곳에서 채우기
		result++;

	}

	if (l > p) cout << -1;
	// 도착하지 못했다면
	else cout << result;
}