#include <iostream>

using namespace std;

int x[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int y[] = { 0, 0, -1, 1, 1, -1, -1, 1 };
int visited[50][50];
int land[50][50];
int n, m, result;

void dfs(int a, int b) {
	visited[a][b] = 1;

	for (int k = 0; k < 8; k++) {
		int dx = a + x[k];
		int dy = b + y[k];
		// 상하좌우 대각선 전부 방문
		if(dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;

		if (land[dx][dy] == 1 && visited[dx][dy] != 1) {
			dfs(dx, dy);
		}
	}
}

int main() {
	while (1) {
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;
		// 0 0을 입력하면 끝
		result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				land[i][j] = 0;
				visited[i][j] = 0;
				// 초기화
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> land[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (land[i][j] == 1 && visited[i][j] != 1) {
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << endl;
		// 여러가지 결과를 출력할 때는 항상 endl
	}
}