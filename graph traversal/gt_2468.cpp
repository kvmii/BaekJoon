#include <iostream>

using namespace std;

int ground[101][101];
int visited[101][101];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
int result = 0;
int n;

void dfs(int x, int y, int num) {
	visited[x][y] = 1;

	for (int k = 0; k < 4; k++) {
		int dx = x + X[k];
		int dy = y + Y[k];
		if (visited[dx][dy] != 1 && ground[dx][dy] > num) {
			dfs(dx, dy, num);
		}
	}
}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			// 방문 초기화
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
		}
	}

	for (int i = 0; i < 100; i++) {
		int num = 0;

		clear();

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visited[j][k] != 1 && ground[j][k] > i) {
					num++;
					dfs(j, k, i);
					// 안전지역 개수
				}
			}
		}
		if (result < num)
			result = num;
	}

	cout << result << endl;
	system("PAUSE");
}