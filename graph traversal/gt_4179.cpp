#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>

using namespace std;
char map[1001][1001];
int visit[1001][1001];
int n, m;
int X[] = { 1, -1, 0, 0 };
int Y[] = { 0, 0, 1, -1 };
queue<pair<int, int>> f;

void fire() {
	// 불 번지기
	int num = f.size();
	// 불의 개수
	while (num--) {
		int i = f.front().first;
		int j = f.front().second;
		f.pop();
		for (int k = 0; k < 4; k++) {
			int di = i + X[k];
			int dj = j + Y[k];
			if (di < 0 || di >= n || dj < 0 || dj >= m) continue;
			if (map[di][dj] == '.') {
				// 땅이면 불 번지기
				map[di][dj] = 'F';
				f.push({ di,dj });
				// 그 불들을 다시 저장
			}
		}
	}
}

int move(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push({ x, y, 1 });
	visit[x][y] = 1;
	int i = 1;
	while (!q.empty()) {
		int dx = get<0>(q.front());
		int dy = get<1>(q.front());
		int cnt = get<2>(q.front());
		if (cnt == i) {
			// 한번 움직이면 불 붙이기
			fire();
			i++;
		}
		q.pop();
		if (dx == n - 1 || dy == m - 1 || dx == 0 || dy == 0) {
			// 밖으로 나가면
			return cnt;
		}
		for (int k = 0; k < 4; k++) {
			int movex = dx + X[k];
			int movey = dy + Y[k];
			if (movex < 0 || movex >= n || movey < 0 || movey >= m) continue;
			if (map[movex][movey] == '.' && visit[movex][movey] != 1) {
				//방문하지 않았고 길이라면
				q.push({ movex, movey, cnt + 1 });
				visit[movex][movey] = 1;
			}
		}
	}
	return -1;
	// 탈출하지 못하면
}

int main() {
		int startx, starty;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'J') {
					startx = i;
					starty = j;
					// 시작위치 찾기
				}
				if (map[i][j] == 'F') {
					f.push({ i, j });
					// 불위치 저장
				}
			}
		}

		int score = move(startx, starty);
		if (score == -1) cout << "IMPOSSIBLE" << endl;
		else cout << score << endl;
}