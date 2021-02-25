#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
vector<pair<int, int>> vec;
vector<int> bag;
long long result = 0;
priority_queue<int> pq;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		bag.push_back(a);
	}

	sort(vec.begin(), vec.end());
	sort(bag.begin(), bag.end());

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		while (cnt < n && vec[cnt].first <= bag[i]) {
			// 보석이 남았고 가방에 들어갈 수 있으면
			pq.push(vec[cnt].second);
			// pq에 들어갈 수 있는 보석이 들어가고 높은 순으로 정렬되기 때문에 제일 위에서 k개를 고르면 된다
			cnt++;
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	// greedy와 우선순위 큐
	cout << result;
}