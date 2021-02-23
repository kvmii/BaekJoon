#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1001
using namespace std;

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, -1, 1 };
char map[MAX][MAX];
int visited[MAX][MAX][2];
int n, m;


int maze() {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());

		q.pop();

		if (x == n - 1 && y == m - 1)
			return visited[x][y][cnt];

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
				if (visited[dx][dy][cnt])
					continue;

				if (map[dx][dy] == '0') {
					// 벽이 없다면
					visited[dx][dy][cnt] = visited[x][y][cnt] + 1;
					q.push(make_tuple(dx, dy, cnt));
				}

				if (map[dx][dy] == '1' && cnt == 0) {
					// 벽이 있고 아직 부시지 않았다면
					visited[dx][dy][cnt + 1] = visited[x][y][cnt] + 1;
					// 벽을 하나 부수기
					q.push(make_tuple(dx, dy, cnt + 1));
				}
			}
		}
	}

	return -1;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	} 

	cout << maze();
	// 처음에 연구소 문제와 비슷하게 풀었으나 시간초과가 발생
	// bfs함수 안에서 해결
}