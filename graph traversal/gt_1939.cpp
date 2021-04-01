#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
int visited[100001];
typedef long long ll;
vector<pair<int, int>> vec[100001];
int n, m;
int start, finish;

bool bfs(int weight) {
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cnt = q.front();
		q.pop();
		if (cnt == finish) return true;
		for (int i = 0; i < vec[cnt].size(); i++) {
			int dx = vec[cnt][i].first;
			int dy = vec[cnt][i].second;
			if (visited[dx] != 1 && weight <= dy) {
				visited[dx] = 1;
				q.push(dx);
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	int low = 0;
	int high = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
		if (high < c) high = c;
	}
	cin >> start >> finish;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		// 무게로 이분탐색

		memset(visited, 0, sizeof(visited));
		if (bfs(mid)) low = mid + 1;
		else high = mid - 1;
	}

	cout << high;
}