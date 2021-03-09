#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;
int n, m, d;
int arr[15][15];
int map[15][15];
int result = 0;
int bow[15];
int visited[15];
int visit[15][15];
int score;

void kill() {
	// 죽이기
	for (int k = 0; k < m; k++) {
		for (int l = 1; l <= d; l++) {
			for (int j = 0; j < m; j++) {
				// 왼쪽부터
				for (int i = n - 1; i >= 0; i--) {
					// 아래부터(가까운 곳)
					if (bow[k] == 1 && visited[k] != 1) {
						// 궁수가 있는 자리고 쏘지 않았다면
						int distance = abs(i - n) + abs(k - j);
						if (distance == l && map[i][j] == 1) {
							// 적이 있다면
							map[i][j] = 0;
							visit[i][j] = 1;
							// 방문 표시
							result++;
							visited[k] = 1;
							break;
						}
						if (distance == l && map[i][j] == 0) {
							// 적이 없지만 방문을 했다면
							if (visit[i][j] == 1) {
								// 똑같은 곳을 쏘고 넘어감
								visited[k] = 1;
								break;
							}
						}
					}
					if (visited[k] == 1) break;
				}
				if (visited[k] == 1) break;
			}
			if (visited[k] == 1) break;
		}
	}
}

void move() {
	// 한칸씩 아래로 움직이기
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			map[i][j] = map[i - 1][j];
		}
		map[0][j] = 0;
	}
}

void copy() {
	// 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = arr[i][j];
		}
	}
}

bool check() {
	// 게임이 끝났는지 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) return false;
		}
	}
	return true;
}

void start(int cnt) {
	if (cnt == 3) {
		// 3개를 배치했다면
		result = 0;
		copy();
		while (1) {
			memset(visited, 0, sizeof(visited));
			memset(visit, 0, sizeof(visit));
			kill();
			// 죽이고
			move();
			// 움직이기
			if (check() == true) break;
			// 게임 끝날때 까지
		}
		score = max(score, result);
		// 최고점수
		return;
	}
	for (int i = 0; i < m; i++) {
		if (bow[i] == 0) {
			bow[i] = 1;
			start(cnt + 1);
			bow[i] = 0;
		}
	}
}

int main() { 
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	start(0);
	cout << score;
}