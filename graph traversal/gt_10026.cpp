#include <iostream>

using namespace std;

int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
char arr[101][101];
int visited[101][101];
int n, num1 = 0, num2 = 0;

void dfs(int x, int y, char z) {
	visited[x][y] = 1;
	// dfs 활용

	for (int k = 0; k < 4; k++) {
		int dx = x + X[k];
		int dy = y + Y[k];

		if (dx < 0 || dx >= n || dy < 0 || dy >= n)
			continue;

		if (arr[dx][dy] == z && visited[dx][dy] != 1) {
			dfs(dx, dy, z);
		}
	}
}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R' && visited[i][j] != 1) {
				dfs(i, j, 'R');
				num1++;
			}
			if (arr[i][j] == 'B' && visited[i][j] != 1) {
				dfs(i, j, 'B');
				num1++;
			}
			if (arr[i][j] == 'G' && visited[i][j] != 1) {
				dfs(i, j, 'G');
				num1++;
			}
		}
	}

	clear();
	// 초기화

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R')
				arr[i][j] = 'G';
			// R을 G로 변환
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G' && visited[i][j] != 1) {
				dfs(i, j, 'G');
				num2++;
			}
			if (arr[i][j] == 'B' && visited[i][j] != 1) {
				dfs(i, j, 'B');
				num2++;
			}
		}
	}

	cout << num1 << " " << num2 << endl;
}