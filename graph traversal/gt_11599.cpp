#include <iostream>
#include <string>	
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;
char arr[12][6];
int visited[12][6];
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
int num;
int result = 0;

void change(int x, int y, char str) {
	// .으로 바꾸기
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;
	arr[x][y] = '.';
	num = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];
			if (dx < 0 || dx >= 12 || dy < 0 || dy >= 6) continue;
			if (visited[dx][dy] != 1 && arr[dx][dy] == str) {
				q.push({ dx, dy });
				visited[dx][dy] = 1;
				arr[dx][dy] = '.';
			}
		}
	}
}

int bfs(int x, int y, char str) {
	// 붙어있는 개수
	queue<pair<int, int>> q;
	q.push({ x, y});
	visited[x][y] = 1;
	num = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dx = a + X[k];
			int dy = b + Y[k];
			if (dx < 0 || dx >= 12 || dy < 0 || dy >= 6) continue;
			if (visited[dx][dy] != 1 && arr[dx][dy] == str) {
				q.push({ dx, dy});
				visited[dx][dy] = 1;
				num++;
			}
		}
	}
	if (num >= 4) {
		// 4개 이상이면
		memset(visited, 0, sizeof(visited));
		change(x, y, str);
		return 1;
	}
	return -1;
}

void gravity() {
	// 중력함수
	for (int j = 0; j < 6; j++) {
		for (int i = 10; i >= 0; i--) {
			for (int k = i + 1; k < 12; k++) {
				if (arr[i][j] != '.' && arr[k][j] == '.') {
					if (k == 11 || arr[k + 1][j] != '.') {
						// 끝에 도달했거나 다음이 .이 아니면
						arr[k][j] = arr[i][j];
						arr[i][j] = '.';
						// 바꾸기
					}
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		bool check = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && visited[i][j] != 1) {
					if (bfs(i, j, arr[i][j]) == 1) {
						// 4개 이상 붙어있으면 다 터트리기
						check = true;
					}
				}
			}
		}
		// 중력 발동
		if (check) gravity();

		if (check == false) break;
		// 아무것도 안터졌다면 break
		result++;
		memset(visited, 0, sizeof(visited));
		// 초기화
	}

	cout << result;
}