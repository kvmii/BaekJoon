#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int visited[200001];
int result = 0;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;



int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	sort(vec.begin(), vec.end());
	// 시작시간 순으로 정렬
	pq.push(vec[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= vec[i].first) pq.pop();
		// 제일 먼저 끝나는 것보다 뒤에 시작하면
		// 제일 먼저 끝나는 것 pop
		pq.push(vec[i].second);
		// 끝나는 시간 push
	}
	
	cout << pq.size();
}