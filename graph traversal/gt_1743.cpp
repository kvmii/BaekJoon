#include <iostream>
#include <queue>

using namespace std;
int n, m, k;
int arr[101][101];
int visited[101][101];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
int score = 0;
int result = 0;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		score++;

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];
			if (visited[dx][dy] != 1 && arr[dx][dy] == 1) {
				q.push({ dx, dy });
				visited[dx][dy] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				score = 0;
				bfs(i, j);
				result = max(result, score);
			}
		}
	}

	cout << result;
}