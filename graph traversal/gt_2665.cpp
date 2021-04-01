#include <iostream>
#include <queue>

using namespace std;
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
int visited[51][51];
char arr[51][51];
int n;

struct three {
	int x, y;
	int cnt;
};

struct comp {
	bool operator()(three a, three b) {
		return a.cnt > b.cnt;
	}
};

void bfs(int a, int b, int c) {
	priority_queue < three, vector<three>, comp> pq;
	// 우선순위 큐
	// 가중치가 작은 것 부터
	pq.push({ a, b, c });
	visited[a][b] = 1;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		pq.pop();

		if (x == n - 1 && y == n - 1) {
			// 제일 먼저 도착한 것이 제일 작다
			cout << cnt;
			return;
		}

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (visited[dx][dy] == 1) continue;
			visited[dx][dy] = 1;

			if (arr[dx][dy] == '0') {
				// 검은색이면 가중치 추가
				pq.push({ dx, dy, cnt + 1 });
			}
			else {
				pq.push({ dx, dy, cnt });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	bfs(0, 0, 0);
}