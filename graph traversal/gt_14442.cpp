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
	// x��ǥ, y��ǥ, �̵� �Ÿ�, �� �μ� Ƚ��
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
			// ���� ���� ������ ���� �ּ� �Ÿ�
			return cnt;

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			// ������ �����
			if (visited[dx][dy][wall])
				continue;
			// �̹� �湮 �ߴٸ�
			if (map[dx][dy] == '0') {
				visited[dx][dy][wall] = 1;
				q.push({ dx, dy, cnt + 1, wall });
			}

			if (map[dx][dy] == '1' && wall > 0) {
				// ���̰� ���� �μ� �� �ִٸ�
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