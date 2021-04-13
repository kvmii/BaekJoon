#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1001
using namespace std;

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, -1, 1 };
char map[MAX][MAX];
int visited[MAX][MAX][10];
int n, m, k;

struct quad {
	int x, y, cnt, wall;
	// x좌표, y좌표, 이동 거리, 벽 부순 횟수
};

int maze() {
	queue<quad> q;
	q.push({ 0, 0, 1, k });
	visited[0][0][k] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int wall = q.front().wall;

		q.pop();

		if (x == n - 1 && y == m - 1)
			// 제일 먼저 도착한 것이 최소 거리
			return cnt;

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			// 범위를 벗어나면
			if (visited[dx][dy][wall])
				continue;
			// 이미 방문 했다면
			if (map[dx][dy] == '0') {
				visited[dx][dy][wall] = 1;
				q.push({ dx, dy, cnt + 1, wall });
			}

			if (map[dx][dy] == '1' && wall > 0) {
				// 벽이고 벽을 부술 수 있다면
				visited[dx][dy][wall] = 1;
				q.push({ dx, dy, cnt + 1, wall - 1 });
			}
		}
	}

	return -1;
}


int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout << maze();
}