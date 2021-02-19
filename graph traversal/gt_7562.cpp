#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int m, n, T;
int visited[301][301];
int X[] = { 2, 2, -2, -2,1, -1, 1, -1 };
int Y[] = { 1, -1, 1, -1, 2, 2, -2, -2 };

int bfs(int x, int y) {
	// bfs 활용
	queue<tuple<int, int, int>> q;
	visited[x][y] = 1;
	q.push(make_tuple(x, y, 0));
	// x, y는 좌표 z는 몇번 움직였는지

	while (!q.empty()) {

		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		if (a == m && b == n)
			return c;
		// 도착 했으면 횟수를 반환

		for (int k = 0; k < 8; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];

			if (dx < 0 || dx >= T || dy < 0 || dy >= T)
				continue;
			if (visited[dx][dy] != 1) {
				q.push(make_tuple(dx, dy, c + 1));
				visited[dx][dy] = 1;
			}
		}
	}
}

void clear() {
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {
			visited[i][j] = 0;
			// 초기화 함수
		}
	}
}

int main() {
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> T;
		int a, b;
		cin >> a >> b;
		cin >> m >> n;
		int result = bfs(a, b);
		cout << result << endl;
		clear();
	}
}