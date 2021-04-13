#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int n, m;
int arr[101][101];
int visited[101][101][4];
int X[] = { 0, 0, 1, -1 };
int Y[] = { 1, -1, 0, 0 };
int startX, startY, startA, endX, endY, endA;
int result = 987654321;


struct three {
	int x, y, angle;
};

int rotate(int x, int y) {
	// 동서남북 회전
	if (x == y) return 0;
	if (x == 0 && y == 1) return 2;
	if (x == 1 && y == 0) return 2;
	if (x == 2 && y == 3) return 2;
	if (x == 3 && y == 2) return 2;
	return 1;

}

void bfs(int x, int y, int angle) {
	queue<three> q;
	visited[x][y][angle] = 0;
	q.push({ x, y, angle });
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int angle = q.front().angle;
		q.pop();

		if (x == endX - 1 && y == endY - 1) {
			// 도착했다면 작은 값 찾기
			result = min(result, visited[x][y][angle] + rotate(angle, endA - 1));
		}

		for (int k = 0; k < 4; k++) {
			int cnt = visited[x][y][angle] + rotate(angle, k) + 1;
			// 현재까지 이동 + 회전 + 1번 이동

			for (int i = 1; i <= 3; i++) {
				int dx = x + X[k] * i;
				int dy = y + Y[k] * i;

				if (dx < 0 || dy < 0 || dx >= n || dy >= m || arr[dx][dy] == 1) break;
				// 벽에 부딪히거나 없을 경우

				if (visited[dx][dy][k] == 0 || cnt < visited[dx][dy][k]) {
					// 최솟값이면
					q.push({ dx, dy, k});
					visited[dx][dy][k] = cnt;
				}

			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> startX >> startY >> startA;
	cin >> endX >> endY >> endA;

	bfs(startX - 1, startY - 1, startA - 1);
	cout << result;
}