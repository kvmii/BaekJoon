#include <iostream>
#include <queue>

using namespace std;
int n, m;
int arr[501][501];
int X[] = { 1, -1, 0 ,0 };
int Y[] = { 0, 0, 1, -1 };
int visited[501][501];
int score = 0;
int num = 0, result = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		score++;
		// ≥–¿Ã
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];
			if (visited[dx][dy] != 1 && arr[dx][dy] == 1) {
				q.push({ dx, dy });
				visited[dx][dy] = 1;
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] != 1 && arr[i][j] == 1) {
				score = 0;
				bfs(i, j);
				num++;
				// ∞≥ºˆ ∆ƒæ««œ±‚
				result = max(score, result);
				// ≥–¿Ã ¡ﬂ ¡¶¿œ ≥–¿∫ ∞Õ √£±‚
			}
		}
	}


	cout << num << endl;
	cout << result;
}