#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
char board[21][21];
int visited[26];
int result = 0;
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };

void dfs(int x, int y, int cnt) {
	// 아스키 코드 활용. 알파벳 값 - 'A'
	if (visited[board[x][y] - 'A'] == 1)
		return;
	
	result = max(result, cnt);
	visited[board[x][y] - 'A'] = 1;

	for (int k = 0; k < 4; k++) {
		int dx = x + X[k];
		int dy = y + Y[k];

		if (dx < 0 || dx >= R || dy < 0 || dy >= C)
			continue;

		dfs(dx, dy, cnt + 1);
	}

	// 초기화
	visited[board[x][y] - 'A'] = 0;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	dfs(0, 0, 1);

	cout << result << endl;
}