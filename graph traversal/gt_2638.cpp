#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
int arr[100][100];
int n, m;
int visited[100][100];
int cheese[100][100];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };


bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

void air() {
	// 바깥공기 판별
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (visited[x][y]) continue;
		visited[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
			if (arr[dx][dy] == 1) {
				// 바깥공기와 치즈가 붙어있다면 개수세기
				cheese[dx][dy] += 1;
			}
			else {
				// 그렇지 않으면 또 다른 바깥공기
				q.push({ dx, dy });
			}
		}
	}
}

void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cheese[i][j] >= 2) {
				// 바깥공기 2개이상이면
				arr[i][j] = 0;
				// 녹이기
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

	int result = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		memset(cheese, 0, sizeof(cheese));
		air();
		melt();
		result++;
		if (check() == true) break;
	}

	cout << result;
}