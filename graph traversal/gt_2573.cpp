#include <iostream>
#include <queue>
#include <string.h>


int n, m;
int arr[300][300];
bool visited[300][300];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
using namespace std;


void bfs(int x, int y){
	// bfs 사용
	// 빙산이 이어져있는지 확인
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = x + X[k];
			int dy = y + Y[k];

			if (dx < 0 || dx >= n || dy < 0 || dy >= m)
				continue;

			if (arr[dx][dy] != 0 && visited[dx][dy] == false) {
				visited[dx][dy] = true;
				q.push({ dx,dy });
			}
		}
	}
}

void down(int x, int y) {
	// 한단계씩 낮추는 함수
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int dx = x + X[k];
		int dy = y + Y[k];

		if (dx < 0 || dx >= n || dy < 0 || dy >= m)
			continue;

		if (arr[dx][dy] == 0 && visited[dx][dy] == false) {
			// 이것 때문에 1차 실패
			// 순서대로 감소할 경우 먼저 감소한게 0이 되었을 때 다음 것이 하나 더 감소된다
			// 그래서 조건에 방문하지 않았다면을 추가
			arr[x][y]--;
		}
		if (arr[x][y] < 0)
			arr[x][y] = 0;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int year = 0;

	while (1) {
		memset(visited, false, sizeof(visited));
		bool zero = true;
		int score = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					zero = false;
					// 전부 0일 경우
				}
			}
		}

		if (zero == true) {
			// 전부 0이면 두 덩어리로 분리 X
			cout << 0;
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == false && arr[i][j] != 0) {
					bfs(i, j);
					score++;
				}
			}
		}

		memset(visited, false, sizeof(visited));

		if (score >= 2) {
			// 빙산이 두 덩어리 이상이면
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					down(i, j);
					// 감소
				}
			}
		}
		year++;
		// 1년 후
	}

	cout << year;
	return 0;
}