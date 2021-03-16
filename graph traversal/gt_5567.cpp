#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<int> vec[501];
int result = 0;
int visited[501];

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visited[x] = 1;
	while (!q.empty()) {
		int dx = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt <= 2 && dx != 1) result++;
		// 模备狼 模备鳖瘤
		// 3何磐绰 模备狼 模备狼 模备
		for (int i = 0; i < vec[dx].size(); i++) {
			int k = vec[dx][i];
			if (visited[k] != 1) {
				q.push({ k, cnt + 1 });
				visited[k] = 1;
			}
		}
	}

}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
		// 辑肺 楷搬
	}

	bfs(1);
	cout << result;
}