#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> vec[101];
int visited[101][101];
int result[101];
int n, m;
int minm = 98765;

void bfs(int x) {
	// bfs활용
	queue<pair<int, int>> q;
	q.push({x, 1});
	while (!q.empty()) {
		int cnt = q.front().first;
		int num = q.front().second;
		// 이동 수
		q.pop();
		for (int i = 0; i < vec[cnt].size(); i++) {
			int nxt = vec[cnt][i];
			if (visited[x][nxt] != 1 && x != nxt) {
				// 연결이 되어있지 않으면
				visited[x][nxt] = 1;
				// x와 nxt가 연결 되었다
				result[x] += num;
				q.push({nxt, num + 1});
				// 거리 증가
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	for (int i = 1; i <= n; i++) {
		if (minm > result[i]) minm = result[i];
		// 제일 작은 수 검출
	}

	for (int i = 1; i <= n; i++) {
		if (result[i] == minm) {
			// 제일 작은 수와 같다면
			cout << i;
			return 0;
		}
	}
}