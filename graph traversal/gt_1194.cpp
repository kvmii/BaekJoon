#include <iostream>
#include <queue>

using namespace std;
char map[51][51];
bool visited[51][51][1 << 6];
// 알파벳 6개 비트마스크 활용
int n, m;
int X[] = { 0, 0, 1, -1 };
int Y[] = { 1, -1, 0, 0 };

struct quad {
	int x, y, cnt, key;
	// x좌표, y좌표, 이동거리, 비트마스크
};

int bfs(int x, int y, int cnt, int key) {
	queue<quad> q;
	q.push({ x, y, cnt, key });
	visited[x][y][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();

		if (map[x][y] == '1') {
			// 도착 지점에 도착했다면
			return cnt;
		}

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			// 범위를 벗어났다면

			if (visited[dx][dy][key] == false) {
				if (map[dx][dy] == '#') continue;
				// 벽에 막혔을 경우
				else if (map[dx][dy] >= 'a' && map[dx][dy] <= 'f') {
					// 열쇠를 얻었을 때
					int bit = map[dx][dy] - 'a';
					int nkey = key | 1 << bit; 
					q.push({ dx, dy, cnt + 1, nkey });
					visited[dx][dy][nkey] = true;
				}
				else if (map[dx][dy] >= 'A' && map[dx][dy] <= 'F') {
					// 문을 만났을 때
					int bit = map[dx][dy] - 'A';
					int nkey = key & (1 << bit);
					if ((1 << bit) == nkey) {
						// 주어진 키로 문을 열 수 있으면
						q.push({ dx, dy, cnt + 1, key });
						visited[dx][dy][key] = true;
					}
				}
				else {
					q.push({ dx, dy, cnt + 1, key });
					visited[dx][dy][key] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				// 시작점 찾기
				a = i;
				b = j;
			}
		}
	}

	cout << bfs(a, b, 0, 0);
}