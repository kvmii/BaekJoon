#include <iostream>

using namespace std;
char arr[10001][501];
int R, C;
int X[] = { -1, 0, 1};
int Y[] = { 1, 1, 1};
int visited[10001][501];
bool check;
int result = 0;

void dfs(int x, int y) {
	// dfs를 활용한 이동
	visited[x][y] = 1;
	if (y == C - 1) {
		// 도달했다면
		result++;
		check = true;
		return;
	}

	for (int k = 0; k < 3; k++) {
		// 위 대각선, 오른쪽, 아래 대각선 순서로 방문
		int dx = x + X[k];
		int dy = y + Y[k];

		if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
		if (arr[dx][dy] == '.' && visited[dx][dy] != 1) {
			dfs(dx, dy);
			if (check) break;
			// 이미 도달 했다면 끝내기
		}
	}
}


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		check = false;
		dfs(i, 0);
	}

	cout << result;
}